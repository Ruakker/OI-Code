#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
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
        std::string s;
        cin >> s;
        int n = s.size(), ans = 0x3f3f3f3f3f3f3f3fll;
        for (signed i = 0; i < n; ++i)
            for (signed j = i + 1; j < n; ++j) {
                if (s[i] == '0' && s[j] == '0' || s[i] == '5' && s[j] == '0' || s[i] == '2' && s[j] == '5' || s[i] == '7' && s[j] == '5')
                    ans = std::min(ans, n - i - 2ll);
            }
        cout << ans << endl;
    }
    return 0;
}
