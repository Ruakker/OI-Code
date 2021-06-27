#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define int long long
#define maxn 250000000000
const int N = 5e5 + 5;
int n, ans;
int a[N];

class SegmentTree {
#define lson w[p].l
#define rson w[p].r
#define mid ((l + r) >> 1)
    struct Node {
        int val, l, r;
    } w[N << 5];
    
    int cnt;

    inline void pushUp(int p) { w[p].val = w[lson].val + w[rson].val; }
    void insert(int pos, int l, int r, int p) {
        if (lson == 0) lson = ++cnt;
        if (rson == 0) rson = ++cnt;
        if (pos == l && pos == r) return ++w[p].val, void();
        if (pos <= mid) insert(pos, l, mid, lson);
        if (mid + 1 <= pos) insert(pos, mid + 1, r, rson);
        pushUp(p);
    }
    int query(int L, int R, int l, int r, int p) {
        if (!lson || !rson) return w[p].val;
        if (L <= l && r <= R) return w[p].val;

        int res = 0;
        if (L <= mid) res += query(L, R, l, mid, lson);
        if (mid + 1 <= R) res += query(L, R, mid + 1, r, rson);
        return res;
    }

   public:
    inline void init() { cnt = 1; }
    inline void insert(int pos) { insert(pos, 1, maxn, 1); }
    inline int query(int l, int r) { return query(l, r, 1, maxn, 1); }

#undef lson
#undef rson
#undef mid
} T;

signed main() {
#ifndef DEBUG
    freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    T.init();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < i; ++j) T.insert(a[i] * a[j]);
        ans += T.query(a[i + 1] + 1, maxn);
    }
    cout << ans << '\n';

    return 0;
}
