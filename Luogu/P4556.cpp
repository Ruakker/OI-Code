/*
	Author: Ruakker
	Date: 2021-05-29 19:48:40
	LastEditTime: 2021-05-29 20:24:28
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
const int N = 1e5 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}

/* Segment-Tree Start */
#define lson k << 1
#define rson k << 1 | 1
struct SegmentTree {
	int val, tag;
} segt[N << 4];
inline void pushup(int k) {
	segt[k].val = segt[lson].val + segt[rson].val;
}
inline void pushdown(int l, int r, int k) {
	if (!segt[k].tag) return;
	int mid = l + r >> 1;
	segt[lson].tag += segt[k].tag;
	segt[rson].tag += segt[k].tag;
	segt[lson].val += segt[k].tag * (mid - l + 1);
	segt[rson].val += segt[k].tag * (r - mid);
	segt[k].tag = 0;
}
/* Segment-Tree End */

/* Tree-Cutting Start */
struct Node {
	int sz, tp, fa, son, dfn;
} p[N];
void dfs1(int u, int pre) {
	p[u].sz = 1, p[u].fa = pre;
	int max = -inf;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dfs1(u, v);
		if (max < p[v].sz)
			max = p[v].sz, p[u].son = v;
		p[u].sz += p[v].sz;
	}
}
int totp = 0;
void dfs2(int u, int top) {
	p[u].tp = top, p[dfn] = ++totp;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == p[u].son || v == p[u].fa) continue;
		dfs2(v, v);
	}
}
/* Tree-Cutting End */

signed main() {
	int n = read<int>(), m = read<int>();
	for (int i = 1; i < n; ++i) {
		int u = read<int>(), v = read<int>();
		adde(u, v), adde(v, u);
	}

	return 0;
}
