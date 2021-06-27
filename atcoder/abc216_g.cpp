#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 2e5 + 5;
int n, m;
std::bitset<N> ans;
struct Query {
    int l, r, cnt;
} q[N];

class Fenwick {
   private:
    int val[N];
    inline int lowbit(int x) { return x & -x; }

   public:
    void add(int k) {
        for (; k <= n; k += lowbit(k)) val[k]++;
    }
    long long query(int k) {
        long long res = 0;
        for (; k; k -= lowbit(k)) res += val[k];
        return res;
    }
} T;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> q[i].l >> q[i].r >> q[i].cnt;

    std::sort(q + 1, q + 1 + m, [](Query a, Query b) { return a.l > b.l; });

    ans.set();

    for (int i = 1; i <= m; ++i) {
        int cnt = T.query(q[i].r) - T.query(q[i].l - 1);
        if (cnt > q[i].cnt) continue;
        for (int pos = q[i].l - 1, rest = q[i].cnt - cnt; rest--;) {
            // cerr << rest << ' ' << pos << '\n';
            pos = ans._Find_next(pos);
            assert(pos <= q[i].r);
            T.add(pos), ans[pos] = false;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << (ans[i] ^ true) << ' ';
    cout << '\n';
    return 0;
}
