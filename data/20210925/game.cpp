/**
 * File              : game.cpp
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
const int N = 1e6 + 5;
int n, k, m;
int a[N];
std::multiset<int> S;
std::vector<std::pair<int, int>> ans;
signed main() {
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= n - k + 1; ++i)
        cin >> a[i];
    // S.insert(a[1]);
    // for (int i = 2; i <= n; ++i) {
    //     if (i > k) S.erase(a[i - k]);
    //     if (a[i] < *S.begin())
    //         ans.emplace_back(std::make_pair(i - 1, a[i - 1]));
    //     if (i <= n - k + 1) S.insert(a[i]);
    // }
    for (int i = 1; i <= n - k; ++i) {
        if (a[i] < a[i + 1]) ans.emplace_back(std::make_pair(i, a[i]));
        if (a[i] > a[i + 1]) ans.emplace_back(std::make_pair(i + k, a[i + 1]));
    }
    std::sort(ans.begin(), ans.end());
    auto len = std::unique(ans.begin(), ans.end());
    cout << len - ans.begin() << endl;
    for (auto iter = ans.begin(); iter != len; ++iter)
        cout << iter->first << ' ' << iter->second << endl;
    return 0;
}