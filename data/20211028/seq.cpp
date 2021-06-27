#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define int long long
#define inf 0x3f3f3f3f3f3f3f3fLL

const signed N = 1.5e6 + 5;

signed n, m;
signed a[N], b[N];
long long suma[N], sumb[N], ans[N];
std::vector<std::pair<signed, signed>> Ql[N], Qr[N];

struct f {
    f(int u = -inf, int v = -inf) { k = u, b = v; }
    long long k, b;
    inline long long operator()(int x) {
        if (k == -inf && b == -inf) return -inf;
        return k * x + b;
    }
};

class LiChaoTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define mid ((l + r) >> 1)
    f val[N * 3];
    int l, r;
    void build(int l, int r, int k) {
        val[k] = f();
        if (l == r) return val[k] = f(), void();
        build(l, mid, lson), build(mid + 1, r, rson);
    }
    long long query(int pos, int l, int r, int k) {
        if (pos == l && pos == r) return val[k](pos);
        if (pos <= mid)
            return std::max(val[k](pos), query(pos, l, mid, lson));
        else
            return std::max(val[k](pos), query(pos, mid + 1, r, rson));
    }

    void modify(f w, int l, int r, int k) {
        if (l == r) {
            if (val[k](l) < w(l)) val[k] = w;
            return;
        }

        if (val[k].k < w.k) {
            if (w(mid) > val[k](mid)) {
                modify(val[k], l, mid, lson);
                val[k] = w;
            } else
                modify(w, mid + 1, r, rson);
        }

        if (val[k].k > w.k) {
            if (w(mid) > val[k](mid)) {
                modify(val[k], mid + 1, r, rson);
                val[k] = w;
            } else
                modify(w, l, mid, lson);
        }

        if (val[k].k == w.k)
            val[k].b = std::max(val[k].b, w.b);
    }

   public:
    inline void build(int _l, int _r) { l = _l, r = _r, build(_l, _r, 1); }
    inline long long query(int pos) { return query(pos, l, r, 1); }
    inline void modify(f w) { modify(w, l, r, 1); }
#undef lson
#undef rson
#undef mid
} T;

signed main() {
#ifndef DEBUG
    freopen("seq.in", "r", stdin), freopen("seq.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

    for (int p, k, i = 1; i <= m; ++i) {
        cin >> p >> k;
        Ql[p - 1].emplace_back(i, k), Qr[p + 1].emplace_back(i, k);
        ans[i] = a[p] - k * b[p];
    }

    for (int i = n; i; --i) {
        suma[i] = a[i] + suma[i + 1];
        sumb[i] = b[i] + sumb[i + 1];
    }
    T.build(-1e6, 1e6);
    for (int i = 1; i <= n; ++i) {
        T.modify(f(-sumb[i], suma[i]));
        for (auto v : Ql[i])
            ans[v.first] = std::max(ans[v.first], ans[v.first] + T.query(v.second) - suma[i + 1] + v.second * sumb[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        suma[i] = a[i] + suma[i - 1];
        sumb[i] = b[i] + sumb[i - 1];
    }
    T.build(-1e6, 1e6);
    for (int i = n; i; --i) {
        T.modify(f(-sumb[i], suma[i]));
        for (auto v : Qr[i])
            ans[v.first] = std::max(ans[v.first], ans[v.first] + T.query(v.second) - suma[i - 1] + v.second * sumb[i - 1]);
    }

    cerr << "-----\n";
    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';

    return 0;
}
