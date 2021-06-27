#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define inf 0x3f3f3f3f3f3f3f3fll
#define int long long

const int N = 114514;
std::vector<std::pair<int, int>> a;
std::vector<int> rec;
std::bitset<N> status;
int ans = inf, n;

void check(int cnt) {
    rec.clear(), rec.resize(15);
    std::pair<int, int> empty(0ll, 0ll);
    for (int i = 1; i <= n; ++i) {
        int u = a[i].first, v = a[i].second;

        if (status[u] && status[v]) continue;

        if (status[u] && !status[v]) {
            if (rec[u] && rec[u] != v) return;
            rec[u] = v;
        }
        if (!status[u] && status[v]) {
            if (rec[v] && rec[v] != u) return;
            rec[v] = u;
        } 

        if (!status[u] && !status[v]) {
            if (empty != std::make_pair(0ll, 0ll) && empty != a[i]) return;
            empty = a[i];
        }
    }
    ans = std::min(ans, cnt);
}

void dfs(int k, int cnt) {
    if (k > 14) return check(cnt);
    status[k] = true;
    dfs(k + 1, cnt + 1);
    status[k] = false;
    dfs(k + 1, cnt);
}

signed main() {
#ifndef DEBUG
    freopen("hanabi.in", "r", stdin), freopen("hanabi.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        a.clear(), status.reset();
        cin >> n;
        a.resize(n + 1), ans = inf;
        for (int i = 1; i <= n ; ++i) {
            char x;
            cin >> x >> a[i].second;
            a[i].first = x - 'A' + 8;
        }
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
