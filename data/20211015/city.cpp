#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

const int N = 1e7 + 5, P = 998244353;
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
}

inline int C(int up, int down) {
    if (up < down) return 0;
    return 1ll * fac[up] * inv[up - down] % P * inv[down] % P;
}

long long n, m, k, ans;

signed main() {
#ifndef DEBUG
    freopen("city.in", "r", stdin), freopen("city.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    init(10000000);
    cin >> n >> m >> k;
    for (int i = 0, id = 1; i <= n && m - i * k >= n; i++, id = -id)
        (ans += P + 1ll * id * C(n, i) % P * C(m - i * k - 1, n - 1) % P) %= P;
    cout << ans << endl;
    return 0;
}
