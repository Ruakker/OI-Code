#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define fk cout << "fuck\n"
#define int long long

const int N = 3e5 + 5, P = 998244353;
std::vector<int> g[N];
int n, ans;
int f[N];

void dfs(int u, int pre) {
    for (auto iter = g[u].begin(); iter != g[u].end(); ++iter) {
        auto v = *iter;
        if (v == pre) continue;
        dfs(v, u);
        f[u] = f[u] * (f[v] + 1) % P;
    }
}

int qpow(int n, int k) {
    int res = 1;
    for (; k; n = n * n % P, k >>= 1)
        if (k & 1) res = res * n % P;
    return res;
}

signed main() {
#ifndef DEBUG
    freopen("prune.in", "r", stdin);
    freopen("prune.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) f[i] = 1;

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) (ans += f[i]) %= P;

    ans = (qpow(2, n) - ans - 1 + P) % P;
    cout << ans << '\n';

    return 0;
}
