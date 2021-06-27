/*
	Author: Ruakker
	Date: 2021-07-23 07:54:16
	LastEditTime: 2021-07-23 20:00:11
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

using std::make_pair;
using std::pair;
typedef pair<int, int> pii;

constexpr int N = 5e4 + 5;
std::vector<int> e[N];
int n, sum, rt, ans;
struct Node {
	int val, sz, sonsz; // sonsz means the max son-tree of this node.
	Node(int a = 1, int b = 0) { this->sz = a, this->sonsz = b; }
} p[N];
void calcsize(int u, int pre) {
	p[u].sz = 1, p[u].sonsz = 0;
	for (auto v : e[u]) {
		if (v == pre) continue;
		calcsize(v, u);
		p[u].sz += p[v].sz;
		p[u].sonsz = std::max(p[u].sonsz, p[v].sz);
	}
	p[u].sonsz = std::max(p[u].sonsz, sum - p[u].sz);
	if (p[u].sonsz < p[rt].sonsz) rt = u;
}
pii st[N], dist[N]; //first: count of nodes on the path; second: min
std::bitset<N> vis;
int cnt;
void calcdist(int u, int pre) {
	st[++cnt] = dist[u];
	for (auto v : e[u]) {
		if (v == pre || vis[v]) continue;
		dist[v].first = dist[u].first + 1;
		dist[v].second = std::min(p[v].val, dist[u].second);
		calcdist(v, u);
	}
}
std::vector<pii> rec;
void dfz(int u, int pre) {
	vis[u] = 1;
	for (auto v : e[u]) {
		if (v == pre || vis[v]) continue;
		dist[v] = make_pair(1, p[v].val);
		calcdist(v, u);
		for (int i = 1; i <= cnt; ++i)
			ans = std::max(st[i].first * st[i].second, ans);
		for (int i = 1; i <= cnt; ++i)
			for (auto cur : rec)
				ans = std::max(ans, (st[i].first + cur.first) * std::min(st[i].second, cur.second));
		for (int i = 1; i <= cnt; ++i)
			rec.emplace_back(st[i]);
		cnt = 0;
	}
	rec.clear();
	for (auto v : e[u]) {
		if (v == pre || vis[v]) continue;
		sum = p[v].sz, rt = 0, p[rt].sonsz = inf;
		calcsize(v, u);
		calcsize(rt, -1);
		dfz(rt, u);
	}
}

bool MEMED;
signed main() {
	// fre(a);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].val;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v), e[v].emplace_back(u);
	}
	sum = n, rt = 0, p[0].sonsz = inf, vis.reset();
	calcsize(1, -1);
	calcsize(rt, -1);

	dfz(rt, -1);
	cout << ans << '\n';
	cout.flush();
	return 0;
}
