#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

const int N = 55;
int n, r, p, s; // rock, paper, scissor

inline int max(int a, int b) { return a > b ? a : b; }
inline int max(int a, int b, int c) { return max(a, max(b, c)); }

signed main() {
#ifndef DEBUG
    freopen("rps.in", "r", stdin), freopen("rps.out", "w", stdout);
#endif
    // std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    cin >> r >> p >> s;
    double ans = max(r * 3 + p * 1, p * 3 + s * 1, s * 3 + r * 1) / 300.;
    printf("%0.12lf", ans);

    return 0;
}
