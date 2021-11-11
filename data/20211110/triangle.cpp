#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define fk cerr << "fuck\n";

namespace GenHelper {
unsigned z1, z2, z3, z4, b, u;
unsigned get() {
    b = ((z1 << 6) ^ z1) >> 13;
    z1 = ((z1 & 4294967294U) << 18) ^ b;
    b = ((z2 << 2) ^ z2) >> 27;
    z2 = ((z2 & 4294967288U) << 2) ^ b;
    b = ((z3 << 13) ^ z3) >> 21;
    z3 = ((z3 & 4294967280U) << 7) ^ b;
    b = ((z4 << 3) ^ z4) >> 12;
    z4 = ((z4 & 4294967168U) << 13) ^ b;
    return (z1 ^ z2 ^ z3 ^ z4);
}
bool read() {
    while (!u) u = get();
    bool res = u & 1;
    u >>= 1;
    return res;
}
void srand(int x) {
    z1 = x;
    z2 = (~x) ^ 0x233333333U;
    z3 = x ^ 0x1234598766U;
    z4 = (~x) + 51;
    u = 0;
}
}  // namespace GenHelper

const int N = 8005;
long long n, m, ans, seed;
long long cnt[2];
bool edge[N][N];

signed main() {
#ifndef DEBUG
    freopen("triangle.in", "r", stdin), freopen("triangle.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> seed;
    GenHelper::srand(seed);

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            edge[j][i] = edge[i][j] = GenHelper::read();

    for (int i = 1; i <= n; ++i) {
        cnt[0] = cnt[1] = 0;
        for (int j = 1; j <= n; ++j)
            cnt[edge[i][j]]++;
        ans += cnt[1] * (cnt[0] - 1);
    }

    cout << n * (n - 1) * (n - 2) / 6 - ans / 2 << '\n';
    return 0;
}
