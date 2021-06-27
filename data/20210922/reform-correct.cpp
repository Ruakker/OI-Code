/**
 * File              : reform-correct.cpp
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
     * sonSize: 可以切的子树大小（小于 n/2 中最大的）
     * fa: 父亲
     */
} p[N];
void dfs(int u, int fa = 0) {
    p[u].fa = fa, p[u].sonSize = p[u].size = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        p[u].size += p[v].size;
        if (p[u].sonSize < p[v].sonSize) p[u].sonSize = p[v].sonSize;
    }
    if (p[u].size <= n >> 1) p[u].sonSize = std::max(p[u].sonSize, p[u].size);
}
void work(int u, int fa = 0) {
    ans.set(u);
    for (auto v : g[u])
        if (p[v].size > n >> 1 && p[v].size - p[v].sonSize > n >> 1)
            ans.reset(u);
    int max1 = 1, max2 = 1;
    for (auto v : g[u])
        if (p[v].sonSize >= max1)
            max2 = max1, max1 = p[v].sonSize;
        else if (p[v].sonSize > max2)
            max2 = p[v].sonSize;
    for (auto v : g[u]) {
        if (v == fa) continue;
        int tmpU = p[u].sonSize, tmpV = p[v].sonSize;
        p[u].size -= p[v].size;
        p[v].size += p[u].size;
        p[u].sonSize = (p[v].sonSize == max1 ? max2 : max1);
        if (p[u].size <= n >> 1)
            p[u].sonSize = std::max(p[u].sonSize, p[u].size);
        p[v].sonSize = std::max(p[v].sonSize, p[u].sonSize);
        work(v, u);
        p[v].size -= p[u].size;
        p[u].size += p[v].size;
        p[u].sonSize = tmpU, p[v].sonSize = tmpV;
    }
}
signed main() {
    freopen("reform.in", "r", stdin), freopen("reform.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        ans.reset();
        cin >> n;
        g.clear();
        g.resize(n + 5);
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        dfs(1);
        work(1);
        for (int i = 1; i <= n; ++i)
            if (ans[i])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        cout << endl;
    }
    return 0;
}