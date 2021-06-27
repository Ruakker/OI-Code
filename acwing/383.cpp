#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define inf 0x3f3f3f3f
#define fk (cerr << "Fuck\n")

const int N = 55;
int n, m, ans;
bool b[N][N];

class MaxFlow {
    struct Edge {
        int to, limit, flow;
        size_t rev;
    };
    std::vector<std::vector<Edge>> g, g_backup;
    std::vector<int> dis;
    std::vector<std::vector<Edge>::iterator> p;
    int n;
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
    MaxFlow() { n = 0; }
    MaxFlow(int _n, int _m) { n = _n, dis.resize(_n + 1), g.resize(_n + 1), p.resize(_n + 1); }
    ~MaxFlow() { g.clear(), dis.clear(), p.clear(), n = 0; }
    inline void adde(int u, int v, int w) {
        g[u].push_back({v, w, 0, g[v].size()});
        g[v].push_back({u, w, w, g[u].size() - 1});
    }
    int get(int s, int t) {
        int ans = 0;
        g = g_backup;
        for (; bfs(s, t);) ans += dfs(s, t, inf);
        return ans;
    }
    inline void backup() { g_backup = g; }
} G;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    for (; cin >> n >> m;) {
        if (!m) {
            if (n == 1)
                cout << "1\n";
            else
                cout << "0\n";
            continue;
        }
        G = MaxFlow(n * 3, n + m * 3);
        for (int i = 1; i <= n; ++i) G.adde(i, n + i, 1);  // i -> n + i
        for (int i = 1, u, v; i <= m; ++i) {
            char ch;
            cin >> ch >> u >> ch >> v >> ch;
            ++u, ++v;
            b[u][v] = b[v][u] = true;
            G.adde(n + u, v, inf), G.adde(n + v, u, inf);  // (n + u -> v), (n + v -> u)
        }
        G.backup();
        ans = inf;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (b[i][j]) ans = std::min({ans, G.get(i + n, j), G.get(j + n, i)});
        cout << ans << '\n';
    }

    return 0;
}
