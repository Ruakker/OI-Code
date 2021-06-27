/**
 * File              : P5903.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-13 18:36:36
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
#define ui unsigned int
ui seed;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return seed = x;
}
#define int long long
constexpr int N = 5e6 + 5;
std::vector<int> g[N];
int n, q, ans;
int root;
struct Node {
	int depth, size, top, fa[31], son, dfn;
} p[N];
void dfs1(int u) {
	int max = -inf;
	p[u].size = 1, p[u].son = 0;
	for (int i = 1; i < 31; ++i)
		p[u].fa[i] = p[p[u].fa[i - 1]].fa[i - 1];
	for (auto v : g[u]) {
		if (v == p[u].fa[0]) continue;
		p[v].depth = p[u].depth + 1;
		dfs1(v);
		p[u].size += p[v].size;
		if (p[v].size > max) max = p[v].size, p[u].son = v;
	}
}
void dfs2(int u, int top) {
	p[u].top = top;
	if (!p[u].son) return;
	dfs2(p[u].son, top);
	for (auto v : g[u]) {
		if (v == p[u].fa[0] || v == p[u].son) continue;
		dfs2(v, v);
	}
}
inline int query(int u, int k) {
	int v = u;
	for (; p[u].depth - p[p[v].top].depth < k; v = p[p[v].top].fa[0])
		;
	int delta = k - (p[u].depth - p[v].depth);
	for (int i = 0; delta; ++i, delta >>= 1)
		if (delta & 1)
			v = p[v].fa[i];
	assert(v);
	return v;
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> q >> seed;
	for (int u = 1, v; u <= n; ++u) {
		cin >> v;
		if (!v) root = u;
		g[u].emplace_back(v), g[v].emplace_back(u);
		p[u].fa[0] = v;
	}
	p[root].depth = 1;
	dfs1(root);
	dfs2(root, root);
#ifdef DEBUG
	cerr << ">>> The \'fa\': ";
	for (int i = 0; i <= 3; ++i)
		cerr << p[6].fa[i] << ' ';
	cerr << endl;
#endif
	int lastAns = 0;
	for (int i = 1; i <= q; ++i) {
		int u = (get(seed) ^ lastAns) % n + 1;
		int k = (get(seed) ^ lastAns) % p[u].depth;
		lastAns = query(u, k);
		ans ^= i * lastAns;
#ifdef DEBUG
		cerr << u << ' ' << k << endl;
		cerr << lastAns << endl;
#endif
	}
	cout << ans << endl;
	cout.flush();
	return 0;
}

