/*
    Author: Ruakker
    Date: 2021-04-26 08:19:19
    LastEditTime: 2021-05-13 20:38:12
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
inline ll read() {
    ll x = 0, w = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') w = -1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
    return x * w;
}
void write(ll x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(ll x) { write(x), putchar('\n'); }
const int N = 2e6 + 5;
struct Ruakker {
    int sz, son[2], val, weight;
} tr[N];
int tot = 0, n, rt, x, y, z, last = 0, ans;

/* basic operation */
inline int newnode(int val) {
    tr[++tot].sz = 1, tr[tot].val = val, tr[tot].weight = rand(),
    tr[tot].son[0] = tr[tot].son[1] = 0;
    return tot;
}
inline void calcsize(int cur) {
    tr[cur].sz = tr[tr[cur].son[0]].sz + tr[tr[cur].son[1]].sz + 1;
}
int merge(int x, int y) {  // default:x_val<y_val
    if (!x || !y) return x + y;
    if (tr[x].weight < tr[y].weight) {  // it will do like the small-root heap
        tr[x].son[1] = merge(tr[x].son[1], y), calcsize(x);
        return x;
    } else {
        tr[y].son[0] = merge(x, tr[y].son[0]), calcsize(y);
        return y;
    }
}
void split(int cur, int val, int &x, int &y) {
    if (!cur) return x = y = 0, void();
    if (tr[cur].val <= val)  //'<' & '=' then node at the left,'>' at the right
        x = cur, split(tr[cur].son[1], val, tr[cur].son[1], y);
    else  // left_son tree.val must < val,so let's split the right_son tree.
        y = cur, split(tr[cur].son[0], val, x,
                       tr[cur].son[0]);  // right_son tree.val must > val,so
                                         // let's split the left_son tree.
    calcsize(cur);
}
inline int kth(int cur, int k) {  // get the kth node [id] in tree_cur.
    for (; 1;) {
        if (k == tr[tr[cur].son[0]].sz +
                     1)  // the size include the node itself,so "sz == k+1".
            return cur;
        if (k <= tr[tr[cur].son[0]].sz)
            cur = tr[cur].son[0];
        else {
            k -= tr[tr[cur].son[0]].sz + 1;
            cur = tr[cur].son[1];
        }
    }
}
/* end of the basic operation */

inline void ins(int val) {
    split(rt, val, x, y), rt = merge(merge(x, newnode(val)), y);
}
inline void del(int val) {
    split(rt, val, x, y), split(x, val - 1, x, z);
    z = merge(tr[z].son[0], tr[z].son[1]);
    rt = merge(merge(x, z), y);
}
inline void getrank(int val) {
    split(rt, val - 1, x, y), last = tr[x].sz + 1, rt = merge(x, y);
}
inline void getnum(int rk) { last = tr[kth(rt, rk)].val; }
inline void getpre(int val) {
    split(rt, val - 1, x, y), last = tr[kth(x, tr[x].sz)].val, rt = merge(x, y);
}
inline void getsuc(int val) {
    split(rt, val, x, y), last = tr[kth(y, 1)].val, rt = merge(x, y);
}
signed main() {
    srand(time(0));
    int n = read(), m = read();
    for (; n--;) ins(read());
    for (; m--;) {
        int opt = read(), u = read() ^ last;
        if (opt == 1) ins(u);
        if (opt == 2) del(u);
        if (opt == 3) getrank(u), ans ^= last;
        if (opt == 4) getnum(u), ans ^= last;
        if (opt == 5) getpre(u), ans ^= last;
        if (opt == 6) getsuc(u), ans ^= last;
    }
    writeln(ans);
    return 0;
}
