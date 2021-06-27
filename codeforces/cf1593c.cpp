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
int a[1000000];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int n, k;
        cin >> n >> k;
        int cnt = n - 1, ans = 0;
        for (int i = 1; i <= k; ++i) cin >> a[i];
        std::sort(a + 1, a + 1 + k);
        for (int i = k; i; --i) {
            cnt -= n - a[i];
            if (cnt < 0) break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
