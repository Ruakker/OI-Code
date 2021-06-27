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
const int N = 1e5 + 5, K = 505;
int t[N], f[N], p[N];
int n, k, one;
std::pair<int, int> a[N];

signed main() {
#ifndef DEBUG
    freopen("buy.in", "r", stdin), freopen("buy.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= k; ++i)
        cin >> a[i].first >> a[i].second;
    cin >> one;
    for (int i = 1; i <= n; ++i){
        f[i] = f[i-1] + one;
        for (int j = 1; j <= k; ++j){
            for (; t[p[j] + 1] - 1 < t[i] - a[j].first; ++p[j]);
            f[i] = std::min(f[i], f[p[j]] + a[j].second);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << f[i] - f[i - 1] << endl;
    return 0;
}
