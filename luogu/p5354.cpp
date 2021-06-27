/**
 * File              : P5354.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-02 07:58:45
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

// #define int unsigned long long
const int N = 2e5 + 5;
std::vector<int> g[N];
struct Node {
	int opt, size, depth, fa, son, top, dfn;
	unsigned long long val;
} p[N];
int n, m, k, a[N];

inline void dfs1(int u, int fa, int depth) {
	p[u].depth = depth, p[u].fa = fa, p[u].size = 1, p[u].son = 0;
	int max = 0;
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs1(v, u, depth + 1);
		p[u].size += p[v].size;
		if (p[v].size > max)
			max = p[v].size, p[u].son = v;
	}
}
int dfnCounter = 0;
inline void dfs2(int u, int top) {
	p[u].top = top, p[u].dfn = ++dfnCounter;
	a[dfnCounter] = p[u].val;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (auto v : g[u]) {
		if (v == p[u].fa || v == p[u].son) continue;
		dfs2(v, v);
	}
}
inline int lca(int u, int v) {
	for (; p[u].top != p[v].top;) {
		if (p[p[u].top].depth < p[p[v].top].depth) std::swap(u, v);
		u = p[p[u].top].fa;
	}
	return p[u].depth < p[v].depth ? u : v;
}

namespace SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
struct Segt {
	Segt() { l0 = r0 = 0, l1 = r1 = ~0; }
	unsigned long long l0, r0, l1, r1;
	Segt operator+(const Segt &Other) const {
		Segt res;
		res.l0 = (this->l0 & Other.l1) | (~this->l0 & Other.l0);
		res.l1 = (this->l1 & Other.l1) | (~this->l1 & Other.l0);
		res.r0 = (Other.r0 & this->r1) | (~Other.r0 & this->r0);
		res.r1 = (Other.r1 & this->r1) | (~Other.r1 & this->r0);
		return res;
	}
} segt[N << 2];
void modify(int pos, int opt, unsigned long long val, int l, int r, int k) {
	if (l >= r) {
		if (opt == 1) // &
			segt[k].l0 = segt[k].r0 = 0, segt[k].l1 = segt[k].r1 = val;
		if (opt == 2) // |
			segt[k].l0 = segt[k].r0 = val, segt[k].l1 = segt[k].r1 = ~0;
		if (opt == 3) // ^
			segt[k].l0 = segt[k].r0 = val, segt[k].l1 = segt[k].r1 = ~val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(pos, opt, val, l, mid, lson);
	if (mid + 1 <= pos) modify(pos, opt, val, mid + 1, r, rson);
	segt[k] = segt[lson] + segt[rson];
}
Segt query(int L, int R, int l = 1, int r = n, int k = 1) {
	if (L <= l && r <= R) return segt[k];
	int mid = (l + r) >> 1;
	Segt res;
	if (L <= mid) res = res + query(L, R, l, mid, lson);
	if (mid + 1 <= R) res = res + query(L, R, mid + 1, r, rson);
	return res;
}
#undef lson
#undef rson
} // namespace SegmentTree

inline void modify(int pos, int opt, unsigned long long val) { SegmentTree::modify(pos, opt, val, 1, n, 1); }
inline unsigned long long query(int u, int v, unsigned long long range) {
	int LCA = lca(u, v);
	SegmentTree::Segt res1, res2, res;
	for (; p[u].top != p[LCA].top; u = p[p[u].top].fa)
		res1 = SegmentTree::query(p[p[u].top].dfn, p[u].dfn) + res1;
	res1 = SegmentTree::query(p[LCA].dfn, p[u].dfn) + res1;

	for (; p[v].top != p[LCA].top; v = p[p[v].top].fa)
		res2 = SegmentTree::query(p[p[v].top].dfn, p[v].dfn) + res2;
	if (v != LCA) res2 = SegmentTree::query(p[LCA].dfn + 1, p[v].dfn) + res2;

	std::swap(res1.l0, res1.r0), std::swap(res1.l1, res1.r1); // Switch the Direction
	res = res1 + res2;

	bool flag = 1;
	unsigned long long ans = 0;
	for (int i = k - 1; ~i; --i) {
		unsigned long long l0 = res.l0 >> i & 1, l1 = res.l1 >> i & 1, t = range >> i & 1;
		if (!flag)
			ans |= std::max(l0, l1) << i;
		else if (t == 0)
			ans |= l0 << i;
		else if (l0 >= l1)
			ans |= l0 << i, flag = 0;
		else
			ans |= l1 << i;
	}
	return ans;
}

bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].opt >> p[i].val;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
#ifdef DEBUG
	cerr << "dfn:" << endl;
	for (int i = 1; i <= n; ++i)
		cerr << p[i].dfn << ' ';
	cerr << endl;
	cerr << "son:" << endl;
	for (int i = 1; i <= n; ++i)
		cerr << p[i].son << ' ';
	cerr << endl;
	cerr << "top:" << endl;
	for (int i = 1; i <= n; ++i)
		cerr << p[i].top << ' ';
	cerr << endl;
#endif
	for (int i = 1; i <= n; ++i)
		modify(p[i].dfn, p[i].opt, p[i].val);

	for (int i = 1; i <= m; ++i) {
		int opt, x, y;
		unsigned long long z;
		cin >> opt >> x >> y >> z;
		if (opt == 1)
			cout << query(x, y, z) << endl;
		if (opt == 2)
			modify(p[x].dfn, y, z);
	}
	cout.flush();
	return 0;
}
