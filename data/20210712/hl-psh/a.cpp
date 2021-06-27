/*
	Author: Ruakker
	Date: 2021-07-12 07:35:27
	LastEditTime: 2021-07-12 16:23:33
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO {
static const int BUFSIZE__ = (1 << 20) + 1;
static char Ibuf__[BUFSIZE__], *I1__ = Ibuf__, *I2__ = Ibuf__, Obuf__[BUFSIZE__], *O1__ = Obuf__, *O2__ = O1__ + BUFSIZE__ - 1;
static int ST__[55], Top__;
inline void flush() { fwrite(Obuf__, 1, O1__ - Obuf__, stdout), O1__ = Obuf__; }
struct flusher__ {
	~flusher__() { flush(); }
} IO__;
inline char getch() { return I1__ == I2__ && (I2__ = (I1__ = Ibuf__) + fread(Ibuf__, 1, BUFSIZE__, stdin), I1__ == I2__) ? EOF : *I1__++; }
inline void putch(char Ch__) { *O1__++ = Ch__, (O1__ == O2__) ? flush() : void(); }
inline void getstr(char* S__) {
	char Ch__ = getch();
	int cnt__ = 0;
	for (; !isgraph(Ch__); Ch__ = getch())
		;
	for (; isgraph(Ch__); Ch__ = getch())
		S__[cnt__++] = Ch__;
	S__[cnt__] = 0;
}
inline void putstr(const char* S__) {
	int Len__ = strlen(S__);
	for (int i__ = 0; i__ < Len__; ++i__)
		putch(S__[i__]);
}
template <typename Var__>
inline Var__ read() {
	register Var__ Res__ = 0, W__ = 1;
	register char Ch__ = getch();
	for (; Ch__ < '0' || Ch__ > '9'; Ch__ = getch())
		if (Ch__ == '-') W__ = -1;
	for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
		Res__ = (Res__ << 3) + (Res__ << 1) + (Ch__ ^ 48);
	return Res__ * W__;
}
inline double readDB() {
	register double ResB__ = 0, Cnt__ = 1;
	register char Ch__ = getch();
	register int ResA__ = 0, W__ = 1;
	if (Ch__ != '.') {
		for (; Ch__ < '0' || Ch__ > '9'; Ch__ = getch())
			if (Ch__ == '-') W__ = -1;
		for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
			ResA__ = (ResA__ << 3) + (ResA__ << 1) + (Ch__ ^ 48);
		if (Ch__ != '.') return ResA__ * W__;
	}
	Ch__ = getch();
	for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
		ResB__ += (Ch__ ^ 48) * (Cnt__ *= 0.1);
	return (ResA__ + ResB__) * W__;
}
template <typename Var__>
inline void write(register Var__ Num__, const char Ch__ = '\0') {
	if (!Num__) putch('0');
	if (Num__ < 0) putch('-'), Num__ = -Num__;
	for (; Num__; ST__[++Top__] = Num__ % 10 + '0', Num__ /= 10)
		;
	for (; Top__; putch(ST__[Top__--]))
		;
	if (Ch__ != '\0') putch(Ch__);
}
} // namespace FastIO
using namespace FastIO;
#define int long long
const int N = 2005;
struct Edge {
	int nxt, to, val;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
int dp[N][N], n, m, size[N];
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
void dfs(int u, int pre) {
	size[u] = 1;
	dp[u][0] = dp[u][1] = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to, val = e[i].val;
		if (v == pre) continue;
		dfs(v, u);
		size[u] += size[v];
		for (int j = min(m, size[u]); j >= 0; --j) {
			//size[v]: the nodes downside, (n-m-size[v]): the nodes upside.
			int up = size[v], down = n - m - size[v];
			if (dp[u][j] != -1) dp[u][j] += dp[v][0] + up * down * val;
			for (int k = min(j, size[v]); k >= 1; --k) {
				if (dp[u][j - k] == -1) continue;
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] + (k * (m - k) + (up - k) * (down + k)) * val);
			}
		}
	}
}
signed main() {
	// freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	n = read<int>(), m = read<int>();
	memset(dp, -1, sizeof dp);
	for (int i = 1; i < n; ++i) {
		int u = read<int>(), v = read<int>(), w = read<int>();
		adde(u, v, w), adde(v, u, w);
	}
	dfs(1, -1);
	write<ll>(dp[1][m], '\n');
	return 0;
}
