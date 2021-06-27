#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define int long long
const int N = 3005, P = 998244353;
int suml[N], sumr[N], f[N][N];
int n, m;

signed main() {
#ifndef DEBUG
    freopen("attack.in", "r", stdin), freopen("attack.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, l, r; i <= n; ++i) {
        cin >> l >> r;
        suml[l]++, sumr[r]++;
    }
    for (int i = 1; i <= m; ++i)
        suml[i] += suml[i - 1], sumr[i] += sumr[i - 1];

#ifdef DEBUG
    for (int i = 1; i <= m; ++i)
        cerr << suml[i] << ' ';
    cerr << endl;
    for (int i = 1; i <= m; ++i)
        cerr << sumr[i] << ' ';
    cerr << endl;
#endif

    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; ++j)
            f[i][j] = (f[i - 1][j] + 1ll * f[i - 1][j - 1] * (sumr[i] - j + 1)) % P;
        for (int j = suml[i - 1]; j < suml[i]; ++j)
            for (int k = 0; k <= i; ++k)
                (f[i][k] *= i - k - j) %= P;
    }
    cout << f[m][n] << endl;

    return 0;
}
