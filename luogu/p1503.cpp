/**
 * File              : P1503.cpp
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
const int N = 5e4 + 5;
int n, m;
std::stack<int> S;
std::bitset<N> tag;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    tag.reset();
    for (int i = 1, u; i <= m; ++i) {
        char opt;
        cin >> opt;
        if (opt == 'D') {
            cin >> u;
            tag.set(u);
            S.emplace(u);
        }
        if (opt == 'R') {
            tag.reset(S.top());
            S.pop();
        }
        if (opt == 'Q') {
            cin >> u;
            if (S.empty()) {
                cout << n << endl;
                continue;
            }
            if (tag[u]) {
                cout << 0 << endl;
                continue;
            }
            int res = 1;
            for (int i = u - 1; i >= 1; --i) {
                if (tag[i]) break;
                ++res;
            }
            for (int i = u + 1; i <= n; ++i) {
                if (tag[i]) break;
                ++res;
            }
            cout << res << endl;
        }
    }
    return 0;
}