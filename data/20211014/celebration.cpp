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

const int N = 1e5 + 5, P = 998244353;
int fac[N], inv[N];

inline int qpow(int base, int k, int Mod = P) {
    int res = 1;
    for (; k; k >>= 1, base = 1ll * base * base % Mod)
        if (k & 1) res = 1ll * res * base % Mod;
    return res;
}

inline void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % P;
    inv[n] = qpow(fac[n], P - 2);
    for (int i = n - 1; ~i; --i)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % P;
#ifdef DEBUG
    for (int i = 0; i <= 10; ++i)
        cerr << fac[i] << ' ';
    cerr << endl;
    for (int i = 0; i <= 10; ++i)
        cerr << inv[i] << ' ';
    cerr << endl;
#endif
}

inline int C(int up, int down) {
    return 1ll * fac[up] * inv[up - down] % P * inv[down] % P;
}

int n, m, ans;
int f[N];

signed main() {
#ifndef DEBUG
    freopen("celebration.in", "r", stdin), freopen("celebration.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    init(100000);
    cin >> n >> m;
    n -= 1ll * m * (m + 1) / 2;
    if (n < 0) {
        cout << 0 << endl;
        return 0;
    }

    f[0] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = i; j <= n; ++j)
            (f[j] += f[j - i]) %= P;

    cout << f[n] * fac[m] % P << endl;

    return 0;
}
