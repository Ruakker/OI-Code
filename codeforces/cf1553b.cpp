/**
 * File              : CF1553B.cpp
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
std::string s, t;
int len;
inline bool check(int pos1, int pos2) {
    int cnt = 0;
    for (int i = pos1; i <= pos2 && cnt < (int)t.length() - 1; ++i)
        if (s[i] != t[++cnt]) return false;
    if (cnt == (int)t.length() - 1) return true;
    for (int i = pos2 - 1; i >= 1 && cnt < (int)t.length() - 1; --i)
        if (s[i] != t[++cnt]) return false;
    if (cnt == (int)t.length() - 1) return true;
    return false;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> s >> t;
        s = '~' + s, t = '~' + t;
        len = s.length() - 1;
        bool flag = false;
        for (int i = 1; i <= len && !flag; ++i)
            for (int j = i; j <= len; ++j)
                if (check(i, j)) {
                    cout << "YeS" << endl;
                    flag = true;
                    break;
                }
        if (flag) continue;
        cout << "nO" << endl;
    }
    return 0;
}