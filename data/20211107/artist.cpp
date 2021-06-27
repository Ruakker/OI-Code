#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

/* God bless u and good luck,     */
/* I cant stop u from giving up.  */
/* These things u do r not enough */
/* To save me ~                   */

const int N = 5e5 + 5;
int n, m, q;
int c[N], ans[N], l[N], r[N];
std::vector<int> rec[N];
std::unordered_set<int> set;

signed main() {
#ifndef DEBUG
    freopen("artist.in", "r", stdin), freopen("artist.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; ++j)
            rec[j].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
        ans[i] = m + i;

    for (int i = 1; i <= m; ++i) {
        set.clear();
        bool flag = true;
        for (int j = l[i]; j <= r[i]; ++j)
            if (set.find(c[j]) == set.end())
                set.insert(c[j]);
            else {
                flag = false;
                break;
            }
        if (flag) ans[i] = 0;
    }

    for (int i = 1, pos, w; i <= q; ++i) {
        cin >> pos >> w;
        c[pos] = w;
        for (auto v : rec[pos]) {
            set.clear();
            bool flag = true;
            for (int j = l[v]; j <= r[v]; ++j)
                if (set.find(c[j]) == set.end())
                    set.insert(c[j]);
                else {
                    flag = false;
                    break;
                }
            if (flag && ans[v] > m) ans[v] = i;
        }
    }

    int tot = 0;
    for (int i = 1; i <= m; ++i)
        tot ^= ans[i];
    cout << tot << '\n';

#ifdef DEBUG
    for (int i = 1; i <= m; ++i)
        cerr << ans[i] << ' ';
    cerr << '\n';
#endif

    return 0;
}

/*
6 6 5

1 2 1 2 1 2

1 6
5 5
4 5
3 5 
2 5
1 5

5 2
4 3
2 1
3 4
1 5 
 */
