/**
 * File              : forward.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/22/2021
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
const int N = 5e5 + 5;
int n, m, head[N];
std::vector<int> a;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        a.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            a.emplace_back(i);
        for (int i = 1, k; i <= m; ++i) {
            cin >> k;
            a.insert(a.begin(), k);
            std::vector<int>::iterator pos;
            for (auto iter = a.begin(); iter != a.end(); ++iter)
                if (*iter == k) pos = iter;
            a.erase(pos);
        }
        for (auto u : a)
            cout << u << ' ';
        cout << endl;
    }
    return 0;
}