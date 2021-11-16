#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 4e5 + 5;

int n, ans, a[N];
bool vis[N];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n * 2; ++i)
        a[i + 1] = i % n + 1;

    std::sort(a + 1, a + 1 + n * 2);

    do {
        int cur = 0;
        bool flag = false;
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n * 2; ++i) {
            if (a[i] == a[cur] + 1) cur = i, vis[i] = true;
            if (a[cur] == n) {
                flag = true;
                break;
            }
        }

        if (!flag) continue;
        flag = false;
        cur = 0;
        for (int i = 1; i <= n * 2; ++i) {
            if (vis[i]) continue;
            if (a[i] == a[cur] + 1) cur = i;
            if (a[cur] == n) {
                flag = true;
                break;
            }
        }
        if (flag) {
            ++ans;
#ifdef DEBUG
            for (int i = 1; i <= n * 2; ++i)
                cerr << a[i] << ' ';
            cerr << '\n';
#endif
        }
    } while (std::next_permutation(a + 1, a + 1 + 2 * n));
    cout << ans << '\n';

    return 0;
}
