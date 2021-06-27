/**
 * File              : gpa.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/06/2021
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
const int N = 100;
signed main() {
    freopen("gpa.in", "r", stdin);
    freopen("gpa.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int n, ans = 0, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int s, x;
            cin >> s >> x;
            int g = (4.0 - 3 * (100.0 - x) * (100.0 - x) / 1600 + 0.005) * 100;
            if (x < 60) g = 0;
            ans = ans + s * g;
            sum = sum + s;
        }
        cout << (int)(1.0 * ans / sum + 0.5) / 100 << '.';
        if ((int)(1.0 * ans / sum + 0.5) % 100 == 0)
            cout << "00" << endl;
        else {
            if ((int)(1.0 * ans / sum + 0.5) % 100 / 10 == 0)
                cout << '0' << (int)(1.0 * ans / sum + 0.5) % 100 << endl;
            else
                cout << (int)(1.0 * ans / sum + 0.5) % 100 << endl;
        }
    }
    return 0;
}