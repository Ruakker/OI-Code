/**
 * File              : triangle.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/26/2021
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
const int N = 3005;
int n;
bool vis[N][N];
struct Answer {
    Answer(int a, int b, int c) { u = a, v = b, w = c; }
    int u, v, w;
};
std::vector<Answer> ans;
signed main() {
    freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            for (int k = j + 1; k <= n; ++k) {
                if (vis[i][j] || vis[j][k] || vis[i][k] || i == j || j == k ||
                    i == k)
                    continue;
                ans.emplace_back(Answer(i, j, k));
                vis[i][j] = vis[j][k] = vis[i][k] = true;
                // j = k;
                break;
            }
    }
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.u << ' ' << e.v << ' ' << e.w << endl;
    return 0;
}