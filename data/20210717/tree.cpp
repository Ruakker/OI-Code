/*
	Author: Ruakker
	Date: 2021-07-17 09:17:29
	LastEditTime: 2021-07-17 14:11:09
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const int N = 1e6 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}

int n, m, fibo[N], fa[N], a[N];
std::bitset<N> inFibo;

inline void GetFibonacci(int n) {
	fibo[1] = 1, inFibo.reset();
	inFibo[0] = inFibo[1] = 1;
	for (int i = 2; fibo[i] <= n; ++i)
		fibo[i] = fibo[i - 1] + fibo[i - 2], inFibo.set(fibo[i]);
}

void dfs(int u, int pre) {
	fa[u] = pre;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre) continue;
		dfs(v, u);
	}
}

void add(int u, int val, int k) {
	if (inFibo[k])
		a[u] += val;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa[u]) continue;
		add(v, val, k + 1);
	}
}

int getsum(int u, int k) {
	int res = 0;
	if (inFibo[k])
		res = a[u];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa[u]) continue;
		res += getsum(v, k + 1);
	}
	return res;
}

signed main() {
	freopen("tree.in", "r", stdin), freopen("tree.out", "w", stdout);
	FastIO;

	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adde(u, v), adde(v, u);
	}

	GetFibonacci(n);
	dfs(1, 0);

	for (int i = 1; i <= m; ++i) {
		int opt, x;
		cin >> opt >> x;
		if (opt == 1) {
			int val;
			cin >> val;
			add(x, val, 0);
		}
		if (opt == 2)
			cout << getsum(x, 0) << endl;
	}

	return 0;
}
