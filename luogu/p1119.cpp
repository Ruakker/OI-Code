/**
 * File              : P1119.cpp
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
const int N = 205, M = 2e4 + 5;
int n, m, t[N];
int g[N][N];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(g, inf, sizeof g);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        assert(t[i] <= n);
        g[i][i] = 0;
    }
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        ++u, ++v;
        g[u][v] = w, g[v][u] = w;
    }
    int q, cnt = 1;
    cin >> q;
    for (int i = 1, u, v, w; i <= q; ++i) {
        cin >> u >> v >> w;
        ++u, ++v;
        for (; cnt <= n && t[cnt] <= w; ++cnt)
            for (int j = 1; j <= n; ++j)
                for (int k = j + 1; k <= n; ++k)
                    if (g[j][k] > g[j][cnt] + g[cnt][k])
                        g[j][k] = g[k][j] = g[j][cnt] + g[cnt][k];
        if (t[u] > w || t[v] > w) {
            cout << -1 << endl;
            continue;
        }
        if (g[u][v] == inf)
            cout << -1 << endl;
        else
            cout << g[u][v] << endl;
    }
    return 0;
}