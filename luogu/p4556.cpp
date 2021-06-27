/*
	Author: Ruakker
	Date: 2021-05-29 19:48:40
	LastEditTime: 2021-05-29 20:24:28
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
int n, m;

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
	int mid = (l + r) >> 1;
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
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adde(u, v), adde(v, u);
	}
	return 0;
}
