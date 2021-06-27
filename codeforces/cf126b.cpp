/**
 * File              : CF126B.cpp
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
const int N = 5e5 + 5;
std::string s;  // s.substr(pos, len)
std::vector<std::string> S;
int n, kmp[N];
inline bool check(std::string a, std::string b) {
    int lena = a.length() - 1, lenb = b.length() - 1;
    for (int i = 0; i <= lenb + 10; ++i)
        kmp[i] = 0;
    for (int i = 2, j = 0; i <= lenb; ++i) {
        while (j && b[i] != b[j + 1])
            j = kmp[j];
        if (b[j + 1] == b[i]) j++;
        kmp[i] = j;
    }
    for (int i = 1, j = 0; i <= lena; ++i) {
        while (j && a[i] != b[j + 1])
            j = kmp[j];
        if (b[j + 1] == a[i]) j++;
        if (j == lenb) return true;
    }
    return false;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        S.clear();
        s.clear();
        cin >> s;
        n = s.length();
        s = '_' + s;
        for (int len = 1; len < n; ++len)
            if (s.substr(1, len) == s.substr(n - len + 1, len))
                S.emplace_back(s.substr(1, len));
#ifdef DEBUG
        for (auto iter = S.rbegin(); iter != S.rend(); ++iter)
            cerr << ">>> " << *iter << endl;
#endif
        bool flag = false;
        for (auto iter = S.rbegin(); iter != S.rend(); ++iter)
            if (check(s.substr(2, n - 2), *iter)) {
                cout << *iter << endl;
                flag = true;
                break;
            }
        if (!flag) cout << -1 << endl;  // Different
    }
    return 0;
}