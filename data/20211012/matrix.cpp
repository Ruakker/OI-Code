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

const int N = 5005, P = 998244353;
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

inline int C(int up, int down) {
    if (up < down) return 0;
    return 1ll * fac[up] * inv[up - down] % P * inv[down] % P;
}

int n;
int w[N], num[N], f[N];
long long ans;

signed main() {
#ifndef DEBUG
    freopen("matrix.in", "r", stdin), freopen("matrix.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    init(5000 * 5000);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
	}

    for (int i = 1; i <= n; ++i)
        num[i] = 1ll * C(n * i, n) % P;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j; --j)
            (f[i] += 1ll * C(i, j) * num[j] % P * ((i - j) & 1 ? -1ll : 1ll) + P) %= P;
        (f[i] *= C(n, i)) %= P;
    }

#ifdef DEBUG
    for (int i = 0; i <= 10; ++i)
        cerr << num[i] << ' ';
    cerr << endl;
    for (int i = 0; i <= 10; ++i)
        cerr << f[i] << ' ';
    cerr << endl;
#endif

    for (int i = 1; i <= n; ++i)
        (ans += 1ll * f[i] * w[i]) %= P;

    cout << ans * fac[n * n - n] % P * fac[n] % P << endl;
    return 0;
}
