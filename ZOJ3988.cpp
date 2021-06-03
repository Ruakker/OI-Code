/*
	Author: Ruakker
	Date: 2021-05-27 15:59:56
	LastEditTime: 2021-05-27 16:28:54
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO {
	static const int BUFSIZE = (1 << 20) + 1;
	static char Ibuf[BUFSIZE], *I1 = Ibuf, *I2 = Ibuf, Obuf[BUFSIZE], *O1 = Obuf, *O2 = O1 + BUFSIZE - 1;
	static int ST[55], Top;
	inline void flush() { fwrite(Obuf, 1, O1 - Obuf, stdout), O1 = Obuf; }
	struct flusher {
		~flusher() { flush(); }
	} IO;
	inline char getch() { return I1 == I2 && (I2 = (I1 = Ibuf) + fread(Ibuf, 1, BUFSIZE, stdin), I1 == I2) ? EOF : *I1++; }
	inline void putch(char Ch) { *O1++ = Ch, (O1 == O2) ? flush() : void(); }
	inline int getstr(char* S) {
		char Ch = getch();
		int cnt = 0;
		for (; !isgraph(Ch); Ch = getch())
			;
		for (; isgraph(Ch); Ch = getch())
			S[cnt++] = Ch;
		S[cnt] = 0;
		return cnt;
	}
	inline void putstr(const char* S) {
		int Len = strlen(S);
		for (int i = 0; i < Len; ++i)
			putch(S[i]);
	}
	template <typename Var>
	inline Var read() {
		register Var Res = 0, W = 1;
		register char Ch = getch();
		for (; Ch < '0' || Ch > '9'; Ch = getch())
			if (Ch == '-') W = -1;
		for (; Ch <= '9' && Ch >= '0'; Ch = getch())
			Res = (Res << 3) + (Res << 1) + (Ch ^ 48);
		return Res * W;
	}
	inline double readDB() {
		register double ResB = 0, Cnt = 1;
		register char Ch = getch();
		register int ResA = 0, W = 1;
		if (Ch != '.') {
			for (; Ch < '0' || Ch > '9'; Ch = getch())
				if (Ch == '-') W = -1;
			for (; Ch <= '9' && Ch >= '0'; Ch = getch())
				ResA = (ResA << 3) + (ResA << 1) + (Ch ^ 48);
			if (Ch != '.') return ResA * W;
		}
		Ch = getch();
		for (; Ch <= '9' && Ch >= '0'; Ch = getch())
			ResB += (Ch ^ 48) * (Cnt *= 0.1);
		return (ResA + ResB) * W;
	}
	template <typename Var>
	inline void write(register Var Num, const char Ch = '\0') {
		if (!Num) putch('0');
		if (Num < 0) putch('-'), Num = -Num;
		for (; Num; ST[++Top] = Num % 10 + '0', Num /= 10)
			;
		for (; Top; putch(ST[Top--]))
			;
		if (Ch != '\0') putch(Ch);
	}
} // namespace FastIO
using namespace FastIO;
using std::cerr;
using std::endl;
const int N = 3e3 + 5, M = 5e6 + 5;
std::vector<int> primes;
std::bitset<M> isprime;
void init() {
	isprime.reset();
	for (int i = 2; i <= M; i++) {
		if (!isprime[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] <= M; j++) {
			isprime[i * primes[j]] = 1;
			if (!(i % primes[j])) break;
		}
	}
	isprime.flip();
	isprime[0] = isprime[1] = 0;
	// for (int i = 0; i <= 100; ++i)
	// 	cerr << isprime[i] << endl;
}
int n, k, a[N], match[N], ans;
std::vector<int> e[N];
std::bitset<N> vis;
inline void adde(int x, int y) {
	e[x].push_back(y);
}
bool dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		if (!match[v] || dfs(match[v])) {
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	return 0;
}
signed main() {
	init();
	for (int T = read<int>(); T--;) {
		memset(a, 0, sizeof a);
		memset(match, 0, sizeof match);
		for (int i = 0; i < N; ++i)
			e[i].clear();
		n = read<int>(), k = read<int>();
		for (int i = 1; i <= n; ++i)
			a[i] = read<int>();
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (isprime[a[i] + a[j]]) adde(i, j), adde(j, i);
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++) {
			vis.reset();
			if (!match[i] && dfs(i))
				sum1++;
		}
		for (int i = 1; i <= n; i++)
			if (!e[i].empty() && !match[i])
				sum2++;
		if (sum1 >= k)
			write(k << 1, '\n');
		else
			write((sum1 << 1) + std::min(k - sum1, sum2), '\n');
	}
	return 0;
}
