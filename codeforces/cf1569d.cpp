/**
 * File              : CF1569D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/28/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
const int N = 1e6 + 5;
int n, m, k;
int x[N], y[N];
struct Human {
    int x, y;
} p[N];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            cin >> x[i];
        for (int i = 1; i <= m; ++i)
            cin >> y[i];
        for (int i = 1; i <= k; ++i)
            cin >> p[i].x >> p[i].y;
    }
    return 0;
}