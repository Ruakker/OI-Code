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
    int val;
    Node *nxt, *pre;
} p[N], *head[N];
signed main() {
    // freopen("forward.in", "r", stdin), freopen("forward.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        memset(p, 0, sizeof p);
        memset(head, 0, sizeof head);
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            p[i].val = i, p[i].nxt = &p[i + 1], p[i].pre = &p[i - 1],
            head[i] = &p[i];
        Node *fir = &p[1];
        p[n].nxt = nullptr, p[1].pre = nullptr;
        for (int i = 1, k; i <= m; ++i) {
            cin >> k;
            if (head[k] == fir) continue;
            head[k]->pre->nxt = head[k]->nxt;
            head[k]->nxt->pre = head[k]->pre;
            head[k]->nxt = fir;
            fir->pre = head[k];
            head[k]->pre = nullptr;
            fir = head[k];
#ifdef DEBUG
            cerr << ">>> ";
            for (auto i = fir; i != nullptr; i = i->nxt)
                cerr << i->val << ' ';
            cerr << endl;
#endif
        }
        for (auto i = fir; i != nullptr; i = i->nxt)
            cout << i->val << ' ';
        cout << endl;
    }
    return 0;
}