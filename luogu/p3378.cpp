/**
 * File              : P3378.cpp
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
std::multiset<int> S;
int n;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1, opt, k; i <= n; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> k;
            S.emplace(k);
        }
        if (opt == 2) cout << *S.begin() << endl;
        if (opt == 3) S.erase(S.begin());
    }
    return 0;
}