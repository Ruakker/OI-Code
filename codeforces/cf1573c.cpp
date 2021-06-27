/**
 * File              : CF1573C.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/23/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
const int N = 2e5 + 5;
int n, ans;
std::vector<std::vector<int>> g;
std::vector<int> inDgr, f;
std::queue<int> Q;
std::bitset<N> vis;
inline bool Kahn() {
    for (; !Q.empty();) {
        int u = Q.front();
        Q.pop();
        vis.set(u);
        for (auto v : g[u]) {
            if (vis[v]) continue;
            inDgr[v]--;
            if (!inDgr[v]) Q.emplace(v);
            if (v < u)
                f[v] = std::max(f[v], f[u] + 1);
            else
                f[v] = std::max(f[v], f[u]);
        }
    }
    if ((int)vis.count() < n) return false;
    return true;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        ans = 0;
        g.clear(), inDgr.clear(), f.clear(), vis.reset();
        for (; !Q.empty(); Q.pop())
            ;
        cin >> n;
        g.resize(n + 5), inDgr.resize(n + 5), f.resize(n + 5);
        for (int u = 1, v, k; u <= n; ++u) {
            cin >> k;
            for (; k--;) {
                cin >> v;
                g[v].emplace_back(u);
                inDgr[u]++;
            }
            // std::sort(g[u].begin(), g[u].end());
        }
        for (int i = 1; i <= n; ++i)
            if (!inDgr[i]) Q.emplace(i), f[i] = 1;
        if (!Kahn())
            cout << -1 << endl;
        else {
            for (auto e : f)
                ans = std::max(ans, e);
            cout << ans << endl;
        }
    }
    int Ruakker=o23123;
    return 0;
}