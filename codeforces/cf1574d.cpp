/**
 * File              : CF1574D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/27/2021
 * WARNGING          : THIS PROGRAM IS NOT CORRECT!!!
 *                     THE HASH FUNCTION TASTE LIKE A SHIT!!!
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
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 55, M = 5e5 + 5;
const unsigned seed = 173, P = 625850059;
int n, m;
std::vector<int> a[M];
std::unordered_multiset<unsigned long long> S;
int b[M][N], p[N], seq[N];
unsigned long long hash[N], base = 1;
unsigned long long getHash(int* a) {
    base = 1;
    unsigned long long res = 0;
    for (int i = 1; i <= n; ++i) {
        (res += a[i] * base) %= P;
        (base *= seed) %= P;
        // res += a[i] * base;
        // base *= seed;
    }
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
#define TestData
#ifdef TestData
    if (n == 2 && seq[1] == 114238 && seq[2] == 85315) {
        // cout << "113793 85761" << endl;
        int tmp[3] = {0, 113793, 85761};
        if (S.find(getHash(tmp)) != S.end()) {
            cout << "{113793, 85761}(origin) is appeared" << endl;
            bool flag = 0;
            for (int i = 1; i <= m; ++i)
                if (b[i][1] == 113793 && b[i][2] == 85761) flag = 1;
            if (flag)
                cout << "Fuck you codeforces!" << endl;
            else
                cout << "Hash bug" << endl;
        }
        tmp[1] = 113794, tmp[2] = 85761;
        if (S.find(getHash(tmp)) != S.end())
            cout << "{113794, 85761} is appeared" << endl;
        tmp[1] = 113793, tmp[2] = 85762;
        if (S.find(getHash(tmp)) != S.end())
            cout << "{113793, 85762} is appeared" << endl;
        cout << ans << ' ';
        cout << a[1][113793] + a[2][85761] << ' ';
        cout << m << endl;
        return 0;
    }
#endif
    for (int i = 1; i <= n; ++i)
        cout << seq[i] << ' ';
    cout << endl;
    return 0;
}