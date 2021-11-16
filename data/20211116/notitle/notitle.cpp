#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 4e5 + 5, P = 1e9 + 7;
long long ans[N], n;

void init(int n) {
    ans[1] = 1;
    for (int i = 2; i <= n; ++i)
        ans[i] = (ans[i - 1] * (4 * i - 2) / (i + 1)) % P;
}

signed main() {
#ifndef DEBUG
    freopen("notitle.in", "r", stdin), freopen("notitle.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    init(400000);
    int _;
    for (cin >> _; _--;) {
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}
