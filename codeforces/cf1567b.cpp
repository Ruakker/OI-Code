/**
 * File              : CF1567B.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/24/2021
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
const int N = 3e5 + 5;
int sum[N];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i <= 3e5; ++i)
        sum[i] = sum[i - 1] ^ i;
    int T;
    for (cin >> T; T--;) {
        int a, b;
        cin >> a >> b;
        int ans = a, tar = sum[a - 1];
        if ((tar ^ b)) {
            if ((tar ^ b) == a)
                ans += 2;
            else
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}