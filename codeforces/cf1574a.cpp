/**
 * File              : CF1574A.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/20/2021
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

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                cout << '(';
            for (int j = 1; j <= i; j++)
                cout << ')';
            for (int j = i + 1; j <= n; j++)
                cout << "()";
            cout << endl;
        }
    }
    return 0;
}