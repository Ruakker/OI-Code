/**
 * File              : reform.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/22/2021
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
const int N = 5e5 + 5;
std::vector<std::vector<int>> g;
std::bitset<N> ans;
int n;
struct Node {
    int size, sonSize, fa;
    /**
     * size: 包含其自身子树大小
     * sonSize: 最大子树（不包含其本身）
     * fa: 父亲
     */
} p[N];
void dfs(int u, int fa = 0) {
    p[u].fa = fa, p[u].sonSize = 0, p[u].size = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        p[u].size += p[v].size;
        if (p[u].sonSize < p[v].size) p[u].sonSize = p[v].size;
    }
    if (p[u].sonSize < n - p[u].size) p[u].sonSize = n - p[u].size;
    if (p[u].sonSize <= n >> 1) ans.set(u);
}
signed main() {
    // freopen("reform.in", "r", stdin), freopen("reform.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        g.clear();
        ans.reset();
        cin >> n;
        g.resize(n + 5);
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        dfs(1);
    }
    return 0;
}