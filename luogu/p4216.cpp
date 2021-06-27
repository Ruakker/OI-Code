/*
	Author: Ruakker
	Date: 2021-07-24 13:42:56
	LastEditTime: 2021-07-24 14:56:21
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
bool MEMST;

constexpr int N = 2e5 + 5;
std::vector<int> e[N], Query[N];
int n, m, rt;

namespace FenwickTree {
int lowbit(int x) { return x & -x; }
const int N = 5e5 + 5;
int t[N];
void add(int k, int val) {
	for (; k <= n; k += lowbit(k))
		t[k] += val;
}
int getsum(int k) {
	int res = 0;
	for (; k > 0; k -= lowbit(k))
		res += t[k];
	return res;
}
} // namespace FenwickTree

namespace HeavyPathDecomposition {
struct Node {
	int fa, depth, sz, son, top, dfn; // son means the HEAVY-SON of the current node.
} p[N];
int cnt = 0, rank[N]; // rank[i] means the position of the node which has the dfn i.
void dfs1(int u, int pre, int depth) {
	p[u].fa = pre, p[u].depth = depth, p[u].sz = 1, p[u].son = -1;
	int childSize = -inf;
	for (auto v : e[u]) {
		if (v == pre) continue;
		dfs1(v, u, depth + 1);
		p[u].sz += p[v].sz;
		if (p[v].sz > childSize)
			childSize = p[v].sz, p[u].son = v;
	}
}
void dfs2(int u, int top) {
	p[u].top = top, p[u].dfn = ++cnt, rank[cnt] = u;
	if (!~p[u].son) return;
	dfs2(p[u].son, p[u].son);
	for (auto v : e[u]) {
		if (v == p[u].fa || v == p[u].son) continue;
		dfs2(v, v);
	}
}
inline int getsum(int u, int v) {
	int res = 0;
	for (; p[u].top != p[v].top;) {
		if (p[u].depth < p[v].depth) std::swap(u, v);
		res += FenwickTree::getsum(p[p[u].top].dfn) - FenwickTree::getsum(p[u].dfn - 1);
		u = p[p[u].top].fa;
	}
	res += FenwickTree::getsum(p[u].dfn) - FenwickTree::getsum(p[v].dfn - 1);
}
inline void add(int u, int val) {
}
} // namespace HeavyPathDecomposition
using namespace HeavyPathDecomposition;

bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int cur;
		cin >> cur;
		if (cur == 0)
			rt == i;
		else
			e[cur].emplace_back(i), e[i].emplace_back(cur);
	}

	dfs1(rt, 0, 1);
	dfs2(rt, rt);

	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int st, ed, c;
			cin >> st >> ed >> c;
			Query[i - c - 1].emplace_back(i);
		}
	}

	cout.flush();
	return 0;
}
