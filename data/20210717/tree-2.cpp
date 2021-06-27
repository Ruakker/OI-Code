/*
	Author: Ruakker
	Date: 2021-07-17 13:34:25
	LastEditTime: 2021-07-17 20:16:46
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const int N = 1e5 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
int n, m, bfn[N], f[N][30];

inline void bfs() {
	std::bitset<N> vis;
	std::queue<int> Q;
	int totbfn = 0;
	vis.reset();
	vis.set(1), Q.push(1), bfn[1] = ++totbfn;
	for (; !Q.empty();) {
		int u = Q.front();
		Q.pop(), bfn[u] = ++totbfn, vis.set(u);
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (vis[v]) continue;
			Q.push(v);
		}
	}
}

void dfs(int u, int pre) {
	f[u][1] = f[u][2] = pre;
	for (int i = 3; i <= 25; ++i)
		f[u][i] = f[f[u][i - 2]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre) continue;
		dfs(v, u);
	}
}
inline void init() {
	for (int i = 1; i <= n;)
}

#define lson (k << 1)
#define rson (k << 1 | 1)
struct SegmentTree {
	int val, tag;
} segt[N << 4];
void build(int l, int r, int k) {
	if (l >= r)
		return segt[k].val = a[l], void();
}

signed main() {
	fre(tree);
	FastIO;

	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adde(u, v), adde(v, u);
	}

	bfs();
	dfs(1, 0);
	return 0;
}
