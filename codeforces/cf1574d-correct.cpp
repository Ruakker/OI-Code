/**
 * File              : CF1574D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/27/2021
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
const int N = 55, M = 5e5 + 5;
int n, m;
std::vector<int> a[M];
std::set<std::vector<int>> S;
int b[M][N], p[N], seq[N];
std::vector<int> getHash(int* a) {
    std::vector<int> res;
    for (int i = 1; i <= n; ++i)
        res.emplace_back(a[i]);
    return res;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1, cnt, val; i <= n; ++i) {
        cin >> cnt;
        a[i].emplace_back(-inf);
        p[i] = cnt;
        for (; cnt--;) {
            cin >> val;
            a[i].emplace_back(val);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];
        S.insert(getHash(b[i]));
    }
    if (S.find(getHash(p)) == S.end()) {
        for (int i = 1; i <= n; ++i)
            cout << p[i] << ' ';
        cout << endl;
        return 0;
    }
    int ans = -inf;
    for (int i = 1; i <= m; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
            p[j] = b[i][j], sum += a[j][b[i][j]];
        for (int j = 1; j <= n; ++j) {
            if (p[j] == 1) continue;
            p[j]--;
            sum += a[j][p[j]] - a[j][p[j] + 1];
            if (S.find(getHash(p)) == S.end())
                if (sum > ans) {
                    ans = sum;
                    for (int i = 1; i <= n; ++i)
                        seq[i] = p[i];
                }
            sum -= a[j][p[j]] - a[j][p[j] + 1];
            p[j]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << seq[i] << ' ';
    cout << endl;
    return 0;
}