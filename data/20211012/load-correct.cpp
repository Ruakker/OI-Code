#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define inf 0x3f3f3f3f
#define int long long

const int N = 2e5 + 5;

int n, m, val[N];
long long ans;
std::vector<std::pair<int, int>> g[N];

class Kruscal {
   private:
    struct Edge {
        Edge(int a, int b, int c) {
            u = a, v = b, val = c;
        }
        int u, v, val;
    };
    std::vector<Edge> e;
    int fa[N], size[N];
    int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
    inline void merge(int u, int v, int val) {
        int fau = getfa(u), fav = getfa(v);
        if (fau == fav) return;
        ans += size[fau] * size[fav] * val;
        fa[fau] = fav, size[fav] += size[fau];
        // ::g[u].emplace_back(v, val), ::g[v].emplace_back(u, val);
#ifdef DEBUG
        cerr << ">>> " << u << ' ' << v << ' ' << val << endl;
#endif
    }

   public:
    void add(int u, int v, int val) { e.emplace_back(u, v, val); }
    void work() {
        for (int i = 1; i <= n; ++i) fa[i] = i, size[i] = 1;
        std::sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.val > b.val; } );
        for (auto cur : e) merge(cur.u, cur.v, cur.val);
    }
} K;  // MAX

signed main() {
#ifndef DEBUG
    freopen("load.in", "r", stdin), freopen("load.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        K.add(u, v, std::min(val[u], val[v]));
    }

    K.work();

    cout << ans << endl;

    return 0;
}
