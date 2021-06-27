/**
 * File              : P4305.cpp
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
std::unordered_set<int> S;
int n;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        S.clear();
        cin >> n;
        for (int i = 1, k; i <= n; ++i) {
            cin >> k;
            if (S.find(k) == S.end()) {
                cout << k << ' ';
                S.insert(k);
            }
        }
        cout << endl;
    }
    return 0;
}