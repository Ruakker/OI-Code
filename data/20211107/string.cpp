#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

/* I do the same thing I told u that I never would,  */
/* Told u Ill change even when I know I never could. */
/* Know that I cant find nobody else as good as u.   */
/* I need u to stay, need u to stay ~                */

const int N = 1e5 + 5;
int n, k;
long long tot;
int ans[N];

signed main() {
#ifndef DEBUG
    freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    if (k == 0) {
        cout << "0\n";
        for (int i = 1; i <= n; ++i)
            cout << "0 ";
        cout << '\n';
        return 0;
    }

    tot = 1ll * (n / 2ll + 1ll) * (n - n / 2ll);
    cout << tot << '\n';  // 2 * (mid / 2 * (n - mid / 2 + 1 - mid / 2)) => (n / 2 + 1) * (n - n / 2)

    for (int i = n - k + 2; i <= n; ++i)
        ans[i] = 1;
    if (n & 1)
        ans[(n - k) / 2 + 1] = 1;
    else
        ans[(n - k + 1) / 2 + 1] = 1;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
