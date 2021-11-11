#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 3005, P = 1e9 + 7;
long long ans;
int n;
int a[N], sum[N], min[N][N], f[N][N];

signed main() {
#ifndef DEBUG
    freopen("cut.in", "r", stdin), freopen("cut.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int l = 1; l <= n; ++l) {
        min[l][l] = a[l];
        for (int r = l + 1; r <= n; ++r)
            min[l][r] = std::min(min[l][r - 1], a[r]);
    }
    for (int i = 1; i <= n; ++i)
        if (min[1][i] == a[i]) f[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            sum[j] = (sum[j - 1] + f[i - 1][j]) % P;
        for (int j = 1; j <= n; ++j)
            if (min[std::min(i, j)][std::max(i, j)] == a[j]) f[i][j] = sum[j];
    }

    ans = 0;
    for (int i = 1; i <= n; ++i)
        (ans += f[n][i]) %= P;
    cout << ans << '\n';
    return 0;
}
