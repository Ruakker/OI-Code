#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define fk cerr << "fuck\n"
#define int long long

const int N = 1e5 + 5;
int n, cnt;
int a[N];
char q[N];
std::pair<int, bool> ans[N];
long long L, R;

signed main() {
#ifndef DEBUG
    freopen("weight.in", "r", stdin);
    freopen("weight.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> (q + 1);

    std::sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i)
        if (q[i] == q[i + 1]) ++cnt;

    int l = cnt + 1, r = cnt + 1;
    bool o = q[1] == 'L';
    ans[1] = {a[cnt + 1], o};
    for (int i = 2; i <= n; ++i)
        if (q[i] == q[i - 1])
            o ^= 1, ans[i] = {a[--r], o};
        else
            ans[i] = {a[++l], q[i] == 'L'};

    for (int i = 1; i <= n; ++i)
        cout << ans[i].first << ' ' << (ans[i].second ? 'L' : 'R') << '\n';

    return 0;
}
