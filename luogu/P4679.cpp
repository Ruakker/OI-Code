#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define inf 0x3f3f3f3f
const int N = 3e5 + 5;
std::vector<int> g[N];
int n, m;

struct info {
    int top, fa, son, size, dfn, depth;
    bool w[2];
} p[N];

int timer;
bool a[N][2];
void dfs1(int u, int pre) {
    p[u].fa = pre, p[u].size = 1, p[u].depth = p[pre].depth + 1;
    for (auto v : g[u]) {
        if (v == pre) continue;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (!p[u].son || p[p[u].son].size < p[v].size) p[u].son = v;
    }
}
void dfs2(int u, int top) {
    p[u].top = top, p[u].dfn = ++timer;
    a[timer][0] = p[u].w[0], a[timer][1] = p[u].w[1];
    if (p[u].son) dfs2(p[u].son, top);
    for (auto v : g[u]) {
        if (v == p[u].son || v == p[u].fa) continue;
        dfs2(v, v);
    }
}

class SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define mid ((l + r) >> 1)

    struct node {
        node() { clear(); }
        
        node(bool w[]) {
            clear();
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    dis[i][j] = -inf;

            if (w[0] && w[1]) {
                for (int i = 0; i < 2; ++i)
                    lmax[i] = rmax[i] = 2;
                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 2; ++j)
                        dis[i][j] = (i == j ? 1 : 2);
            } else
            if (w[0] || w[1]) {
                int pos = w[1];  // equal to (w[0] ? 0 : 1)
                lmax[pos] = rmax[pos] = 1;
                dis[pos][pos] = 1;
            }
        }

        int lmax[2], rmax[2], dis[2][2];

        node operator+(const node &Other) const {
            node res;
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    res.lmax[i] = std::max({res.lmax[i], this->lmax[i], this->dis[i][j] + Other.lmax[j]});
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    res.rmax[i] = std::max({res.rmax[i], Other.rmax[i], this->rmax[j] + Other.dis[j][i]});

            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j) {
                    res.dis[i][j] = -inf;
                    for (int k = 0; k < 2; ++k)
                        res.dis[i][j] = std::max(res.dis[i][j], this->dis[i][k] + Other.dis[k][j]);
                }
            return res;
        }

        void rev() {
            for (int i = 0; i < 2; ++i)
                std::swap(lmax[i], rmax[i]);
            std::swap(dis[0][1], dis[1][0]);
        }

        void clear() {
            memset(dis, 0, sizeof dis);
            memset(lmax, 0, sizeof lmax);
            memset(rmax, 0, sizeof rmax);
        }
    } t[N << 2];

    int n;

    inline void pushUp(int k) { t[k] = t[lson] + t[rson]; }

    void build(int l, int r, int k) {
        if (l == r) {
            t[k] = node(a[l]);
            return;
        }
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(k);
    }

    void modify(int pos, bool w[], int l, int r, int k) {
        if (pos == l && pos == r) {
            t[k] = node(w);
            return;
        }
        if (pos <= mid) modify(pos, w, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, w, mid + 1, r, rson);
        pushUp(k);
    }

    node query(int L, int R, int l, int r, int k) {
        // cerr << l << ' ' << r << '\n';
        if (L <= l && r <= R) return t[k];
        if (L <= mid && mid + 1 <= R)
            return query(L, R, l, mid, lson) + query(L, R, mid + 1, r, rson);
        if (L <= mid)
            return query(L, R, l, mid, lson);
        if (mid + 1 <= R)
            return query(L, R, mid + 1, r, rson);
        assert(false);
        return node();
    }

   public:
    inline void build(int _n) {
        n = _n;
        build(1, n, 1);
    }

    inline void modify(int u, bool w[]) { modify(p[u].dfn, w, 1, n, 1); }

    inline node query(int l, int r) {
        // cerr << "Querying: " << l << ' ' << r << '\n';
        return query(l, r, 1, n, 1);
    }

    int answer(int u, int v) {
        if (!(p[u].w[0] || p[u].w[1])) return 0;
        node res[2];
        bool status = 0;
        for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
            // cerr << "in the loop" << '\n';
            if (p[p[u].top].depth < p[p[v].top].depth) status ^= 1, std::swap(u, v);
            // cerr << "status: " << status << '\n';
            res[status] = res[status] + query(p[p[u].top].dfn, p[u].dfn);
        }

        // cerr << "out of the loop" << '\n';
        if (p[u].depth > p[v].depth) status ^= 1, std::swap(u, v);
        res[status] = res[status] + query(p[u].dfn, p[v].dfn);

        res[1].rev();
        node ans = res[0] + res[1];
        return std::max(ans.lmax[0], ans.lmax[1]);
    }

#undef lson
#undef rson
#undef mid
} T;


signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        std::string s;
        cin >> s;
        for (int j = 0; j < 2; ++j)
            p[i].w[j] = (s[j] == '.');
    }

    dfs1(1, 0);
    dfs2(1, 1);
    T.build(n);

    for (char opt; m--;) {
        cin >> opt;
        if (opt == 'Q') {
            int u, v;
            cin >> u >> v;
            cout << T.answer(u, v) << '\n';
        }
        if (opt == 'C') {
            int u;
            bool w[2];
            std::string s;
            cin >> u >> s;
            for (int i = 0; i < 2; ++i)
                w[i] = (s[i] == '.');
            T.modify(u, w);
        }
    }

    return 0;
}
