#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define ceil(x) (int)(x + 0.5)
const int N = 405;
int n, w;
int a[N], f[N][N][N], sum[N][3];

signed main() {
#ifndef DEBUG
    freopen("pack.in", "r", stdin);
    freopen("pack.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i][a[i]]++;
        sum[i][1] = sum[i - 1][1];
        sum[i][0] = sum[i - 1][0];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)

    return 0;
}
