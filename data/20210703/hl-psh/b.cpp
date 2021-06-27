/*
	Author: Ruakker
	Date: 2021-07-03 15:49:11
	LastEditTime: 2021-07-03 16:38:18
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
using std::cerr;
using std::endl;
#define int long long
bool MEMST;
const int N = 7e5 + 5;
struct Edge {
	int nxt, to, val;
} e[N << 1];
int tote = 1, head[N];
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
int n, st, k, down[N], dgr[N], fa[N], downmaxval[N];
void dfs(int u, int pre) {
	fa[u] = pre;
	if (dgr[u] == 1 && u != 1) down[u] = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre) continue;
		dfs(v, u);
		down[u] = std::max(down[v] + 1, down[u]);
		downmaxval[u] = std::max(downmaxval[u], downmaxval[v] + e[i].val);
	}
}
bool flag = 0;
void dfs2(int u, int pre, int reststeps, int res) {
	if (flag) return;
	if (!reststeps) {
		if (res >= k)
			flag = 1;
		return;
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre || v == fa[u]) continue;
		dfs2(v, u, reststeps - 1, res + e[i].val);
	}
}
inline bool chk(int cur) {
	flag = 0;
	dfs2(st, -1, cur, 0);
	return flag;
}
inline int BinarySearch(int l, int r) {
	int res = -1;
	for (; l <= r;) {
		int mid = l + r >> 1;
		if (chk(mid))
			res = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return res;
}
bool MEMED;
signed main() {
	freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	cerr << "Memory used: " << fabs(&MEMST - &MEMED) / 1048576.0 << endl;
	int id = read<int>();
	n = read<int>();
	for (int i = 1; i < n; ++i) {
		int u = read<int>(), v = read<int>(), w = read<int>();
		adde(u, v, w), adde(v, u, w);
		++dgr[u], ++dgr[v];
	}
	memset(down, -1, sizeof down);
	memset(downmaxval, 0, sizeof downmaxval);
	dfs(1, 0);
	// for (int i = 1; i <= n; ++i)
	// 	cerr << down[i] << endl;
	for (int q = read<int>(); q--;) {
		st = read<int>(), k = read<int>();
		if (downmaxval[st] < k) {
			putstr("-1\n");
			continue;
		}
		if (downmaxval[st] == k) {
			write(down[st], '\n');
			continue;
		}
		write<int>(BinarySearch(0, down[st] + 1), '\n');
	}
	return 0;
}
