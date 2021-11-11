#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int P = 998244353;
long long a, b, n, x, y;

struct Matrix {
    Matrix() { memset(w, 0, sizeof w); }
    long long w[2][2];
    Matrix operator*(const Matrix &Other) {
        Matrix res;
        for (int k = 0; k < 2; ++k)
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    (res.w[i][j] += this->w[i][k] * Other.w[k][j]) %= P;
        return res;
    }
    Matrix pow(long long k) {
        Matrix res = *this;
        --k;
        for (; k; k >>= 1, *this = *this * *this)
            if (k & 1) res = res * *this;
        return res;
    }
} f, g;

signed main() {
#ifndef DEBUG
    freopen("poly.in", "r", stdin), freopen("poly.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> a >> b >> n;

    f.w[0][0] = 0, f.w[0][1] = P - b, f.w[1][0] = 1, f.w[1][1] = a;
    g.w[0][0] = 2, g.w[0][1] = a, g.w[1][0] = 0, g.w[1][1] = 0;

    f = f.pow(n - 1);
    g = g * f;
    cout << g.w[0][1] << '\n';

    return 0;
}
