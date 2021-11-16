#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int Len = 1442250;
long long n, ans, lim;
unsigned long long a[Len + 5];

bool dfs(int sum, int k) {
    if (sum == n) {
        ans = k - 1;
        return true;
    }
    if (k > lim) return false;
    if (dfs(sum + k * k, k + 1) || dfs(sum - k * k, k + 1)) return true;
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    for (int i = 1; i <= Len; ++i)
        a[i] = a[i - 1] + 1ull * i * i;

    int _ = 50;
    for (int i = 1; i <= _; ++i)
        cout << std::setw(3) << i;
    cout << '\n';

    for (n = 1; n <= _; ++n) {
        // int len = std::lower_bound(a + 1, a + 1 + Len, n) - a;
        for (lim = 1; !dfs(0, 1); ++lim);
            // if (dfs(0, 1)) {cout << ans << '\n';break;}
        // cout << std::setw(3) << n << ' ' << ans << '\n';
        cout << std::setw(3) << ans;
        cout.flush();
    }

    return 0;
}
