#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 3e5 + 5;
std::vector<int> g[N];
int n, m;
int color[N], con[N];

bool dfs(int u, int pre) {
    color[u] = color[pre] ^ 1;
    for (auto v : g[u]) {
        if (color[v] == color[u] && con[u] != con[v] && con[v] != con[u]) {
            if (!con[u] && !con[v])
                con[u] = v, con[v] = u;
            else
                return false;
        }
        if (~color[v]) continue;
        if (!dfs(v, u)) return false;
    }
    return true;
}

signed main() {
#ifndef DEBUG
    freopen("horse.in", "r", stdin), freopen("horse.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    memset(color, -1, sizeof color);
    color[0] = 0;
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        if (color[i] == -1)
            if (!dfs(i, 0)) {
                flag = false;
                break;
            }
    if (!flag)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; ++i)
            cout << color[i];
        cout << '\n';
    }
    return 0;
}
