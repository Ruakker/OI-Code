/**
 * File              : stairs.cpp
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
const int N = 1e6 + 5, P = 1e9 + 7;
int w[8];
namespace pts20 {
int ans[N];
signed Main() {
    ans[1] = ans[2] = ans[3] = 1;
    for (int i = 4; i <= w[1]; ++i)
        ans[i] = (ans[i - 1] + ans[i - 2]) % P;
    cout << ans[w[1]] << endl;
    return 0;
}
}  // namespace pts20
signed main() {
    freopen("stairs.in", "r", stdin), freopen("stairs.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i <= 7; ++i)
        cin >> w[i];
    if (w[1] > 0 && w[2] + w[3] + w[4] + w[5] + w[6] + w[7] == 0)
        return pts20::Main();
    cout << "你今天又爆零了" << endl;
    cout << "你失去了决心" << endl;
    return 0;
}