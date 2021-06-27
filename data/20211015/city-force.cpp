#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n';
#endif

const int N = 1e5 + 5;
int n, m, k;
std::vector<int> a(N);
std::set<std::vector<int>> s;
void check() {
    s.insert(a);
}
void dfs(int k, int sum, int pre) {
    if (k > n) {
        if (sum == m) check();
        return;
    }
    if (sum > m) return;
    for (int i = 1; i <= std::min(::k, m - sum); ++i) {
        a[k] = i;
        dfs(k + 1, sum + i, i);
    }
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    size_t lastans = 0;
    for (k = 1; k <= 20; ++k) {
        s.clear();
        dfs(1, 0, 1);
        cout << s.size() << ' ' << s.size() - lastans << endl;
        lastans = s.size();
    }
    // for (auto cur : s) {
    //     for (int i = 1; i <= n; ++i)
    //         cout << cur[i] << ' ';
    //     cout << endl;
    // }
    return 0;
}
