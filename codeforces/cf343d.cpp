/**
 * File              : CF343D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-09 15:25:04
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#	define endl '\n'
#endif
bool MEMST;
const int N = 5e5 + 5;
int n, q;
std::vector<int> g[N];

struct Node {
	int size, top, son, fa;
} p[N];
int a[N], bel[N];
void dfs1(int u) {
	p[u].size = 1, p[u].son = 0;
	int max = -inf;
	for (auto v : g[u]) {
		if (v == p[u].fa) continue;
		p[v].fa = u;
		dfs1(v);
		p[u].size += p[v].size;
		if (p[v].size > max) {
			max = p[v].size;
			p[u].son = v;
		}
	}
}
int dfnCounter = 0;
void dfs2(int u, int top) {
	p[u].top = top, bel[u] = ++dfnCounter;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (auto v : g[u]) {
		if (v == p[u].fa || v == p[u].son) continue;
		dfs2(v, v);
	}
}

namespace SegT {
#define lson (k << 1)
#define rson (k << 1 | 1)
struct SegmentTree {
	SegmentTree() { val = 0, tag = -1; }
	int val, tag;
} segt[N << 2];
inline void pushdown(int l, int r, int k) {
	if (segt[k].tag == -1) return;
	int mid = (l + r) >> 1;
	segt[lson].tag = segt[rson].tag = segt[k].tag;
	segt[lson].val = segt[k].tag * (mid - l + 1);
	segt[rson].val = segt[k].tag * (r - mid);
	segt[k].tag = -1;
}
inline void pushup(int k) { segt[k].val = segt[lson].val + segt[rson].val; }
void modify(int L, int R, int l, int r, int val, int k) {
#ifdef DEBUG
	cerr << ">>> " << L << ' ' << R << ' ' << l << ' ' << r << endl;
#endif
	if (L <= l && r <= R) {
		segt[k].tag = val;
		segt[k].val = val * (r - l + 1);
		return;
	}
	pushdown(l, r, k);
	int mid = (l + r) >> 1;
	if (L <= mid) modify(L, R, l, mid, val, lson);
	if (mid + 1 <= R) modify(L, R, mid + 1, r, val, rson);
	pushup(k);
}
int query(int pos, int l, int r, int k) {
	if (l == pos && r == pos) return segt[k].val;
	pushdown(l, r, k);
	int mid = (l + r) >> 1;
	if (pos <= mid)
		return query(pos, l, mid, lson);
	else
		return query(pos, mid + 1, r, rson);
}
#undef lson
#undef rson
} // namespace SegT
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	p[1].fa = 0;
	dfs1(1);
	dfs2(1, 1);
#ifdef DEBUG
	cerr << ">>> top" << endl
	     << ">>> ";
	for (int i = 1; i <= n; ++i)
		cerr << p[i].top << ' ';
	cerr << endl;
#endif
	cin >> q;
	for (int opt, u; q--;) {
		cin >> opt >> u;
		if (opt == 1)
			SegT::modify(bel[u], bel[u] + p[u].size - 1, 1, n, 1, 1);
		if (opt == 2) {
			for (; p[u].top != 1; u = p[p[u].top].fa)
				SegT::modify(bel[p[u].top], bel[u], 1, n, 0, 1);
			SegT::modify(1, bel[u], 1, n, 0, 1);
		}
		if (opt == 3)
			cout << SegT::query(bel[u], 1, n, 1) << endl;
	}
	cout.flush();
	return 0;
}

