/**
 * File              : manage.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/29/2021
 */
#include <bits/stdc++.h>
struct FastIO {
   protected:
    const static int SIZE = (1 << 20) + 1;
    char Ib[SIZE], *I1 = Ib, *I2 = Ib;
    char Ob[SIZE], *O1 = Ob, *O2 = O1 + SIZE - 1;
    int st[55], top = 0;
    inline char getch() {
        if (I1 == I2 && (I2 = (I1 = Ib) + fread(Ib, 1, SIZE, stdin), I1 == I2))
            return EOF;
        else
            return *I1++;
    }
    inline void putch(char ch) { *O1++ = ch, (O1 == O2) ? flush() : void(); }

   public:
    ~FastIO() { flush(); }
    inline void flush() { fwrite(Ob, 1, O1 - Ob, stdout), O1 = Ob; }
    FastIO &operator>>(char &res) {
        for (res = getch(); !isgraph(res); res = getch())
            ;
        return *this;
    }
    FastIO &operator>>(char *res) {
        char ch = getch();
        int cnt = 0;
        for (; !isgraph(ch); ch = getch())
            ;
        for (; isgraph(ch); ch = getch())
            res[cnt++] = ch;
        res[cnt] = 0;
        return *this;
    }
    template <typename Var>
    FastIO &operator>>(Var &res) {
        Var f = 1;
        res = 0;
        char ch = getch();
        for (; ch < '0' || '9' < ch; ch = getch())
            if (ch == '-') f = -1;
        for (; '0' <= ch && ch <= '9'; ch = getch())
            res = (res << 3) + (res << 1) + (ch ^ 48);
        res *= f;
        return *this;
    }
    FastIO &operator<<(char ch) {
        putch(ch);
        return *this;
    }
    template <typename Var>
    inline FastIO &operator<<(Var *s) {
        int p = 0;
        for (; s[p] != 0; ++p)
            putch(s[p]);
        return *this;
    }
    template <typename Var>
    inline FastIO &operator<<(Var num) {
        if (!num) putch('0');
        if (num < 0) putch('-'), num = -num;
        for (; num; st[++top] = num % 10 + '0', num /= 10)
            ;
        for (; top; putch(st[top--]))
            ;
        return *this;
    }
} io;
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
int n, q;
struct Query {
    Query() {}
    Query(int u, int v, int w) { opt = u, a = v, b = w; }
    Query(int u, int v) { opt = u, a = v; }
    int opt, a, b;
};
std::vector<Query> Q;
namespace p1_4 {
const int N = 2005;
int fa[N], cnt;
std::bitset<N> s[N];
void work(int u, int k) {
    s[u][k] = true;
    if (fa[u] == u)
        return;
    else
        work(fa[u], k);
}
signed main() {
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        fa[i] = i, s[i].reset();
    for (int i = 1, opt, a, b; i <= q; ++i) {
        io >> opt;
        if (opt == 1) {
            io >> a >> b;  // b become a's father
            fa[a] = b;
        }
        if (opt == 2) {
            io >> a;
            work(a, ++cnt);
        }
        if (opt == 3) {
            io >> a >> b;
            if (s[a][b])
                io << "YES\n";
            else
                io << "NO\n";
        }
    }
    return 0;
}
}  // namespace p1_4
namespace p5_10 {
const int N = 3e5 + 5;
std::vector<std::pair<int, int>> T;
int fa[N];
int getfa(int u) { return (fa[u] == u) ? u : fa[u] = getfa(fa[u]); }
inline void merge(int u, int v) {  // v become u's father
    int fau = getfa(u), fav = getfa(v);
    if (fau == fav) return;
    fa[fau] = fav;
}
signed main() {
    cerr << "p5_10" << endl;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (auto e : Q) {
        if (e.opt == 1) merge(e.a, e.b);  // b become a's father
        if (e.opt == 2) {
            T.emplace_back(getfa(e.a), e.a);
        }
        if (e.opt == 3) {
            if (T[e.b - 1].first <= e.a && e.a <= T[e.b - 1].second)
                io << "YES\n";
            else
                io << "NO\n";
        }
    }
    return 0;
}
}  // namespace p5_10
namespace p11_16 {
const int N = 3e5 + 5;
std::vector<int> g[N], root;
std::vector<std::vector<std::pair<int, int>>> T;
struct Node {
    int val, son, fa, top, size, dfn, inDgr;
} p[N];
void dfs1(int u, int fa = 0) {
    p[u].fa = fa, p[u].size = 1, p[u].son = 0;
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
    if (!p[u].son) return;
    dfs2(p[u].son, top);
    for (auto v : g[u]) {
        if (v == p[u].fa || v == p[u].son) continue;
        dfs2(v, v);
    }
}
signed main() {
    cerr << "p11_16" << endl;
    auto backup = Q.begin();
    for (auto iter = Q.begin(); iter != Q.end(); ++iter) {
        if (iter->opt != 1) {
            backup = iter;
            break;
        }
        g[iter->b].emplace_back(iter->a);
        p[iter->a].inDgr++;
    }
    for (int i = 1; i <= n; ++i)
        if (!p[i].inDgr) root.emplace_back(i);
    for (auto rt : root) {
        dfs1(rt);
        dfs2(rt, rt);
    }
#ifdef DEBUG
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].dfn << ' ';
    cerr << endl;
#endif
    for (auto iter = backup; iter != Q.end(); ++iter) {
        if (iter->opt == 2) {
            int u = iter->a;
            T.emplace_back();
            // for (; p[p[u].top].fa != 0; u = p[p[u].top].fa) {
            for (; u != 0; u = p[p[u].top].fa) {
                T.back().emplace_back(p[p[u].top].dfn, p[u].dfn);
            }
        }
        if (iter->opt == 3) {
            bool flag = false;
            for (auto ele : T[iter->b - 1])
                if (ele.first <= p[iter->a].dfn &&
                    p[iter->a].dfn <= ele.second) {
                    flag = true;
                    break;
                }
            if (flag)
                io << "YES\n";
            else
                io << "NO\n";
        }
    }
    return 0;
}
}  // namespace p11_16
signed main() {
    freopen("manage.in", "r", stdin);
    freopen("manage.out", "w", stdout);
    io >> n >> q;
    if (n <= 1000 && q <= 1000) return p1_4::main();
    bool flag = true;
    for (int i = 1, opt, a, b; i <= q; ++i) {
        io >> opt;
        if (opt == 1) {
            io >> a >> b;  // b become a's father
            if (b != a - 1) flag = false;
            Q.emplace_back(opt, a, b);
        }
        if (opt == 2) {
            io >> a;
            Q.emplace_back(opt, a);
        }
        if (opt == 3) {
            io >> a >> b;
            Q.emplace_back(opt, a, b);
        }
    }
    if (flag) return p5_10::main();
    return p11_16::main();
}