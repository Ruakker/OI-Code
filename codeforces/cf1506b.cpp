/**
 * File              : CF1506B.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-24 22:49:51
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
#define int long long
int a, b, c, d;
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> a >> b >> c;
        if (a < b) std::swap(a, b);
        int n = (a - b) * 2;
        if (a > n || b > n || c > n)
            cout << -1 << endl;
        else {
            d = (n / 2 + c) % n;
            if (!d) d = n;
            cout << d << endl;
        }
    }
    cout.flush();
    return 0;
}
