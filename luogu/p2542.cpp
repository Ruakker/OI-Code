/*
	Author: Ruakker
	Date: 2021-05-27 08:28:32
	LastEditTime: 2021-05-27 15:09:38
*/
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <map>
// #include <stack>
// #include <vector>
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define getch getchar
#define putch putchar
namespace FastIO {
	static const int BUFSIZE = (1 << 20) + 1;
	static char Ibuf[BUFSIZE], *I1 = Ibuf, *I2 = Ibuf, Obuf[BUFSIZE], *O1 = Obuf, *O2 = O1 + BUFSIZE - 1;
	static int ST[55], Top;
	inline void flush() { fwrite(Obuf, 1, O1 - Obuf, stdout), O1 = Obuf; }
	struct flusher {
		~flusher() { flush(); }
	} IO;
	// inline char getch() { return I1 == I2 && (I2 = (I1 = Ibuf) + fread(Ibuf, 1, BUFSIZE, stdin), I1 == I2) ? EOF : *I1++; }
	// inline void putch(char Ch) { *O1++ = Ch, (O1 == O2) ? flush() : void(); }
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
bool STARTMEM;
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
const int N = 5e5 + 5;
#define int long long
int n, m;
struct ForwardStar {
	int from, to, nxt, vis;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (ForwardStar){x, y, head[x], 0};
	head[x] = tote;
}

/* Segment Tree Start */
#define lson k << 1
#define rson k << 1 | 1
struct SegmentTree {
	int val, tag;
} segt[N << 2];
inline void pushup(int k) {
	segt[k].val = segt[lson].val + segt[rson].val;
}
inline void pushdown(int l, int r, int k) {
	if (!segt[k].tag) return;
	int mid = l + r >> 1;
	segt[lson].tag = segt[rson].tag = 1;
	segt[lson].val = segt[rson].val = 0;
	segt[k].tag = 0;
}
void build(int l, int r, int k) {
	segt[k].tag = 0;
	if (l >= r) return segt[k].val = 1, void();
	int mid = l + r >> 1;
	build(l, mid, lson), build(mid + 1, r, rson);
	pushup(k);
}
void modify(int L, int R, int l, int r, int k) {
	if (L <= l && r <= R) {
		segt[k].val = 0, segt[k].tag = 1;
		return;
	}
	pushdown(l, r, k);
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, lson);
	if (mid < R) modify(L, R, mid + 1, r, rson);
	pushup(k);
}
int query(int L, int R, int l, int r, int k) {
	if (L <= l && r <= R) return segt[k].val;
	pushdown(l, r, k);
	int mid = l + r >> 1, res = 0;
	if (L <= mid) res += query(L, R, l, mid, lson);
	if (mid < R) res += query(L, R, mid + 1, r, rson);
	return res;
}
#undef lson
#undef rson
/* Segment Tree End */

/* Tree-Cutting Start */
struct Node {
	int sz, depth, fa, son, dfn, tp, vis;
} p[N];
void predfs(int u) {
	p[u].vis = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		e[i].vis = e[i ^ 1].vis = 1;
		int v = e[i].to;
		if (p[v].vis) continue;
		predfs(v);
	}
}
void dfs1(int u, int pre, int depth) {
	p[u].depth = depth, p[u].fa = pre, p[u].sz = 1;
	int max = -inf;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre || !e[i].vis) continue;
		dfs1(v, u, depth + 1);
		p[u].sz += p[v].sz;
		if (max < p[v].sz)
			max = p[v].sz, p[u].son = v;
	}
}
int cnte = 0;
void dfs2(int u, int top) {
	++cnte;
	p[u].dfn = cnte, p[u].tp = top;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == p[u].fa || v == p[u].son || !e[i].vis) continue;
		dfs2(v, v);
	}
}
inline void opt0(int u, int v) {
	for (; p[u].tp != p[v].tp;) {
		if (p[p[u].tp].depth < p[p[v].tp].depth) std::swap(u, v);
		modify(p[p[u].tp].dfn, p[u].dfn, 1, n, 1);
		u = p[p[u].tp].fa;
	}
	if (p[u].depth > p[v].depth) std::swap(u, v);
	if (p[u].depth != p[v].depth) modify(p[u].dfn, p[v].dfn, 1, n, 1);
}
inline int opt1(int u, int v) {
	int res = 0;
	for (; p[u].tp != p[v].tp;) {
		if (p[p[u].tp].depth < p[p[v].tp].depth) std::swap(u, v);
		res += query(p[p[u].tp].dfn, p[u].dfn, 1, n, 1);
		u = p[p[u].tp].fa;
	}
	if (p[u].depth > p[v].depth) std::swap(u, v);
	res += query(p[u].dfn, p[v].dfn, 1, n, 1);
	res -= query(p[u].dfn, p[u].dfn, 1, n, 1);
	return res;
}
/* Tree-Cutting End */

struct Query {
	int opt, u, v;
};
struct Edge {
	int u, v, del;
};
std::map<pii, int> edges;
std::vector<Edge> E;
std::stack<Query> q;
std::stack<int> ans;
bool ENDMEM;
signed main() {
	cerr << fabs(&STARTMEM - &ENDMEM) / 1048576.0 << endl;
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= m; ++i) {
		int u = read<int>(), v = read<int>();
		edges[mp(u, v)] = i;
		E.push_back((Edge){u, v, 0});
	}
	for (int opt = read<int>(); ~opt; opt = read<int>()) {
		int u = read<int>(), v = read<int>();
		q.push((Query){opt, u, v});
		if (!opt) E[edges[mp(u, v)] - 1].del = 1;
	}
	for (int i = 0; i < E.size(); ++i)
		if (!E[i].del) {
			cerr << E[i].u << ' ' << E[i].v << endl;
			adde(E[i].u, E[i].v), adde(E[i].v, E[i].u);
		}
	// predfs(1);
	dfs1(1, -1, 1);
	dfs2(1, 1);
	build(1, n, 1);

	cerr << tote << endl;
	for (int i = 2; i <= tote; i += 2)
		cerr << e[i].from << ' ' << e[i].to << ' ' << e[i].vis << endl;
	for (int i = 1; i <= n; ++i)
		cerr << query(i, i, 1, n, 1) << ' ';
	cerr << endl;

	for (int i = 2; i <= tote; i += 2)
		if (!e[i].vis) opt0(e[i].from, e[i].to);
	for (; !q.empty(); q.pop()) {
		Query cur = q.top();
		if (cur.opt == 0)
			opt0(cur.u, cur.v);
		if (cur.opt == 1) ans.push(opt1(cur.u, cur.v));

		for (int i = 1; i <= n; ++i)
			cerr << query(i, i, 1, n, 1) << ' ';
		cerr << endl;
	}
	for (; !ans.empty(); ans.pop())
		write(ans.top(), '\n');
	return 0;
}
