/**
 * File              : three.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/29/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
std::vector<std::vector<int>> g, t;  // graph & tree
struct info {
    info() { col = false, dgr = 0, ans = 0; }
    int dgr;
    bool col;  // color: 0/1
    char ans;
};
std::vector<info> p;
std::vector<bool> vis;
std::vector<int> col[2], leaves;
int n, m;

void getTree(int u) {
    vis[u] = true;
    col[p[u].col].emplace_back(u);
    for (auto v : g[u]) {
        if (vis[v]) continue;
        t[u].emplace_back(v), t[v].emplace_back(u);
        ++p[u].dgr, ++p[v].dgr;
        p[v].col = p[u].col ^ true;
        getTree(v);
    }
}
bool cmp(const int &a, const int &b) { return p[a].dgr > p[b].dgr; }
inline bool solve1() {
    std::sort(col[0].begin(), col[0].end(), cmp);  // Descending
    int k = n / 3, sum = 0;
    for (int i = 0; i < k; ++i)
        p[col[0][i]].ans = 'R', sum += p[col[0][i]].dgr;
    if (sum >= n) return false;
    for (unsigned i = k; i < col[0].size(); ++i) {
        p[col[0][i]].ans = 'B';
        for (auto v : t[col[0][i]]) {
            assert(p[v].col == 1);
            p[v].ans = 'B';
        }
    }
    for (int i = 1; i <= n; ++i)
        if (p[i].ans == 0) p[i].ans = 'G';
    int cntR = 0, cntG = 0, cntB = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i].ans == 'R') ++cntR;
        if (p[i].ans == 'G') ++cntB;
        if (p[i].ans == 'B') ++cntG;
    }
    if (cntR == cntG && cntB == cntG) return true;
#ifdef DEBUG
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].ans;
    cerr << endl;
#endif
    return false;
}

void getLeaf(int u, int fa = -1) {
    if (t[u].size() == 1 && p[u].col == true) leaves.emplace_back(u);
    for (auto v : t[u]) {
        if (v == fa) continue;
        getLeaf(v);
    }
}
inline bool solve2() {
    getLeaf(1);
    for (auto ele : leaves)
        p[ele].ans = 'R';
    for (auto ele : col[0])
        if (p[ele].ans == 0) p[ele].ans = 'G';
    for (auto ele : col[1])
        if (p[ele].ans == 0) p[ele].ans = 'B';
    return true;
}

inline void init(int n) {
    g.clear(), t.clear(), p.clear(), vis.clear(), leaves.clear();
    col[0].clear(), col[1].clear();
    g.resize(n + 5), t.resize(n + 5), p.resize(n + 5), vis.resize(n + 5);
}
signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int T;
    for (cin >> T; T--;) {
        cin >> n >> m;
        init(n);
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        getTree(1);
        if (col[0].size() > col[1].size()) {
            std::swap(col[0], col[1]);
            for (int i = 1; i <= n; ++i)
                p[i].col ^= true;
        }
        if (int(col[0].size()) >= n / 3 && solve1()) {
            for (int i = 1; i <= n; ++i)
                cout << p[i].ans;
            cout << '\n';
        } else if (solve2()) {
            for (int i = 1; i <= n; ++i)
                cout << p[i].ans;
            cout << '\n';
        } else
            cout << -1 << '\n';
    }
    return 0;
}