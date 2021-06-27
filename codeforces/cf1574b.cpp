/**
 * File              : 2.cpp
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

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int a[3], m;
        cin >> a[0] >> a[1] >> a[2] >> m;
        std::sort(a, a + 3);
        int min = a[2] - a[1] - a[0] - 1;
        int max = a[0] + a[1] + a[2] - 3;
        if (m >= min && m <= max)
            cout << "YeS" << endl;
        else
            cout << "nO" << endl;
    }
    return 0;
}