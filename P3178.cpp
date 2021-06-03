/*
	Author: Ruakker
	Date: 2021-05-27 08:12:08
	LastEditTime: 2021-05-31 17:12:45
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
#define int long long
const int N = 1e6 + 5;
struct Edge {
	int to, nxt;
} e[N << 1];
int head[N], tote = e;
inline void adde(int x, int y) {
	e[++tote] = (Edge){y, head[x]};
	head[x] = tote;
}
int n, m;
struct Node {
	int val, dfn, sz, tp, fa, son, depth;
} p[N];
int cntdfn = 0, q[N];

namespace SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
struct SegTree {
	int tag, val;
} segt[N];
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
void build(int l, int r, int k) {
	segt[k].tag = 0;
	if (l >= r) return segt[k].val = q[l], void();
	int mid = l + r >> 1;
	build(l, mid, lson), build(mid + 1, r, rson);
	pushup(k);
}
void modify(int L, int R, int l, int r, int val, int k) {
	if (l > r) cerr << "Fuck CCF" << endl;
	if (L <= l && r <= R) {
		segt[k].val += val * (r - l + 1), segt[k].tag += val;
		return;
	}
	pushdown(l, r, k);
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, val, lson);
	if (mid < R) modify(L, R, mid + 1, r, val, rson);
	pushup(k);
}
int query(int L, int R, int l, int r, int k) {
	if (l > r) cerr << "Fuck CCF" << endl;
	if (L <= l && r <= R) return segt[k].val;
	pushdown(l, r, k);
	int mid = l + r >> 1, res = 0;
	if (L <= mid) res += query(L, R, l, mid, lson);
	if (mid < R) res += query(L, R, mid + 1, r, rson);
	return res;
}
#undef lson
#undef rson
} // namespace SegmentTree
using namespace SegmentTree;

namespace TreeCutting {
void dfs1(int u, int pre, int depth) {
	p[u].sz = 1, p[u].fa = pre, p[u].depth = depth;
	int max = -inf;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre) continue;
		dfs1(v, u, depth + 1);
		if (max < p[v].sz)
			max = p[v].sz, p[u].son = v;
		p[u].sz += p[v].sz;
	}
}
void dfs2(int u, int top) {
	++cntdfn;
	p[u].tp = top, p[u].dfn = cntdfn, q[cntdfn] = p[u].val;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == p[u].fa || v == p[u].son) continue;
		dfs2(v, v);
	}
}
inline void opt1(int u, int val) {
	modify(p[u].dfn, p[u].dfn, 1, n, val, 1);
}
inline void opt2(int u, int val) {
	modify(p[u].dfn, p[u].dfn + p[u].sz - 1, 1, n, val, 1);
}
inline int opt3(int u, int v) {
	int res = 0;
	for (; p[u].tp != p[v].tp;) {
		if (p[p[u].tp].depth < p[p[v].tp].depth) std::swap(u, v);
		res += query(p[p[u].tp].dfn, p[u].dfn, 1, n, 1);
		u = p[p[u].tp].fa;
	}
	if (p[u].depth > p[v].depth) std::swap(u, v);
	res += query(p[u].dfn, p[v].dfn, 1, n, 1);
	return res;
}
} // namespace TreeCutting
using namespace TreeCutting;

signed main() {
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= n; ++i)
		p[i].val = read<int>();
	for (int i = 1; i < n; ++i) {
		int u = read<int>(), v = read<int>();
		adde(u, v), adde(v, u);
	}
	dfs1(1, -1, 1);
	dfs2(1, 1);
	build(1, n, 1);

	// for (int i = 1; i <= n; ++i)
	// 	cerr << q[i] << ' ';
	// cerr << endl;

	// for (int i = 1; i <= n; ++i)
	// 	cerr << query(i, i, 1, n, 1) << ' ';
	// cerr << endl;

	for (int i = 1; i <= m; ++i) {
		int opt = read<int>();
		if (opt == 1) {
			int x = read<int>(), val = read<int>();
			opt1(x, val);
		}
		if (opt == 2) {
			int x = read<int>(), val = read<int>();
			opt2(x, val);
		}
		if (opt == 3) {
			int x = read<int>();
			write(opt3(x, 1), '\n');
		}
	}
	return 0;
}
