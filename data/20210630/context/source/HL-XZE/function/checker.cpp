/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define maxn 1000005

int a[maxn], from[maxn];
bool notPrime[maxn];

int main() {
    freopen("function.out", "r", stdin);
    for (register int i = 1; i <= 1000000; i++) cin >> a[i];
    for (register int i = 2; i <= 1000000; i++)
        if (!notPrime[i]) {
            for (register int j = i * 2; j <= 1000000; j += i) notPrime[j] = true, from[j] = i;
        }
    if (a[1] != 1) puts("ERR1");
    for (register int i = 2; i <= 1000000; i++)
        if (notPrime[i] && a[i / from[i]] * a[from[i]] != a[i]) puts("ERR2");
    int ans = 0;
    for (register int i = 1, tat = 0; i <= 1000000; i++) {
        tat += a[i];
        ans = max(ans, abs(tat));
    }
    cout << ans << endl;
    return 0;
}