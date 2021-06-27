#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 1e5 + 5;
int n, k, limit;
int ans[N];

inline int lowbit(int x) { return x & -x; }

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    int limit = std::max((n - 3) / 2, 0);
    if (k > limit || !(n & 1) || (n == 9 && k == 2) ||
        (__builtin_popcount(n + 1) == 1 && k == 1) ||
        (__builtin_popcount(n + 1) != 1 && !k)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int base = 2 * std::max(0, k - 1);
    for (int i = 1; i < base; i += 2)
        ans[i + 1] = i, ans[i] = std::max(0, i - 2);

    ans[base + 1] = std::max(0, base - 1);

    for (int i = 2; i <= n - base; ++i)
        ans[base + i] = (i >> 1) + base;

    if (__builtin_popcount(n - base + 1) == 1 && k) ans[n - 1] = ans[n] = 2;

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
