/**
 * File              : CF1567D.cpp
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
#define int long long
const int N = 105;
int sum, n, cnt;
// std::vector<int> ans;
std::priority_queue<int, std::vector<int>, std::greater<int>> ans;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> sum >> n;
        int Count = 0;
        for (; !ans.empty(); ans.pop())
            ;
        // ans.clear();
        cnt = 0;
        int sumcnt = 0;
        if (n == 1) {
            cout << sum << endl;
            continue;
        }
        for (int tmp = sum; tmp; tmp /= 10) {
            sumcnt += tmp % 10;
            if (tmp % 10 != 0) ++cnt;
        }
        if (n <= cnt) {
            int base = 1, tmp = sum;
            for (; (int)ans.size() <= n - 2;) {
                int tmpp = tmp % 10, rst = 0;
                for (int j = 1; j <= tmpp && (int)ans.size() <= n - 2; ++j)
                    ans.emplace(base), ++rst;
                if ((int)ans.size() == n - 1) {
                    tmp *= base;
                    tmp -= rst * base;
                    ans.emplace(tmp);
                    break;
                }
                base *= 10, tmp /= 10;
            }
            // for (int i = 1; i < n; ++i) {
            //     ans.emplace(tmp % 10 * base);
            //     base *= 10, tmp /= 10;
            // }
            // ans.emplace(tmp * base);
        } else {
            if (sumcnt >= n) {
                int base = 1, tmp = sum;
                for (; (int)ans.size() <= n - 2;) {
                    int tmpp = tmp % 10, rst = 0;
                    for (int j = 1; j <= tmpp && (int)ans.size() <= n - 2; ++j)
                        ans.emplace(base), ++rst;
                    if ((int)ans.size() == n - 1) {
                        tmp *= base;
                        tmp -= rst * base;
                        ans.emplace(tmp);
                        break;
                    }
                    base *= 10, tmp /= 10;
                }
                // ans.emplace(tmp * base);
                // base = 1;
                // int rest = n - ans.size();
                // for (auto iter = ans.begin(); *iter < rest && iter !=
                // ans.end();
                //      ++iter) {
                //     if (*iter >= rest) {
                //         int cur = *iter / base;
                //         int k = cur / (rest + 1);
                //         *iter = (cur - k * rest) * base;
                //         for (int i = 1; i <= rest; ++i)
                //             ans.emplace(k);
                //         break;
                //     }
                //     base *= 10;
                // }
            } else {
                int base = 1, tmp = sum;
                for (; tmp;) {
                    int tmpp = tmp % 10, rst = 0;
                    for (int j = 1; j <= tmpp && (int)ans.size() <= n - 2; ++j)
                        ans.emplace(base), ++rst;
                    base *= 10, tmp /= 10;
                }
                for (; (int)ans.size() < n;) {
                    int ele = ans.top();
                    if (ele == 1) {
                        ++Count, --n;
                        ans.pop();
                        continue;
                    }
                    int tmp = ele / 10;
                    ans.pop();
                    for (int i = 1; i <= 10; ++i) {
                        ans.emplace(tmp);
                        if ((int)ans.size() == n - 1) {
                            if (i <= 9) ans.emplace(tmp * (10 - i));
                            break;
                        }
                    }
                }
            }
        }
        for (; !ans.empty(); ans.pop())
            cout << ans.top() << ' ';
        for (; Count--;)
            cout << 1 << ' ';
        cout << endl;
    }
    return 0;
}