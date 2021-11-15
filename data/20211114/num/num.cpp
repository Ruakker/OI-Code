#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int ans[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 1, 2, 1, 1, 1, 2, 1, 1},
    {1, 1, 3, 1, 1, 3, 1, 1, 3, 1},
    {1, 2, 1, 4, 1, 1, 1, 4, 1, 1},
    {1, 1, 1, 1, 5, 1, 1, 1, 1, 5},
    {1, 1, 3, 1, 1, 6, 1, 1, 3, 1},
    {1, 1, 1, 1, 1, 1, 7, 1, 1, 1},
    {1, 2, 1, 4, 1, 1, 1, 8, 1, 1},
    {1, 1, 3, 1, 1, 3, 1, 1, 9, 1},
    {1, 1, 1, 1, 5, 1, 1, 1, 1, 10},
};

signed main() {
#ifndef DEBUG
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        cout << ans[u - 1][v - 1] << '\n';
    }
    return 0;
}
