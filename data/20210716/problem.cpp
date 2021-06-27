/*
	Author: Ruakker
	Date: 2021-07-16 15:51:23
	LastEditTime: 2021-07-16 16:07:19
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const int N = 3e5 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
int n, m, siz, k, mn, totid, DFN, top, x[N], y[N];
int inDgr[N], outDgr[N], sta[N], dfn[N], low[N], id[N], size[N];
std::bitset<N> vis;

inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}

inline void tarjan(int u) {
	dfn[u] = low[u] = ++DFN;
	sta[++top] = u, vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v])
			tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (vis[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++totid;
		do {
			id[sta[top]] = totid;
			vis[sta[top]] = 0;
			++size[totid];
		} while (sta[top--] != u);
	}
}

int dfs(int u) {
	vis[u] = 1;
	if (!outDgr[u]) {
		++siz;
		return size[u];
	}
	int res = size[u];
	++siz;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v]) res += dfs(v);
	}
	return res;
}

signed main() {
	freopen("problem.in", "r", stdin), freopen("problem.out", "w", stdout);
	FastIO;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		adde(x[i], y[i]);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	memset(e, 0, sizeof e);
	memset(head, 0, sizeof head);
	vis.reset();
	tote = 1;
	for (int i = 1; i <= m; ++i)
		if (id[x[i]] != id[y[i]]) {
			adde(id[x[i]], id[y[i]]);
			++outDgr[id[x[i]]], ++inDgr[id[y[i]]];
		}
	for (int i = 1; i <= totid; ++i)
		if (!inDgr[i]) {
			++k, siz = 0;
			mn += dfs(i) - siz;
		}
	for (int i = mn; i <= n - k; ++i)
		cout << i << endl;
	return 0;
}
