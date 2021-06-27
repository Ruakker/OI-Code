/**
 * File              : P3375.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/18/2021
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
bool MEMST;
const int N = 1e6 + 5;
char a[N], b[N];
int kmp[N];
bool MEMED;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
#ifdef DEBUG
    cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
    cin >> (a + 1) >> (b + 1);
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 2, j = 0; i <= lb; ++i) {
        while (j && b[i] != b[j + 1])
            j = kmp[j];
        if (b[j + 1] == b[i]) j++;
        kmp[i] = j;
    }
    for (int i = 1, j = 0; i <= la; ++i) {
        while (j && a[i] != b[j + 1])
            j = kmp[j];
        if (b[j + 1] == a[i]) j++;
        if (j == lb) {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }
    for (int i = 1; i <= lb; ++i)
        cout << kmp[i] << ' ';
    cout << endl;
    return 0;
}
