/**
 * File              : password-correct.cpp
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
const int N = 1e6 + 5;
std::string s;
int n, nxt[N];
signed main() {
    freopen("password.in","r",stdin);
    freopen("password.out","w",stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        memset(nxt, 0, sizeof nxt);
        int max = 0;
        cin >> s;
        n = s.length(), s = '_' + s, nxt[1] = 0;
        for (int i = 2, j = 0; i <= n; i++) {
            for (; j && s[i] != s[j + 1]; j = nxt[j])
                ;
            if (s[i] == s[j + 1]) j++;
            nxt[i] = j;
            if (i != n) max = std::max(nxt[i], max);
        }
        int u = nxt[n];
        for (; u > max; u = nxt[u])
            ;
        if (!u) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 2; i < n; i++)
            if (u == nxt[i]) {
                for (int j = i - nxt[i] + 1; j <= i; j++)
                    cout << s[j];
                cout << endl;
                break;
            }
    }
    return 0;
}