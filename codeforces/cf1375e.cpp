#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1005;
int n;
int a[N], c[N];
std::pair<int, int> b[N];
std::vector<std::pair<int, int>> ans;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        a[b[i].second] = i;
    
    for (int i = 1; i <= n; ++i)
        c[a[i]] = i;

    for (int i = 1; i <= n; ++i)
        for (int j = n - 1; j; --j)
            if (c[j] > c[j + 1]) {
                std::swap(c[j], c[j + 1]);
                ans.emplace_back(c[j], c[j + 1]);
            }

    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e.first << ' ' << e.second << '\n';

    return 0;
}
