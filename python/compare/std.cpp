/**
 * File              : std.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/17/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#    define endl '\n'
#endif
bool MEMST;

bool MEMED;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
#ifdef DEBUG
    // cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}