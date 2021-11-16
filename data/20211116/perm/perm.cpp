#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define inf 0x3f3f3f3f
const int N = 55;
int n, ans;
int a[N], f[N];

signed main() {
#ifndef DEBUG
    freopen("perm.in", "r", stdin), freopen("perm.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];

    for (int i = 1; i <= n; ++i) a[i] = i;

    do {
        bool flag = true;
        for (int k = 1; k <= n; ++k) {
            int max = -inf;
            for (int i = 1; i <= n - k + 1; ++i) {
                int min = inf;
                for (int j = i; j <= i + k - 1; ++j)
                    min = std::min(min, a[j]);
                max = std::max(max, min);
            }
            if (max != f[k]) {
                flag = false;
                break;
            }
        }
        if (flag) ++ans;
    } while (std::next_permutation(a + 1, a + 1 + n));

    cout << ans << '\n';

    return 0;
}
