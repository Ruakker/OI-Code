#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define int long long
#define inf 0x3f3f3f3f3f3f3f3fLL
const int N = 5005;
int n, m, s, t;

class MaxFlow {
    struct Edge {
        int to, limit, flow;
        size_t rev;
    };
    std::vector<std::vector<Edge>> g;
    std::vector<int> dis;
    std::vector<std::vector<Edge>::iterator> p;
    int n, m;
    bool bfs(int s, int t) {
        std::fill(dis.begin(), dis.end(), 0);
        for (int i = 1; i <= n; ++i)
            p[i] = g[i].begin();
        static std::queue<int> Q;
        for (; !Q.empty(); Q.pop());
        Q.push(s), dis[s] = 1;
        for (; !Q.empty();) {
            int u = Q.front();
            Q.pop();
            for (auto e : g[u]) {
                int v = e.to;
                if (dis[v] || e.limit <= e.flow) continue;
                dis[v] = dis[u] + 1, Q.push(v);
            }
        }
        return dis[t];
    }
    int dfs(int u, int t, int curflow) {
        if (u == t || !curflow) return curflow;
        int rest = curflow, c;
        for (auto iter = p[u]; iter != g[u].end() && rest; ++iter) {
            int v = iter->to, limit = iter->limit, *flow = &iter->flow;
            p[u] = iter;
            if (limit <= *flow || dis[v] != dis[u] + 1) continue;
            c = dfs(v, t, std::min(rest, limit - *flow));
            if (!c) dis[v] = 0;
            *flow += c;
            g[v][iter->rev].flow -= c;
            rest -= c;
        }
        return curflow - rest;
    }

   public:
    MaxFlow() { n = m = 0; }
    MaxFlow(int _n, int _m) { n = _n, m = _m, dis.resize(_n + 1), g.resize(_n + 1), p.resize(_n + 1); }
    ~MaxFlow() { g.clear(), dis.clear(), p.clear(), n = m = 0; }
    inline void adde(int u, int v, int w) {
        g[u].push_back({v, w, 0, g[v].size()});
        g[v].push_back({u, w, w, g[u].size() - 1});
    }
    inline int get(int s, int t) {
        int ans = 0;
        for (; bfs(s, t);) ans += dfs(s, t, inf);
        return ans;
    }
} G;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    G = MaxFlow(n, m);
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        G.adde(u, v, w);
    }
    cout << G.get(s, t) << '\n';
    return 0;
}
