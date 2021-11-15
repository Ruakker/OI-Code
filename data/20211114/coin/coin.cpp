#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

// struct Matrix {
//     Matrix() { memset(w, 0, sizeof w); }
//     long long w[2][2];
//     Matrix operator*(const Matrix &Other) {
//         Matrix res;
//         for (int k = 0; k < 2; ++k)
//             for (int i = 0; i < 2; ++i)
//                 for (int j = 0; j < 2; ++j)
//                     (res.w[i][j] += this->w[i][k] * Other.w[k][j]) %= P;
//         return res;
//     }
//     Matrix pow(long long k) {
//         Matrix res = *this;
//         --k;
//         for (; k; k >>= 1, *this = *this * *this)
//             if (k & 1) res = res * *this;
//         return res;
//     }
// };

const long long N = 1e18 + 5, P = 998244353;
int p, k;
long long f[114514];

signed main() {
#ifndef DEBUG
    freopen("coin.in", "r", stdin), freopen("coin.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> p >> k;

    for (int i = 1; i <= k; ++i)
        f[i] = (f[i - 1] + (P - p) * f[i - 1] + P * p) % P;

    cout << f[k] << '\n';

    return 0;
}

