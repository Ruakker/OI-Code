#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define int long long
const int P = 998244353;
int m;
long long qpow(long long n, long long k, long long p = P) {
    long long res = 1;
    for (; k; k >>= 1, n = n * n % P)
        if (k & 1) res = res * n % P;
    return res;
}

signed main() {
    cin >> m;
    for (int x = 1; x <= m; ++x)
        for (int y = 1; y <= m; ++y)
            for (int n = 1; n <= 1; ++n)
                printf("x: %lld y: %lld a: %lld b: %lld n: %lld, the ans is %lld\n", x, y, x + y, x * y, n, qpow(x, n) + qpow(y, n));
    return 0;
}
