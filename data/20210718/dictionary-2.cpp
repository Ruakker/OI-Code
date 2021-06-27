/*
	Author: Ruakker
	Date: 2021-07-18 13:03:08
	LastEditTime: 2021-07-18 13:18:39
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
const int N = 1e5 + 5;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
int n, m, inDgr[N];
std::priority_queue<int> Q;
std::vector<int> ans;
inline void topo() {
	for (int i = 1; i <= n; ++i)
		if (!inDgr[i]) Q.push(i);
	for (; !Q.empty();) {
		int u = Q.top();
		Q.pop(), ans.push_back(u);
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (!(--inDgr[v])) Q.push(v);
		}
	}
}

bool MEMED;
signed main() {
	fre(dictionary);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adde(v, u), ++inDgr[u];
	}
	topo();
	if (ans.size() < n) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
