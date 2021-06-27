#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define inf 0x3f3f3f3f
const int N = 22;
int n, ans = inf;
int a[N], dis[N][N], f[1 << N][N];

int main() {
#ifndef DEBUG
    freopen("treasure.in", "r", stdin), freopen("treasure.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dis[i][j];
    int key = 0;
    for (int i = 0, opt, k; i < n; ++i) {
        cin >> opt;
        if (opt == 0) {
            key |= 1 << i;
            cin >> k;
            for (int j = 0, u; j < k; ++j) {
                cin >> u;
                a[i] |= 1 << (u - 1);
            }
        }
    }
    key |= a[0]; // all chests and some key

    memset(f, inf, sizeof f);
    f[1][0] = 0;
    for (int i = 1; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j)
            if (i >> j & 1) {
                for (int k = 0; k < n; k++)
                    if (!(i >> k & 1) && (a[k] & (i | 1 << k)) == a[k])
                        f[i | 1 << k][k] = std::min(f[i | 1 << k][k], f[i][j] + dis[j][k]);
                if ((i & key) == key) ans = std::min(ans, f[i][j] + dis[j][0]);
            }
    cout << ans << endl;

    return 0;
}

