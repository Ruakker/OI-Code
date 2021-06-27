/*
	Author: Ruakker
	Date: 2021-07-21 07:36:04
	LastEditTime: 2021-07-21 11:28:08
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

const int N = 3e5 + 5;
struct Edge {
	int nxt, to, val;
} e[N];
int tote = 1, head[N];
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
int n, m, Ans, ans[N];
std::bitset<N> inStack;

void dfs(int u, int last, int len) {
	ans[u] = std::max(len, ans[u]);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to, val = e[i].val;
		if (inStack[i]) continue;
		if (val > last) {
			inStack[i] = 1;
			dfs(v, val, len + 1);
			inStack[i] = 0;
		}
	}
}

bool MEMED;
signed main() {
	fre(graph);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adde(u, v, w);
	}
	for (int i = 1; i <= n; ++i)
		adde(0, i, 0);

	dfs(0, -1, -1);
	for (int i = 1; i <= n; ++i)
		Ans = std::max(Ans, ans[i]);
	cout << Ans << '\n';
#ifdef DEBUG
	for (int i = 1; i <= n; ++i)
		cerr << ans[i] << ' ';
	cerr << '\n';
#endif
	cout.flush();

	return 0;
}
