#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 6e4 + 5, K = 5005;
const int dire[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
int n, m, k, q, cnt;
int ng[K][K];
std::vector<std::vector<bool>> vis;
std::vector<std::vector<int>> g, rec, nfa;

std::vector<std::vector<std::pair<int, int>>> fa;

std::pair<int, int> getfa(std::pair<int, int> x) {
    auto &fax = fa[x.first][x.second];
    if (fax == x)
        return x;
    else {
        fax = getfa(fax);
        return fax;
    }
}
inline void merge(int x1, int y1, int x2, int y2) {
    auto fa1 = getfa(std::make_pair(x1, y1)), fa2 = getfa(std::make_pair(x2, y2));
    if (fa1 == fa2) return;
    fa[fa1.first][fa1.second] = fa2;
}

std::queue<std::pair<int, int>> Q;
void bfs(int _x, int _y) {
    Q.emplace(_x, _y);
    vis[_x][_y] = true;
    for (; !Q.empty();) {
        auto x0 = Q.front().first, y0 = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = x0 + dire[i][0], y = y0 + dire[i][1];
            if (x > n || x < 1 || y > m || y < 1) continue;
            if (vis[x][y] || !g[x][y]) continue;
            vis[x][y] = true, Q.emplace(x, y);
            merge(x, y, x0, y0);
        }
    }
}

struct Query {
    int x1, y1, x2, y2;
};
std::vector<Query> cache;

signed main() {
#ifndef DEBUG
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k >> q;
    g.resize(n + 5, std::vector<int>(m + 5));
    rec.resize(n + 5, std::vector<int>(m + 5));
    vis.resize(n + 5, std::vector<bool>(m + 5));
    nfa.resize(n + 5, std::vector<int>(m + 5));
    fa.resize(n + 5, std::vector<std::pair<int, int>>(m + 5));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fa[i][j] = std::make_pair(i, j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            static char ch;
            cin >> ch;
            g[i][j] = (ch == '.');
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!vis[i][j] && g[i][j]) bfs(i, j);

    for (int i = 1, x1, y1, x2, y2; i <= k; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        g[x1][y1] = g[x2][y2] = 2;
        cache.push_back({x1, y1, x2, y2});
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j] == 2) {
                int x = fa[i][j].first, y = fa[i][j].second;
                if (!rec[x][y]) rec[x][y] = ++cnt;
                nfa[i][j] = rec[x][y];
            }
    int cntavai = cnt;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (g[i][j] == 1) {
                int x = fa[i][j].first, y = fa[i][j].second;
                if (!rec[x][y]) rec[x][y] = ++cnt;
                nfa[i][j] = rec[x][y];
            }

    for (auto v : cache) {
        if (nfa[v.x1][v.y1] == nfa[v.x2][v.y2]) continue;
        assert(nfa[v.x1][v.y1] <= cntavai);
        ng[nfa[v.x1][v.y1]][nfa[v.x2][v.y2]] = true;
    }

    for (int k = 1; k <= cntavai; ++k)
        for (int i = 1; i <= cntavai; ++i)
            for (int j = 1; j <= cntavai; ++j)
                ng[i][j] |= ng[i][k] & ng[k][j];


    for (int x1, y1, x2, y2; q--;) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (nfa[x1][y1] == nfa[x2][y2] || ng[nfa[x1][y1]][nfa[x2][y2]])
            cout << "1\n";
        else
            cout << "0\n";
    }

#ifdef DEBUG
    for (int i = 1; i <= n; ++i, cerr << '\n')
        for (int j = 1; j <= m; ++j)
            cerr << " (" << fa[i][j].first << ", " << fa[i][j].second << ")";
    cerr << '\n';
    for (int i = 1; i <= n; ++i, cerr << '\n')
        for (int j = 1; j <= m; ++j)
            cerr << nfa[i][j] << ' ';
#endif
    return 0;
}

/*
4 4 2 1
.#..
##..
#...
...#
1 1 1 3
4 1 4 2
4 1 3 2

1
*/
