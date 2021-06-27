/**
 * File              : item.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/25/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define int long long
const int N = 5e5 + 5;
int n, cap, ans;
std::pair<int, int> a[N];   // first: Weight, second: Value
inline bool check(int m) {  // Try to choose m things, choose a_x <= m first
    int cnt = 0, rest = cap;
    for (int i = 1; i <= n && cnt <= m; ++i)
        if (rest >= a[i].first && m <= a[i].second) {
            rest -= a[i].first;
            ++cnt;
        }
    if (cnt >= m) return true;
    return false;
}
inline int BinarySearch(int l, int r) {
    int mid = (l + r) >> 1;
    for (; l + 1 < r;) {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}
signed main() {
    // freopen("item.in", "r", stdin);
    // freopen("item.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> cap;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].second >> a[i].first;
    std::sort(a + 1, a + 1 + n);
    cout << BinarySearch(0, n + 5) << endl;
    return 0;
}