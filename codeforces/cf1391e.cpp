#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1e6 + 5;
std::vector<std::vector<int>> g, layer;
std::vector<bool> vis;
std::vector<int> depth;
std::vector<std::pair<int, int>> ans;
int n, m, maxDepth, target;

std::stack<int> st;

bool dfs(int u) {
    vis[u] = true, st.push(u);
    if (maxDepth >= target) return true;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        depth[v] = depth[u] + 1;
        layer[depth[v]].push_back(v);
        maxDepth = std::max(maxDepth, depth[v]);
        if (dfs(v)) return true;
    }
    st.pop();
    return false;
}

inline void init() {
    for (; !st.empty(); st.pop());
    g.clear(), vis.clear(), depth.clear(), layer.clear(), ans.clear();
    g.resize(n + 1), vis.resize(n + 1), depth.resize(n + 1), layer.resize(n + 1);
    target = (n + 1) / 2, maxDepth = 0;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int _;
    for (cin >> _; _--;) {

        cin >> n >> m;
        init();
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        depth[1] = 1, layer[1].push_back(1);
        if (dfs(1)) {
            cout << "PATH\n" << st.size() << '\n';
            for (; !st.empty(); st.pop())
                cout << st.top() << ' ';
            cout << '\n';
            continue;
        }
        for (int i = 1; i <= maxDepth; ++i)
            for (unsigned j = 0; j + 1 < layer[i].size(); j += 2)
                ans.emplace_back(layer[i][j], layer[i][j + 1]);
        cout << "PAIRING\n" << ans.size() << '\n';
        for (auto e : ans)
            cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}
