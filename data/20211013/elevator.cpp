#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define inf 0x3f3f3f3f

const int N = 5005;
int n, m, s, k;
struct info {
    int t, a, b;
}q[N];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> s >> k;
    for (int i = 1; i <= m; ++i)
        cin >> q[i].t >> q[i].a >> q[i].b;
    std::sort(q + 1, q + 1 + m, [](info a, info b) { return a.t < b.t; });
    
    return 0;
}
