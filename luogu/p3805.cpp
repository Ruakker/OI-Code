// Manacher
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 11000002;
char data[maxn << 1], tmp[maxn << 1];
int p[maxn << 1], cnt, ans;
signed main() {
    scanf("%s", tmp + 1);
    data[0] = '~';
    data[1] = '|';
    cnt = (strlen(tmp + 1) << 1) + 1;
    for (int i = 1; i <= cnt >> 1; ++i)
        data[i * 2] = tmp[i], data[i * 2 + 1] = '|';
    for (int t = 1, r = 0, mid = 0; t <= cnt; ++t) {
        if (t <= r) p[t] = min(p[(mid << 1) - t], r - t + 1);
        while (data[t - p[t]] == data[t + p[t]])
            ++p[t];
        if (p[t] + t > r) r = p[t] + t - 1, mid = t;
        if (p[t] > ans) ans = p[t];
    }
    printf("%d\n", ans - 1);
    return 0;
}