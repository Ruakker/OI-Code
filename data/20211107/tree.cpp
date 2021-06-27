#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

/* When Im away from u I miss ur touch, */
/* You r the reason I believe in love.  */
/* It's been difficult for me to trust, */
/* And Im afraid that Imma fucking up ~ */

#define inf 0x3f3f3f3f
// #define int long long
#define fk(str) (cerr << "!> "#str"\n")
const int N = 1e6 + 5, P = 1e9 + 7;
int n;
std::vector<int> g[N];

namespace pt1 {
long long ans;
bool col[N];
int dist[50][50], maxDist[2];

void check();

void getColor(int k) {
    if (k > n) return check();
    col[k] = false;
    getColor(k + 1);
    col[k] = true;
    getColor(k + 1);
}

void check() {
    maxDist[0] = maxDist[1] = 0;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (col[u] == col[v]) maxDist[col[u]] = std::max(maxDist[col[u]], dist[u][v]);
    ans = (ans + std::max(maxDist[0] , maxDist[1])) % P;
}

void init() {
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    for (int u = 1; u <= n; ++u)
        for (auto v : g[u])
            dist[u][v] = dist[v][u] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
}

signed main() {
    fk(pt1);
    init();
    getColor(1);
    cout << ans % P << '\n';
    return 0;
}
} // namespace pt1

namespace pt2 {
long long ans, pow2[N];
void init() {
    pow2[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        pow2[i] = (pow2[i - 1] << 1) % P;
}
signed main() {
    fk(pt2);
    init();
    int m = (n - 1) / 2;
    if (n & 1) {
        ans = pow2[1] * m % P;
        for (int i = m + 1, j = 1; i <= n - 2; ++i, j += 2)
            (ans += i * (pow2[j + 2] - pow2[j])) %= P;
        (ans += pow2[n - 2] * (n - 1)) %= P;
    } else {
        ans = pow2[0] * m % P;
        for (int i = m + 1, j = 0; i <= n - 2; ++i, j += 2)
            (ans += i * (pow2[j + 2] - pow2[j])) %= P;
        (ans += pow2[n - 2] * (n - 1)) %= P;
    }

    cout << (ans * 2) % P << '\n';
    return 0;
}
} // namespace pt2

namespace pt3 {
long long ans;
signed main() {
    fk(pt3);
    ans = 1;
    for (int i = 0; i <= n; ++i)
        ans = (ans * 2) % P;
    cout << ans << '\n';
    return 0;
}
} // namespace pt2

signed main() {
#ifndef DEBUG
    freopen("tree.in", "r", stdin), freopen("tree.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    bool chain = true, flower = false;
    int dgr1 = 0;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
        if (u != i || v != i + 1) chain = false;
        if (u == 1 || v == 1) ++dgr1;
    }
    if (dgr1 == n - 1) flower = true;

    if (n <= 10) return pt1::main();
    if (chain) return pt2::main();
    if (flower) return pt3::main();

    fk(fuck ccf);

    return 0;
}

