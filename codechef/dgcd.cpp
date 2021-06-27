/**
 * File              : DGCD.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-15 13:52:54
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fre(fileName) \
    freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
bool MEMST;
const int N = 5e4 + 5;
std::vector<int> g[N];
int n, q;
struct SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)

   protected:
    inline int getGcd(int x, int y) { return (!y) ? x : getGcd(y, x % y); }
    inline int GCD(int x, int y) { return GCD(abs(x), abs(y)); }
    int val[N << 2], gcd[N << 2];
    inline void pushUp(int k) {
        val[k] = val[lson] + val[rson];
        gcd[k] = GCD(gcd[lson], gcd[rson]);
    }
    inline void pushDown(int l, int r, int k) {}  // It seems nothing to do...

   public:
    void build(int *a, int l, int r, int k = 1) {
        if (!n) n = r;
        if (l >= r) {
            val[k] = a[l];
        }
        int mid = (l + r) >> 1;
        build(a, l, mid, lson), build(a, mid + 1, r, rson);
        pushUp(k);
    }
    void modify(int pos, int num, int l = 1, int r = n, int k = 1) {
        if (pos == l && pos == r) {
            val[k] += num;
            gcd[k] += num;
            return;
        }
        pushDown(l, r, k);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(pos, num, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, num, mid + 1, r, rson);
        pushUp(k);
    }
    int query(int L, int R, int l = 1, int r = n, int k = 1) {
        if (L <= l && r <= R) return gcd[k];
        pushDown(l, r, k);
        int mid = (l + r) >> 1, res = 0;
        if (L <= mid) res = query(L, R, l, mid, lson);
        if (mid + 1 <= R) {
            int tmp = query(L, R, mid + 1, r, rson);
            if (!res)
                res = tmp;
            else
                res = GCD(res, tmp);
        }
        return res;
    }

#undef lson
#undef rson
} T;
struct Node {
    int val, diff, size, fa, son, top, dfn;
} p[N];
int bel[N], a[N];
void dfs1(int u, int fa = 0) {
    p[u].fa = fa, p[u].size = 1, p[u].son = 0;
    int max = -inf;
    for (auto v : g[u]) {
        if (v == p[u].fa) continue;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (p[v].size > max) max = p[u].size, p[u].son = v;
    }
}
int dfnCounter;
void dfs2(int u, int top) {
    p[u].top = top, p[u].dfn = ++dfnCounter;
    bel[dfnCounter] = u;
    if (!p[u].son) return;
    dfs2(p[u].son, top);
    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;
        dfs2(v, v);
    }
}
inline int query(int u, int v) {
    int res = 0;
    // for (; p[u].top != p[v].top;)
    return 0;
}
inline void modify(int u, int v, int num) {
    T.modify(p[u].dfn, num);
    T.modify(p[v].dfn + 1, num);
}
bool MEMED;
signed main() {
    FastIO;
#ifdef DEBUG
    cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        ++u, ++v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].val;
        p[i].diff = p[i].val - p[i - 1].val;
    }
    dfs1(1);
    dfs2(1, 1);
    T.build(a, 1, n);
    cin >> q;
    for (char opt, u, v, num; q--;) {
        cin >> opt >> u >> v;
        ++u, ++v;
        if (opt == 'F') cout << query(u, v) << endl;
        if (opt == 'C') {
            cin >> num;
            modify(u, v, num);
        }
    }
    cout.flush();
    return 0;
}
