/**
 * File              : link.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/22
 * Last Modified Date: 2021/08/22
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
bool MEMST;
#define int long long
constexpr int N = 2e5 + 5, P = 10007;
std::vector<int> g[N];
int n, a[N], ans1 = -inf, ans2 = 0;
std::bitset<N> vis;
std::set<pii> b;
bool flag = 0;
namespace sta {
int st[300005], tp = 0;
inline void push(int x) { st[++tp] = x; }
inline int get() { return st[tp - 2]; }
inline int getSize() { return tp; }
inline void clear() { tp = 0; }
} // namespace sta
inline void work(int u) {
	sta::push(u);
	if (sta::getSize() <= 2) return;
	int v = sta::get();
	if (u > v) std::swap(u, v);
	if (u == v || b.find(make_pair(u, v)) != b.end()) return;
	b.insert(make_pair(u, v));
	ll tmp = 1ll * a[u] * a[v];
	ans1 = std::max(1ll * ans1, tmp);
	(ans2 += tmp) %= P;
#ifdef DEBUG
	cerr << "Point: " << u << ' ' << v << "; Val: " << tmp << endl;
#endif
}
void dfs(int u) {
	if (flag)
		flag = 0;
	else
		vis[u] = 1;
	work(u);
	if (g[u].empty()) return;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
		work(u);
	}
}
bool MEMED;
signed main() {
	fre(link);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	vis.reset();
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			sta::clear(), flag = 1;
			dfs(i);
		}
	cout << ans1 << ' ' << ans2 * 2 << endl;
	cout.flush();
	return 0;
}
