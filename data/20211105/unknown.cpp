#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define int long long

const int N = 2e5 + 5;

int n, m, ans;
std::vector<int> g[N];
std::set<std::pair<int, int>> edges;
int tag[N], dgr[N];

signed main() {
#ifndef DEBUG
    freopen("unknown.in", "r", stdin), freopen("unknown.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    int t = 0;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v; if (u > v) std::swap(u,v);
        if (edges.find(std::make_pair(u, v)) != edges.end()) {
            ++t;
            continue;
        }
        edges.emplace(u, v);
        ++dgr[u], ++dgr[v];
        g[u].push_back(v), g[v].push_back(u);
    }
    m -= t;

    for (int u = 1; u <= n; ++u) {
        for (auto v : g[u]) tag[v] = u;
        for (auto v : g[u])
            for (auto w : g[v])
                if (tag[w] == u) ++ans;
    }

    ans = n * (n - 1) * (n - 2) / 6 - m * (n - 2) - ans / 6;
    for (int i = 1; i <= n; ++i)
        ans += dgr[i] * (dgr[i] - 1) / 2;
    cout << ans << '\n';
    return 0;
}
