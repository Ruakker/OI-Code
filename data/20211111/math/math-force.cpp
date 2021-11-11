#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 5000;
long long n, x, y, ans, lastans;

signed main() {
#ifndef DEBUG
    freopen("math.in", "r", stdin), freopen("math.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    int m;
    cin >> m;
    for (n = 1; n <= m; ++n) {
        ans = 0;
        for (x = 1; x <= n; ++x)
            for (y = x; y <= n; ++y)
                if ((x * x + y * y) % (x * y + 1) == 0) ++ans;
        if (ans != lastans) cout << n << ": " << (lastans = ans) << '\n';
    }

    return 0;
}
