#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

const int N = 2050, P = 1e9 + 7;
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
    return 1ll * fac[up] * inv[up - down] % P * inv[down] % P;
}

#define int long long

int n, k;
int f[(N << 1) + 5][(N << 1) + 5], a[N * N], b[N * N];
long long ans;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    init(4'000'000);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
		f[N - a[i]][N - b[i]]++;
	}
    for (int i = 1; i <= N << 1; ++i)
        for (int j = 1; j <= N << 1; ++j)
            (f[i][j] += (f[i - 1][j] + f[i][j - 1]) % P) %= P;
    for (int i = 1; i <= n; ++i) {
        (ans += f[N + a[i]][N + b[i]]) %= P;
        (ans -= C(2 * a[i] + 2 * b[i], 2 * a[i])) %= P;
        (ans += P) %= P;
    }
    ans = (ans * inv[2]) % P;
    cout << ans << endl;
    return 0;
}
