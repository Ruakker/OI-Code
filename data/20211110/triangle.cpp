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
int n, m, ans, seed;
int tag[N], dgr[N];
bool edge[N][N];
std::vector<int> g[N][2];

signed main() {
#ifndef DEBUG
    freopen("triangle.in", "r", stdin), freopen("triangle.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> seed;
    GenHelper::srand(seed);

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            edge[j][i] = edge[i][j] = GenHelper::read();
            g[i][edge[i][j]].push_back(j);
            g[j][edge[j][i]].push_back(i);
        }

    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        ++cnt;
        for (auto v : g[u][0]) {
            tag[v] = cnt;
            for (auto w : g[v][0])
                if (tag[w] == cnt && edge[v][w] == 0) ++ans;
        }
        ++cnt;
        for (auto v : g[u][1]) {
            tag[v] = cnt;
            for (auto w : g[v][1])
                if (tag[w] == cnt && edge[v][w] == 1) ++ans;
        }
    }

    ans /= 3;
    cout << ans << '\n';
    return 0;
}
