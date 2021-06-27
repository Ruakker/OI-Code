/**
 * File              : stairs-2.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/22/2021
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
const int N = 1e5 + 5;
int n, ans, a[N];
void dfs(int pos) {
    if (pos > n) {
        ++ans;
        return;
    }
    if (!a[pos - 1] && !a[pos + 1]) {
        a[pos] = 1;
        dfs(pos + 1);
        a[pos] = 0;
        dfs(pos + 1);
    } else
        dfs(pos + 1);
}
inline void solve(int k) {
    memset(a, 0, sizeof a);
    ans = 0, n = k - 1;
    a[0] = a[k] = 1;
    dfs(1);
    cout << k << ": " << ans << endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i <= 10; ++i)
        solve(i);
    return 0;
}