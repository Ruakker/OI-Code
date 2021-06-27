/**
 * File              : 3.cpp
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
#define int long long
const int N = 2e5 + 5;
int a[N], sum;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    std::sort(a + 1, a + 1 + n);
    cin >> m;
    // for (int i = 1; i <= m; ++i) {
    //     int x, y, ans = 0;
    //     cin >> x >> y;
    //     auto it = std::lower_bound(a + 1, a + 1 + n, x);
    //     if (it == a + 1 + n) {
    //         ans += abs(a[n] - x);
    //         if (sum - a[n] < y) ans += y - (sum - a[n]);
    //     } else {
    //         cerr << ">>> " << *it << endl;
    //         if (sum - *it < y) ans += y - (sum - *it);
    //     }
    //     cout << ans << endl;
    // }
    for (int i = 1; i <= m; ++i) {
        int ans = 0, x, y;
        cin >> x >> y;
        int pos = std::lower_bound(a + 1, a + 1 + n, x) - a;
        if (pos > n) {
            cout << std::max(0ll,
                             x - a[n] + (y - sum + a[n]) * (sum - a[n] < y))
                 << endl;
        } else {
            if (sum - a[pos] < y) ans = (y - sum + a[pos]);
            if (pos != 1)
                ans = std::min(ans,
                               std::max(0ll, x - a[pos - 1] +
                                                 ((sum - a[pos - 1] < y)
                                                      ? (y - sum + a[pos - 1])
                                                      : 0ll)));
            cout << ans << endl;
        }
    }
    return 0;
}