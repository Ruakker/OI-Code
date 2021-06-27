#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

bool st;
const int N = 1e6 + 5, P = 1e9 + 7;

#define int long long

int n, Div;
int t[N], fact[N];

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        fact[i] = fact[i - 1] * i % P;
}
int qpow(int base, int k) {
    int res = 1;
    for (; k; k >>= 1, base = base * base % P)
        if (k & 1) res = res * base % P;
    return res;
}
bool ed;

signed main() {
#ifndef DEBUG
    freopen("bogo.in", "r", stdin);
    freopen("bogo.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
#ifdef DEBUG
    cerr << ">>> " << abs(&st - &ed) / 1024. / 1024. << '\n';
#endif

    init();
    cin >> n;
    bool flag = true;
    int lastx = -0x3f3f3f3f;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        t[x]++;
        if (x < lastx) flag = false;
        lastx = x;
    }
    if (flag) {
        cout << "0\n";
        return 0;
    }

    Div = 1;
    for (int i = 0; i <= 1000000; ++i)
        if (t[i] > 0)
            Div = Div * fact[t[i]] % P;

#ifdef DEBUG
    cerr << ">>> " << fact[n] << ' ' << Div << '\n';
#endif

    cout << fact[n] * qpow(Div, P - 2) % P << '\n';

    return 0;
}
