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

int n, m;
long long ans;
std::vector<std::pair<int, int>> g[N];

struct Info {
    int val, size, sonSize;  // sonSize means the max son-tree of this node.
}p[N];

class Kruscal {
   private:
    struct Edge {
        Edge(int a, int b, int c) {
            u = a, v = b, val = c;
        }
        int u, v, val;
    };
    std::vector<Edge> e;
    int fa[N];
    int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
    inline void merge(int u, int v, int val) {
        int fau = getfa(u), fav = getfa(v);
        if (fau == fav) return;
        fa[fau] = fav;
        ::g[u].emplace_back(v, val), ::g[v].emplace_back(u, val);
#ifdef DEBUG
        cerr << ">>> " << u << ' ' << v << ' ' << val << endl;
#endif
    }

   public:
    void add(int u, int v, int val) { e.emplace_back(u, v, val); }
    void work() {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        std::sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.val > b.val; } );
        for (auto cur : e) merge(cur.u, cur.v, cur.val);
    }
} K;  // MAX

const int M = 1e6;
class Fenwick {
   private:
    inline int lowbit(int x) { return x & -x; }
    int val[M + 5];
   public:
    void add(int x) {
        for (; x <= M; x += lowbit(x)) 
            val[x]++;
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x))
            res += val[x];
        return res;
    }
    void clear() {
        memset(val, 0, sizeof val);
    }
} T;

void disc(std::vector<int> &a, std::vector<int> &b) {
    std::vector<int> disc = a;
    for (auto cur : b) disc.emplace_back(cur);
    std::sort(disc.begin(), disc.end());
    auto ed = std::unique(disc.begin(), disc.end());
    for (unsigned i = 0; i < a.size(); ++i)
        a[i] = std::lower_bound(disc.begin(), ed, a[i]) - disc.begin() + 1;
    for (unsigned i = 0; i < b.size(); ++i)
        b[i] = std::lower_bound(disc.begin(), ed, b[i]) - disc.begin() + 1;
}

// DFZ start

int sum, root;
bool vis[N];
int dist[N];
std::vector<int> rec, st;
std::queue<int> changed;

void calcsize(int u, int pre) {
    p[u].size = 1, p[u].sonSize = 0;
    for (auto e : g[u]) {
        auto v = e.first;
        if (v == pre || vis[v]) continue;
        calcsize(v, u);
        p[u].size += p[v].size;
        p[u].sonSize = std::max(p[u].sonSize, p[v].size);
    }
    p[u].sonSize = std::max(p[u].sonSize, sum - p[u].size);
    if (p[u].sonSize < p[root].sonSize) root = u;
}

void calcdist(int u, int pre) {
    for (auto e : g[u]) {
        auto v = e.first, val = e.second;
        if (v == pre || vis[v]) continue;

        dist[v] = std::min(dist[u], val), changed.emplace(v);
        st.emplace_back(dist[v]);
        calcdist(v, u);
    }
}

void dfz(int u, int pre) {
    // cerr << u << endl;
    vis[u] = true;
    for (auto e : g[u]) {
        auto v = e.first, val = e.second;
        if (v == pre || vis[v]) continue;

        dist[v] = val, changed.emplace(v);
        st.emplace_back(dist[v]);
        calcdist(v, u);

        for (auto cur : st) ans += cur;

        if (rec.size() > 0) {
            std::vector<int> rec2 = rec, st2 = st, sum = rec;

            std::sort(sum.begin(), sum.end());
            for (unsigned i = 1; i < sum.size(); ++i) 
                sum[i] += sum[i - 1];


            disc(rec2, st2);

            for (auto cur : rec2) T.add(cur);
            for (unsigned i = 0; i < st.size(); ++i) {
                int rnk = T.query(st2[i] - 1);
                ans += (rnk == 0 ? 0 : sum.at(rnk - 1)) + (rec.size() - rnk) * st[i];
            }
        }

        for (auto cur : st) rec.emplace_back(cur);
        st.clear(), T.clear();
    }
    rec.clear();
    for (; !changed.empty(); changed.pop()) dist[changed.front()] = 0;

    for (auto e : g[u]) {
        auto v = e.first;
        if (v == pre || vis[v]) continue;

        sum = p[v].size, root = 0, p[root].sonSize = inf;
        calcsize(v, u);
        calcsize(root, -1);
        assert(root);
        dfz(root, u);
    }
}

// DFZ end

signed main() {
#ifndef DEBUG
    freopen("load.in", "r", stdin), freopen("load.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].val;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        K.add(u, v, std::min(p[u].val, p[v].val));
    }

    K.work();

    sum = n, root = 0, p[0].sonSize = inf;

    calcsize(1, -1);
    calcsize(root, -1);
    dfz(root, -1);

    cout << ans << endl;

    return 0;
}
