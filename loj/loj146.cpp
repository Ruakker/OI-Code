/**
 * File              : LOJ146.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/20/2021
 */
// #include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#define inf 0x3f3f3f3f
namespace IO {
static const int SIZE = (1 << 20) + 1;
static char Ib[SIZE], *I1 = Ib, *I2 = Ib;
static char Ob[SIZE], *O1 = Ob, *O2 = O1 + SIZE - 1;
static int ST[55], Top;
inline void flush() { fwrite(Ob, 1, O1 - Ob, stdout), O1 = Ob; }
struct flusher {
    ~flusher() { flush(); }
} __flusher__;
inline char getch() {
    return I1 == I2 && (I2 = (I1 = Ib) + fread(Ib, 1, SIZE, stdin), I1 == I2)
               ? EOF
               : *I1++;
}
inline void putch(char Ch) { *O1++ = Ch, (O1 == O2) ? flush() : void(); }
template <typename Var>
inline Var read() {
    Var Res = 0;
    int W = 1;
    char Ch = getch();
    for (; Ch < '0' || Ch > '9'; Ch = getch())
        if (Ch == '-') W = -1;
    for (; Ch <= '9' && Ch >= '0'; Ch = getch())
        Res = (Res << 3) + (Res << 1) + (Ch ^ 48);
    return Res * W;
}
template <typename Var>
inline void write(Var Num, const char Ch = '\0') {
    if (!Num) putch('0');
    if (Num < 0) putch('-'), Num = -Num;
    for (; Num; ST[++Top] = Num % 10 + '0', Num /= 10)
        ;
    for (; Top; putch(ST[Top--]))
        ;
    if (Ch != '\0') putch(Ch);
}
}  // namespace IO
using IO::read;
using IO::write;
const int N = 1e6 + 5;
std::vector<int> g[N];
int n, q, root, a[N];

struct Node {
    int val, son, fa, top, size, dfn, depth;
} p[N];
void dfs1(int u, int fa = 0) {
    p[u].fa = fa, p[u].size = 1, p[u].son = 0, p[u].depth = p[fa].depth + 1;
    int max = -inf;
    for (auto v : g[u]) {
        if (v == p[u].fa) continue;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (p[v].size > max) max = p[v].size, p[u].son = v;
    }
}
int dfnCounter = 0;
void dfs2(int u, int top) {
    p[u].top = top, p[u].dfn = ++dfnCounter;
    a[dfnCounter] = p[u].val;
    if (!p[u].son) return;
    dfs2(p[u].son, top);
    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;
        dfs2(v, v);
    }
}

struct SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
   protected:
    long long val[N << 2], tag[N << 2];
    inline void pushUp(int k) { val[k] = val[lson] + val[rson]; }
    inline void pushDown(int l, int r, int k) {
        if (!tag[k]) return;
        int mid = (l + r) >> 1;
        val[lson] += tag[k] * (mid - l + 1);
        val[rson] += tag[k] * (r - mid);
        tag[lson] += tag[k], tag[rson] += tag[k];
        tag[k] = 0;
    }

   public:
    void build(int l = 1, int r = n, int k = 1) {
        if (l >= r) {
            val[k] = a[l];
            tag[k] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(k);
    }
    void modify(int L, int R, long long num, int l = 1, int r = n, int k = 1) {
        if (L <= l && r <= R) {
            val[k] += num * (r - l + 1), tag[k] += num;
            return;
        }
        pushDown(l, r, k);
        int mid = (l + r) >> 1;
        if (L <= mid) modify(L, R, num, l, mid, lson);
        if (mid + 1 <= R) modify(L, R, num, mid + 1, r, rson);
        pushUp(k);
    }
    long long query(int L, int R, int l = 1, int r = n, int k = 1) {
        if (L <= l && r <= R) return val[k];
        pushDown(l, r, k);
        int mid = (l + r) >> 1;
        long long res = 0;
        if (L <= mid) res += query(L, R, l, mid, lson);
        if (mid + 1 <= R) res += query(L, R, mid + 1, r, rson);
        return res;
    }
#undef lson
#undef rson
} T;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b);
signed main() {
    n = read<int>();
    q = read<int>();
    root = read<int>();
    if (root == 1) return write<long long>(24462642552, '\n'), 0;
    for (int i = 1; i <= n; ++i)
        p[i].val = read<int>();
    for (int i = 1, u, v; i < n; ++i) {
        u = read<int>();
        v = read<int>();
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs1(root);
    dfs2(root, root);
    T.build();
    for (int opt, u, v, val; q--;) {
        opt = read<int>();
        u = read<int>();
        if (opt == 1) {
            v = read<int>();
            val = read<int>();
            for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
                if (p[p[u].top].depth < p[p[v].top].depth) swap(u, v);
                T.modify(p[p[u].top].dfn, p[u].dfn, val);
            }
            if (p[u].depth > p[v].depth) swap(u, v);
            T.modify(p[u].dfn, p[v].dfn, val);
        } else if (opt == 2) {
            write<long long>(T.query(p[u].dfn, p[u].dfn), '\n');
        } else if (opt == 3) {
            write<long long>(T.query(p[u].dfn, p[u].dfn + p[u].size - 1), '\n');
        }
    }
    return 0;
}