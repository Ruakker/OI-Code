#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define inf 0x3f3f3f3f
#define int long long

const int N = 5.5e5 + 5, z = 22;

std::vector<int> g[N];
int n, cur;
int ans[N], bag[1 << z];
struct info {
    int size, son, fa, depth, l, r;
    size_t w;
    char ch;
} p[N];
int bel[N], timer;

void pre_dfs(int u, int pre) {
    p[u].depth = p[pre].depth + 1, p[u].fa = pre, p[u].size = 1, p[u].l = p[u].r = ++timer;
    if (u != pre) p[u].w = p[pre].w ^ 1 << (p[u].ch - 'a');
    bel[p[u].l] = u;
    for (auto v : g[u]) {
        if (v == pre) continue;
        pre_dfs(v, u);
        p[u].size += p[v].size, p[u].r = std::max(p[u].r, p[v].r);
        if (!p[u].son || p[v].size > p[p[u].son].size) p[u].son = v;
    }
}

void dfs(int u, bool keep) {
    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;
        dfs(v, 1);
        ans[u] = std::max(ans[u], ans[v]);
    }

    if (p[u].son) {
        dfs(p[u].son, false);
        ans[u] = std::max(ans[u], ans[p[u].son]);
    }

    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;

        for (int k = p[v].l; k <= p[v].r; k++) {
            int x = bel[k];
            cur = std::max(cur, p[x].depth + bag[p[x].w] - 2 * p[u].depth);
            for (int i = 0; i < z; i++)
                cur = std::max(cur, p[x].depth + bag[p[x].w ^ (1 << i)] - 2 * p[u].depth);
        }
        for (int k = p[v].l; k <= p[v].r; k++)
            bag[p[bel[k]].w] = std::max(bag[p[bel[k]].w], p[bel[k]].depth);
    }

    cur = std::max(cur, bag[p[u].w] - p[u].depth);

    for (int i = 0; i < z; i++)
        cur = std::max(cur, bag[p[u].w ^ (1 << i)] - p[u].depth);

    bag[p[u].w] = std::max(bag[p[u].w], p[u].depth);
    ans[u] = std::max(ans[u], cur);

    if (keep) {
        for (int k = p[u].l; k <= p[u].r; k++) bag[p[bel[k]].w] = -inf;
        cur = 0;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 2, u; i <= n; i++) {
        cin >> u >> p[i].ch;
        g[u].push_back(i), g[i].push_back(u);
    }

    for (int i = 0; i < 1 << z; ++i) bag[i] = -inf;

    pre_dfs(1, 1);
    dfs(1, false);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
