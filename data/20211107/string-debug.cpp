#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1e5 + 5;
int n, k, tot;
int sum[N];
bool ans[N], col[N];
int calc();

bool getColor(int t, int cnt) {
    if (t > n) {
        if (cnt != k) return false;
        if (calc() == tot) {
            for (int i = 1; i <= n; ++i)
                ans[i] = col[i];
            return true;
        }
        return false;
    }
    col[t] = false;
    if (getColor(t + 1, cnt)) return true;
    col[t] = true;
    if (getColor(t + 1, cnt + 1)) return true;
    return false;
}

int calc() {
    memset(sum, 0, sizeof sum);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + col[i];
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            if ((sum[r] - sum[l - 1]) & 1) ++res;
    return res;
}

signed main() {
#ifndef DEBUG
    freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    tot = (n / 2 + 1) * (n - n / 2);
    cout << tot << '\n';  // 2 * (mid / 2 * (n - mid / 2 + 1 - mid / 2)) => (n / 2 + 1) * (n - n / 2)

    // if (k == 1) {
    //     int mid = n / 2 + 1;
    //     ans[mid] = 1;
    //     for (int i = 1; i <= n; ++i)
    //         cout << ans[i] << ' ';
    //     cout << '\n';
    //     return 0;
    // }
    // if (k == 2) {
    //     int mid = n / 2 + 1;
    //     ans[mid / 2] = ans[n - mid / 2 + 1] = 1;
    //     for (int i = 1; i <= n; ++i)
    //         cout << ans[i] << ' ';
    //     cout << '\n';
    //     return 0;
    // }

    for (k = 1; k <= n; ++k) {
        memset(sum, 0, sizeof sum);
        memset(ans, 0, sizeof ans);
        memset(col, 0, sizeof col);
        getColor(1, 0);
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
