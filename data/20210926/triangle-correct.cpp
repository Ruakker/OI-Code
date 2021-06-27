/**
 * File              : triangle-correct.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/29/2021
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
const int N = 2005;
int n;
std::bitset<N> vis[N];
typedef std::pair<std::pair<int, int>, int> p_pii_i;
std::vector<p_pii_i> ans;
signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (vis[i][j]) continue;
            int k = (2 * n - i - j) % n;
            if (k <= 0 || i == k || j == k) continue;
            ans.emplace_back(std::make_pair(i, j), k);
            vis[i][j] = vis[i][k] = vis[k][j] = true;
            vis[j][i] = vis[k][i] = vis[j][k] = true;
        }
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.first.first << ' ' << e.first.second << ' ' << e.second
             << endl;
    return 0;
}