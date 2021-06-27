/**
 * File              : CF1573B.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/23/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define int long long
const int N = 1e5 + 5;
int a[N], b[N];
int n;
struct SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
   protected:
    int val[N << 2], tag[N << 2];
    inline void pushup(int k) { val[k] = std::min(val[lson], val[rson]); }

   public:
    void build(int l, int r, int k) {
        if (l >= r) {
            val[k] = inf;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        pushup(k);
    }
    void modify(int pos, int num, int l, int r, int k) {
        if (l == r) {
            val[k] = num;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(pos, num, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, num, mid + 1, r, rson);
        pushup(k);
    }
    int query(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return val[k];
        int mid = (l + r) >> 1, res = inf;
        if (L <= mid) res = std::min(res, query(L, R, l, mid, lson));
        if (mid + 1 <= R) res = std::min(res, query(L, R, mid + 1, r, rson));
        return res;
    }
#undef lson
#undef rson
} T;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int _;
    cin >> _;
    for (; _--;) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        T.build(1, 2 * n, 1);
        for (int i = 1; i <= n; ++i)
            T.modify(b[i], i - 1, 1, 2 * n, 1);
        int ans = inf;
        for (int i = 1; i <= n; ++i)
            ans = std::min(ans, T.query(a[i] + 1, 2 * n, 1, 2 * n, 1) + i - 1);
        cout << ans << endl;
    }
    return 0;
}