/**
 * File              : CF1573A.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/23/2021
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
        int n, ans = 0;
        std::string s;
        cin >> n >> s;
        ans += s[n - 1] - '0';
        for (int i = 0; i < n - 1; ++i)
            if (s[i] != '0') ans += s[i] - '0' + 1;
        cout << ans << endl;
    }
    return 0;
}