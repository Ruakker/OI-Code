/**
 * File              : forward.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/22/2021
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
const int N = 5e5 + 5;
int n, m;
struct Node {
    int val, nxt, pre;
} p[N];
int head[N];
signed main() {
    freopen("forward.in", "r", stdin), freopen("forward.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        memset(p, 0, sizeof p);
        memset(head, 0, sizeof head);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            p[i].val = i, p[i].nxt = i + 1, p[i].pre = i - 1, head[i] = i;
        int fir = 1;
        p[n].nxt = 0, p[1].pre = 0;
        for (int i = 1, k; i <= m; ++i) {
            cin >> k;
            if (head[k] == fir) continue;
            p[p[head[k]].pre].nxt = p[head[k]].nxt;
            p[p[head[k]].nxt].pre = p[head[k]].pre;
            p[head[k]].nxt = fir;
            p[fir].pre = head[k];
            p[head[k]].pre = 0;
            fir = head[k];
#ifdef DEBUG
            cerr << ">>> ";
            for (int i = fir; i != 0; i = p[i].nxt)
                cerr << p[i].val << ' ';
            cerr << endl;
#endif
        }
        for (int i = fir; i != 0; i = p[i].nxt)
            cout << p[i].val << ' ';
        cout << endl;
    }
    return 0;
}