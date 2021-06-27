#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define eps 1e-15

const int N = 150005;

std::vector<std::vector<double>> a;
std::vector<std::pair<int,int>> e;
std::vector<std::vector<int>> g;
int n, m;
int dgr[N];
double ans;
double f[N];

void Gauss(std::vector<std::vector<double>> &a, int n) {
    for (int i = 1; i <= n; ++i) {
        int k = i;
        for (int j = i + 1; j <= n; ++j)
            if (fabs(a[j][i]) > fabs(a[k][i])) k = j;
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
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n + 1, std::vector<double>(n + 1));
    g.resize(n + 1), e.resize(m + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
        ++dgr[u], ++dgr[v];
        e[i] = {u, v};
    }

    for (int u = 1; u < n; ++u) {
        a[u][u] = 1;
        for (auto v : g[u])
            if (v != n)
                a[u][v] = -1. / dgr[v];
    }

    a[1][n] = 1;
    Gauss(a, n - 1);

    for (int i = 1; i <= m; ++i) {
        auto u = e[i].first, v = e[i].second;
        if (u != n) f[i] += a[u][n] / dgr[u];
        if (v != n) f[i] += a[v][n] / dgr[v];
    }

    std::sort(&f[1], &f[m] + 1);
    for (int i = 1; i <= m; ++i)
        ans += f[i] * (m - i + 1.);

    cout << std::fixed << std::setprecision(3) << ans << '\n';

    return 0;
}

