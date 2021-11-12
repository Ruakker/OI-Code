#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int P = 1e9 + 7;
int n, m, x;
std::vector<std::vector<std::vector<int>>> f;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> x;

    if (n > m) {
        cout << "0\n";
        return 0;
    }
    f.resize(m + 1,
             std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1)));

    f[0][0][0] = 1;

    for (int i = 1; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= j; ++k) {
                if (j > k) (f[i][j][k] += f[i - 1][j - 1][k]) %= P;
                if (j && k) (f[i][j][k] += f[i - 1][j - 1][k - 1]) %= P;
                if (i != x) {
                    if (k) (f[i][j][k] += f[i - 1][j][k - 1]) %= P;
                    (f[i][j][k] += f[i - 1][j][k]) %= P;
                }
            }

    long long ans = f[m][n][n];
    for (int i = 1; i <= n; ++i) (ans *= i) %= P;

    cout << ans << '\n';

    return 0;
}
