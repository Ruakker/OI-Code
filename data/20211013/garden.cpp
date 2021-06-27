#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define int long long
const int N = 2e6 + 5;
struct Edge {
    Edge() {}
    Edge(int a, int b, int c) { to = a, dis = b, val = c; }
    int to, dis, val;
};
std::vector<Edge> g[N];
int n, m, q;
bool vis[N][20];
long long ans[N][20];

std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> Q;  // min-heap

void dijkstra(int st) {
    memset(ans, 0x3f, sizeof ans);
    ans[1][q] = 0;
    Q.emplace(0, std::make_pair(st, q));
    for (; !Q.empty();) {
        int u = Q.top().second.first, sumVal = Q.top().second.second;
        Q.pop();
        if (vis[u][sumVal]) continue;
        vis[u][sumVal] = true;
        for (auto e : g[u]) {
            int v = e.to, val = e.val, dis = e.dis;
            if (sumVal - val >= 0 && ans[v][sumVal - val] > ans[u][sumVal] + dis) {
                ans[v][sumVal - val] = ans[u][sumVal] + dis;
                Q.emplace(ans[v][sumVal - val], std::make_pair(v, sumVal - val));
            }
        }
    }
}

signed main() {
#ifndef DEBUG
    freopen("garden.in", "r", stdin), freopen("garden.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1, u, v, dis, val; i <= m; ++i) {
        cin >> u >> v >> dis >> val;
        if (u == v) continue;
        g[u].emplace_back(v, dis, val), g[v].emplace_back(u, dis, val);
    }

    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        long long tmp = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j <= q; ++j)
            tmp = std::min(tmp, ans[i][j]);
        cout << ((tmp == 0x3f3f3f3f3f3f3f3fll) ? -1 : tmp) << ' ';
    }
    cout << endl;

    return 0;
}
