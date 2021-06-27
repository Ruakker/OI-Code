#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define inf 0x3f3f3f3f3f3f3f3fll

#define int long long

const int N = 505, M = 250000;
int n, m, root;
int rank[N][N], val[M];
long long ans;
long long dis[N][N];
struct Edge {
    Edge() {}
    Edge(int a, int b, int c) { u = a, v = b, val = c; }
    int u, v, val;
}e[M];

signed main() {
#ifndef DEBUG
    freopen("tree.in", "r", stdin), freopen("tree.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int i = 1, u, v, val; i <= m; ++i) {
        cin >> u >> v >> val;
        val <<= 1;
        dis[u][v] = dis[v][u] = val;
        e[i] = Edge(u, v, val);
    }

    for (int k = 1; k <= n; ++k) // Floyed
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            rank[i][j] = j;  // j-th max point from node i AFTER getting sorted
            val[j] = dis[i][j];  // the distant of edge j from node i
        }
        std::sort(rank[i] + 1, rank[i] + 1 + n, [](int a, int b) { return val[a] < val[b]; });
    }

    long long ans1 = inf, ans2 = inf;
    for (int i = 1; i <= n; ++i)  // the center is point
        ans1 = std::min(ans1, dis[i][rank[i][n]] << 1);

    for (int i = 1; i <= m; ++i) {  // the center is edge
        int u = e[i].u, v = e[i].v, val = e[i].val, p = n; 
        for (int i = n - 1; i; --i)
            if (dis[v][rank[u][i]] > dis[v][rank[u][p]]) {
                ans2 = std::min(ans2, dis[u][rank[u][i]] + dis[v][rank[u][p]] + val);
                p = i;
            }
    }
    cout << (std::min(ans1, ans2) >> 1) << endl;

    return 0;
}
