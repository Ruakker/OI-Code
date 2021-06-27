/*
	Author: Ruakker
	Date: 2021-07-18 07:46:55
	LastEditTime: 2021-07-18 10:31:54
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
bool MEMST;
// #define DEBUG

const int N = 1005;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
int n, m, rt, inDgr[N];
std::bitset<N> vis, inStack;
bool added[N][N];
bool dfs(int u) {
	vis[u] = 1;
	if (inStack[u]) return 0;
	inStack[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (inStack[v]) return 0;
		if (vis[v]) continue;
		if (!dfs(v)) return 0;
	}
	inStack[u] = 0;
	return 1;
}
std::stack<int> st;
std::vector<int> ans;
bool findAns(int u, int k) {
	inStack[u] = 1;
	st.push(u);
	if (k == n) {
		for (; !st.empty(); st.pop())
			ans.push_back(st.top());
		for (int i = ans.size() - 1; i >= 0; --i)
			cout << ans[i] << ' ';
		cout << endl;
		return 1;
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (inStack[v]) continue;
		if (findAns(v, k + 1)) return 1;
	}
	st.pop();
	inStack[u] = 0;
	return 0;
}

bool MEMED;
signed main() {
	fre(dictionary);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif

	memset(added, 0, sizeof added);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		++inDgr[v];
		adde(u, v);
		added[u][v] = added[v][u] = 1;
	}

	vis.reset(), inStack.reset();
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		inStack.reset();
		if (!dfs(i)) {
			cout << "-1" << endl;
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i)
		if (!inDgr[i]) {
			rt = i;
			break;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (!added[i][j]) adde(i, j);

	inStack.reset();
	if (findAns(rt, 1)) return 0;
	cout << "-1" << endl;
	return 0;
}
