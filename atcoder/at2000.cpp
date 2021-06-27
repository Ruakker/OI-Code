#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

const int N = 2005, P = 1e9 + 7;
int fac[N * N], inv[N * N];

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

inline int C(int down, int up) {
    return 1ll * fac[up] * inv[up - down] % P * inv[down] % P;
}

int n, k;
int f[N][N];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    init(4'000'000);
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    f[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = (f[i - 1][j] + 1ll * f[i][j - 1] * (n - j + 1ll) % P * C(k - 2, 1ll * n * k - i - (j - 1ll) * (k - 1ll ) - 1ll) % P) % P;
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
