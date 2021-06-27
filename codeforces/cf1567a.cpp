/**
 * File              : CF1567A.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/24/2021
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
    for (cin >> T; T--;) {
        int n;
        std::string s;
        cin >> n >> s;
        for (auto ch : s)
            cout << (char)(ch == 'U' || ch == 'D' ? ch ^ 'U' ^ 'D' : ch);
        cout << endl;
    }
    return 0;
}