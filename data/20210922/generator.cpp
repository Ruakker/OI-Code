/**
 * File              : generator.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/22/2021
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
const int N = 2000;
std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = rnd() % 6 + 1;
    // int T = 6;
    cout << T << endl;
    for (; T--;) {
        int n = rnd() % N + 1, m = rnd() % N + 1;
        // int n = N, m = N;
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= m; ++i)
            cout << rnd() % n + 1 << endl;
    }
    return 0;
}