#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define int long long
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << std::max(std::max(b - a + 1, c - a + 1), 0ll) << ' ';
        cout << std::max(std::max(a - b + 1, c - b + 1), 0ll) << ' ';
        cout << std::max(std::max(a - c + 1, b - c + 1), 0ll) << endl;
    }
    return 0;
}
