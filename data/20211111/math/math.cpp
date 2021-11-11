#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 1e7 + 5;
const long long inf = 1e18;
long long n, x, y, ans, cnt;
long long a[N];

signed main() {
#ifndef DEBUG
    freopen("math.in", "r", stdin), freopen("math.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    n = inf;
    for (int i = 2; i <= n / i / i; ++i) {
        long long x = 1ll * i * i * i, k = i;
        while (x <= n) {
            a[++cnt] = x;
            if (x > (n - k) / (1ll * i * i)) break;
            long long B = 1ll * i * i * x;
            long long t = B - k;
            k = x;
            x = t;
        }
    }
    std::sort(a + 1, a + cnt + 1);

    int _;
    for (cin >> _; _--;) {
        cin >> n;
        cout << std::upper_bound(a + 1, a + cnt, n) - a + (n == inf) << '\n';
    }

    return 0;
}
