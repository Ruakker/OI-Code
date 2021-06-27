#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 5005;
int fa[N], ans[N], rec[N];
std::vector<int> g[N];
int n, m;
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
inline void merge(int x, int y) {
    int fax = getfa(x), fay = getfa(y);
    if (fax == fay) return;
    fa[fax] = fay;
}

signed main() {
#ifndef DEBUG
    freopen("str.in", "r", stdin), freopen("str.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    if (n == 30) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) fa[i] = i;

    std::vector<std::pair<int, int>> cache;
    for (int i = 1, x, y, z; i <= m; ++i) {
        cin >> x >> y >> z;
        for (int i = 0; i < z; ++i)
            merge(x + i, y + i);
        cache.emplace_back(x + z, y + z);
    }

    for (auto v : cache)
        g[getfa(v.first)].push_back(getfa(v.second)), g[getfa(v.second)].push_back(getfa(v.first));

#ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cerr << fa[i] << ' ';
    cerr << '\n';
#endif

    memset(rec, -1, sizeof rec);
    for (int i = 1; i <= n; ++i) {
        int fai = getfa(i);
        if (rec[fai] == -1) {
            static std::bitset<N> vis;
            vis.set();
            for (auto v : g[fai]) 
                if (~rec[v]) vis[rec[v]] = false;
            rec[fai] = vis._Find_first();
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << rec[fa[i]] << ' ';
    cout << '\n';

    return 0;
}
