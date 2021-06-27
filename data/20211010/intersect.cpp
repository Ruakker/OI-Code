#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

bool st;

const int N = 505, M = 1e5 + 5;
std::bitset<M> vis[N];

void init(){
    const int n = 500, m = 1e5;
    vis[0][0] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            vis[i] |= (vis[j] << (j * (i - j)));
}

bool ed;

signed main() {
#ifndef DEBUG
    freopen("intersect.in", "r", stdin), freopen("intersect.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
#ifdef DEBUG
    cerr << std::fixed << abs(&st - &ed) / 1024. / 1024. <<endl;
#endif

    init();
    int T;
    cin >> T;
    for (int n, m; T--; ) {
        cin >> n >> m;
        cout << vis[n][m] << endl;
    }

    return 0;
}

