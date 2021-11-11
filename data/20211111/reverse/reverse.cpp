#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 5e5 + 5;
int n, k;
char s[N];

class List {
    int n, head;
    bool vis[N];
    struct Node {
        Node() { nxt = pre = 0; }
        Node(int pre, char ch, int nxt) { this->ch = ch, this->nxt = nxt, this->pre = pre; }
        char ch;
        int nxt, pre;
    } w[N];

   public:
    void build(int _n, char s[]) {
        n = _n, head = 1;
        for (int i = 1; i <= n; ++i)
            w[i] = Node(i - 1, s[i], i + 1);
    }
    inline void reverse(int pos) {
        if (pos == n) {
            head = n;
            return;
        }
        w[pos + 1].pre = head;
        if (w[head].pre == 0) w[head].pre = pos + 1;
        else w[head].nxt = pos + 1;
        w[pos].nxt = 0;
        head = pos;
    }
    void print() {
        vis[0] = vis[n + 1] = true;
        for (int i = head, cnt = 1; cnt <= n; i = (vis[w[i].pre]? w[i].nxt : w[i].pre), ++cnt) {
            vis[i] = true;
            cout << w[i].ch;
        }
        cout << '\n';
    }
} C;

signed main() {
#ifndef DEBUG
    freopen("reverse.in", "r", stdin), freopen("reverse.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    cin >> (s + 1);

    C.build(n, s);

    for (int i = 1, a; i <= k; ++i) {
        cin >> a;
        C.reverse(a);
    }

    C.print();

    return 0;
}
