#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 1005;
int n, m, sum;
int a[N];
double ans;
double f[N][N], s[N];

signed main() {
    cin >> n >> m;
    if (m == 1) {
        cout << "1.000000000000\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double num = m - 1;
    f[0][0] = num;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        s[0] = f[cur ^ 1][0];
        f[cur][0] = 0;
        for (int j = 1; j <= n * m; j++)
            s[j] = s[j - 1] + f[cur ^ 1][j], f[cur][j] = 0;
        for (int j = 0; j <= n * m; j++) {
            f[cur][j] = s[j - 1] / num;
            if (j - m - 1 >= 0) f[cur][j] -= s[j - m - 1] / num;
            if (j - a[i] >= 0) f[cur][j] -= f[cur ^ 1][j - a[i]] / num;
        }
        cur ^= 1;
    }
    for (int i = 0; i < sum; i++) ans += f[cur ^ 1][i];
    cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}
