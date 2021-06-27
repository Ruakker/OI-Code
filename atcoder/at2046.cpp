/**
 * File              : AT2046.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/22
 * Last Modified Date: 2021/08/22
 */
/**
 * @Date:   2021-Apr-26
 * @Email:  i@ruakker.cn
 * @Filename: AT2046.cpp
 * @Last modified time: 2021-Jun-02
**/

#include <bits/stdc++.h>
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
inline int getstr(char *S) {
	char Ch = getch();
	int cnt = 0;
	for (; !isgraph(Ch); Ch = getch())
		;
	for (; isgraph(Ch); Ch = getch())
		S[cnt++] = Ch;
	S[cnt] = 0;
	return cnt;
}
inline void putstr(const char *S) {
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
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
const int N = 1e6 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
int val[N], k[N], st[N], top, ans, blackcnt, n, oddu, oddv, m, whitecnt; // -1: white, 1: black
bool isodd = 0;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}

void predfs(int u, int pre) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre) continue;
		if (val[v]) {
			if (val[v] == val[u])
				isodd = 1;
			oddu = u, oddv = v;
			continue;
		}
		if (val[u] == -1)
			val[v] = 1, ++blackcnt;
		else
			val[v] = -1, ++whitecnt;
		predfs(v, u);
	}
}
void dfs(int u, int pre) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre || (u == oddu && v == oddv) || (u == oddv && v == oddu)) continue;
		dfs(v, u);
		val[u] += val[v], k[u] += k[v];
	}
}

signed main() {
	n = read<int>(), m = read<int>();
	if (n & 1) return putstr("-1\n"), 0;
	for (int i = 1; i <= m; ++i) {
		int u = read<int>(), v = read<int>();
		adde(u, v), adde(v, u);
	}
	val[1] = 1, ++blackcnt;
	predfs(1, -1);
	if (n == m + 1) {
		if (whitecnt != blackcnt)
			return putstr("-1\n"), 0;
	} else {
		if (isodd) {
			int sum = blackcnt - whitecnt >> 1;
			ans += std::abs(sum), val[oddu] -= sum, val[oddv] -= sum;
		} else {
			if (whitecnt != blackcnt)
				return putstr("-1\n"), 0;
			k[oddu] = 1, k[oddv] = -1;
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		if (k[i])
			st[++top] = k[i] * val[i];
		else
			ans += std::abs(val[i]);
	st[++top] = 0;
	std::sort(st + 1, st + 1 + top);
	int mid = st[top + 1 >> 1];
	for (int i = 1; i <= top; ++i)
		ans += std::abs(st[i] - mid);
	write<int>(ans, '\n');
	return 0;
}
