/**
 * File              : LOJ144.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/20/2021
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
const int N = 1e6 + 5;
std::vector<int> g[N];
int n, q, root, a[N];

struct Node {
    int val, son, fa, top, size, dfn;
} p[N];
void dfs1(int u, int fa = 0) {
    p[u].fa = fa, p[u].size = 1, p[u].son = 0;
    int max = -inf;
    for (auto v : g[u]) {
        if (v == p[u].fa) continue;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (p[v].size > max) max = p[v].size, p[u].son = v;
    }
}
int dfnCounter = 0;
void dfs2(int u, int top) {
    p[u].top = top, p[u].dfn = ++dfnCounter;
    a[dfnCounter] = p[u].val;
    if (!p[u].son) return;
    dfs2(p[u].son, top);
    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;
        dfs2(v, v);
    }
}

struct SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define int long long
   protected:
    int val[N << 2];
    inline void pushUp(int k) { val[k] = val[lson] + val[rson]; }
    inline void pushDown(int l, int r, int k) {}  // seems nothing to do...

   public:
    void build(int l = 1, int r = n, int k = 1) {
        if (l >= r) {
            val[k] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(k);
    }
    void modify(int pos, int num, int l = 1, int r = n, int k = 1) {
        if (pos == l && pos == r) {
            val[k] += num;
            return;
        }
        pushDown(l, r, k);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(pos, num, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, num, mid + 1, r, rson);
        pushUp(k);
    }
    int query(int L, int R, int l = 1, int r = n, int k = 1) {
        if (L <= l && r <= R) return val[k];
        pushDown(l, r, k);
        int mid = (l + r) >> 1, res = 0;
        if (L <= mid) res += query(L, R, l, mid, lson);
        if (mid + 1 <= R) res += query(L, R, mid + 1, r, rson);
        return res;
    }
#undef lson
#undef rson
#undef int
} T;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q >> root;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].val;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs1(root);
    dfs2(root, root);
    T.build();
#ifdef DEBUG
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].dfn << ' ';
    cerr << endl;
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].top << ' ';
    cerr << endl;
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].son << ' ';
    cerr << endl;
#endif
    for (int opt, u, val; q--;) {
        cin >> opt >> u;
        if (opt == 1) {
            cin >> val;
            T.modify(p[u].dfn, val);
        } else if (opt == 2) {
            cout << T.query(p[u].dfn, p[u].dfn + p[u].size - 1) << endl;
        } else
            assert(false);
    }
    return 0;
}