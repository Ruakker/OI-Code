/**
 * File              : bit.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/25/2021
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
#define int long long
long long a, b, c;
long long u, v, w;
signed main() {
    // freopen("bit.in", "r", stdin), freopen("bit.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> a >> b >> c;
        if (abs(a + b) & 1)
            cout << -1 << endl;
        else {
            u = (a + b) >> 1;
            v = (a - b) >> 1;
            w = a ^ b ^ c ^ u ^ v;
            if (u <= 0 || v <= 0 || w <= 0)
                cout << -1 << endl;
            else
                cout << u << ' ' << v << ' ' << w << endl;
        }
    }
    return 0;
}