#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using pii = std::pair<int, int>;

const int N = 1005, M = 1e5 + 5;
int n, m, q;

class SegmentTree {
#define lson (p << 1)
#define rson (p << 1 | 1)
#define mid ((l + r) >> 1)
    int n;
    struct Node {
        std::set<pii> edge;
        Node operator+(const Node &Other) const {
            Node res;
            int cnt = 0;
            res.edge.resize(this->edge.size() + Other.edge.size());
            for (auto e : this->edge) res.edge[cnt++] = e;
            for (auto e : Other.edge) res.edge[cnt++] = e;
            return res;
        }
        Node merge(Node &Other) {
            Node res;
        }
    } w[M << 2];
    inline void pushUp(int p) { w[p] = w[lson] + w[rson]; }
    void modify(int pos, pii edge, int l, int r, int p) {
        if (pos == l && pos == r) {
            w[p].edge.push_back(edge);
            w[p].edge.emplace_back(edge.second, edge.first);  // swap
            return;
        }
        if (pos <= mid) modify(pos, edge, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, edge, mid + 1, r, rson);
        pushUp(p);
    }
    void sort(int l, int r, int p) {
        std::sort(w[p].edge.begin(), w[p].edge.end());
        auto len = std::unique(w[p].edge.begin(), w[p].edge.end()) - w[p].edge.begin();
        w[p].edge.resize(len);
        if (l == r) return;
        sort(l, mid, lson), sort(mid + 1, r, rson);
    }
    Node query(int L, int R, int l, int r, int p) {
        if (L <= l && r <= R) return w[p];
        if (L <= mid && mid + 1 <= R) return query(L, R, l, mid, lson).merge(query(L, R, mid + 1, r, rson));
        if (L <= mid) return query(L, R, l, mid, lson);
        if (mid + 1 <= R) return query(L, R, mid + 1, r, rson);
    }

   public:
    inline void resize(int _n) { n = _n; }
    inline void modify(int pos, pii edge) { modify(pos, edge, 1, n, 1); }
    inline void sort() { sort(1, n, 1); }
    void query(int l, int r, int s, int t) {
        
    }
#undef lson
#undef rson
#undef mid
} T;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> q;
    T.resize(m);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        T.modify(i, {u, v});
    }
    T.sort();
    for (int i = 1, l, r, s, t; i <= m; ++i) {
        cin >> l >> r >> s >> t;
        cout << T.query(l, r, s, t);
    }

    return 0;
}
