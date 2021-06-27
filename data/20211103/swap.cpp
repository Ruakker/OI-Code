#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 3005;
int n, k;
std::pair<int, int> a[N];
std::set<std::vector<int>> S;
std::vector<int> t;

signed main() {
#ifndef DEBUG
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    t.resize(n + 1);
    for (int i = 1; i < n; ++i) cin >> a[i].first >> a[i].second;
    std::sort(a + 1, a + n);
    do {
        for (int i = 1; i <= n; ++i)
            t[i] = i;
        for (int i = 1; i <= k; ++i)
            std::swap(t[a[i].first], t[a[i].second]);
        S.insert(t);
    } while (std::next_permutation(a + 1, a + n));
    cout << S.size() % 998244352u << '\n';

    return 0;
}
