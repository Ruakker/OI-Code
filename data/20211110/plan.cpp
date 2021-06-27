#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using pii = std::pair<int, int>;

const int N = 1005, M = 1e5 + 5;
int n, m, q;
pii edge[M];

class SegmentTree {
#define lson (p << 1)
#define rson (p << 1 | 1)
#define mid ((l + r) >> 1)
    int n;
    std::vector<int> cache[N];
    struct Node {
        std::vector<pii> edge;
        Node operator+(const Node &Other) const {
            Node res;
            int cnt = 0;
            res.resize(this->edge.size() + Other.edge.size());
            for (auto e : this->edge) res.edge[cnt++] = e;
            for (auto e : Other.edge) res.edge[cnt++] = e;
            return res;
        }
    } w[M << 2];
    Node merge(const Node &a, const Node &b) {
        Node res;
        for (auto e : a.edge) cache[e.second].push_back(e.first);
        for (auto e : b.edge)
            for (auto v : cache[e.first])
                res.edge.emplace_back(v, e.second);
        for (auto e : a.edge) cache[e.second].clear();
        return res;
    }
    inline void pushUp(int p) { w[p] = w[lson] + w[rson]; }
    void sort(int l, int r, int p) {
        std::sort(w[p].edge.begin(), w[p].edge.end());
        auto len = std::unique(w[p].edge.begin(), w[p].edge.end()) - w[p].edge.begin();
        w[p].edge.resize(len);
        if (l == r) return;
        sort(l, mid, lson), sort(mid + 1, r, rson);
    }
    void build(int l, int r, int p) {
        if (l == r) {
            w[p].edge.push_back(::edge[l]);
            w[p].edge.emplace_back(::edge[l].second, ::edge[l].first);
            return;
        }
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(p);
    }
    Node query(int L, int R, int l, int r, int p) {
        if (L <= l && r <= R) return w[p];
        if (L <= mid && mid + 1 <= R) return merge(query(L, R, l, mid, lson), query(L, R, mid + 1, r, rson));
        if (L <= mid) return query(L, R, l, mid, lson);
        else return query(L, R, mid + 1, r, rson);
    }

   public:
    inline void resize(int _n) { n = _n; }
    inline void build() { build(1, n, 1); }
    inline void sort() { sort(1, n, 1); }
    bool query(int l, int r, int s, int t) {
        auto res = query(l, r, 1, n, 1);
        if (res.edge.find({s, t}) == res.edge.end()) return false;
        return true;
    }
#undef lson
#undef rson
#undef mid
} T;

signed main() {
#ifndef DEBUG
    freopen("plan.in", "r", stdin);
    freopen("plan.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> q;
    T.resize(m);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        edge[i] = {u, v};
    }
    T.build();
    T.sort();
    for (int i = 1, l, r, s, t; i <= q; ++i) {
        cin >> l >> r >> s >> t;
        cout << (T.query(l, r, s, t) ? "Yes\n" : "No\n");
        // cout.flush();
    }

    return 0;
}

/*
3 3 6
2 3
1 2
3 1
1 2 1 3
1 3 1 3
3 3 3 1
3 3 3 2
2 3 2 3
2 3 3 2

No
Yes
Yes
No
Yes
No
*/
