#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define eps 1e-15

const int N = 105;
int n;
std::vector<std::vector<double>> a;

bool Gauss(std::vector<std::vector<double>> &a, int n) {
    for (int i = 1; i <= n; ++i) {
        int k = i;
        for (int j = i + 1; j <= n; ++j)
            if (fabs(a[j][i]) > fabs(a[k][i])) k = j;
        if (fabs(a[k][i]) < eps) return false;
        std::swap(a[i], a[k]);

        for (int j = i + 1; j <= n; j++) {
            double div = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++)
                a[j][k] -= a[i][k] * div;
        }
    }

#ifdef DEBUG
    for (int i = 1; i <= n; ++i, cerr << '\n')
        for (int j = 1; j <= n + 1; ++j)
            cerr << std::fixed << std::setprecision(2) << a[i][j] << ' ';
#endif

    for (int i = n; i; --i) {
        for (int j = i + 1; j <= n; ++j)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }

    return true;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    a.resize(n + 1, std::vector<double>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 1; ++j)
            cin >> a[i][j];

    if (!Gauss(a, n)) {
        cout << "No Solution" << '\n';
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        cout << std::fixed << std::setprecision(2) << a[i][n + 1] << '\n';

    return 0;
}
