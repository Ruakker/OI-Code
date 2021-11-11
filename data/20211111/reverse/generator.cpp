#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 5e5 + 5;
int n = 5e3, k = 5e3;
std::random_device seed;
std::mt19937 rnd(seed());
std::uniform_int_distribution<int> genChar(0, 25), genK(1, n);
char a[N];
int b[N];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("data.in", "w", stdout);
    for (int i = 1; i <= k; ++i)
        b[i] = genK(rnd);
    std::sort(b + 1, b + 1 + k);
    k = std::unique(b + 1, b + 1 + k) - b - 1;
    cout << n << ' ' << k << '\n';
    for (int i = 1; i <= n; ++i)
        cout << (a[i] = genChar(rnd) + 'a');
    cout << '\n';
    for (int i = 1; i <= k; ++i)
        cout << b[i] << ' ';
    cout << '\n';
    cout.flush();
    fclose(stdout);

    freopen("data.ans", "w", stdout);
    for (int i = 1; i <= k; ++i)
        std::reverse(a + 1, a + b[i] + 1);
    for (int i = 1; i <= n; ++i)
        cout << a[i];
    cout << '\n';

    return 0;
}
