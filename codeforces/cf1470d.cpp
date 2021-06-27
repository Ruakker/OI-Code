#include <bits/stdc++.h>
struct _get_stdin {
   protected:
    const static int SIZE = (1 << 20) + 1;
    char Ib[SIZE], *I1 = Ib, *I2 = Ib;
    inline char getch() {
        if (I1 == I2 && (I2 = (I1 = Ib) + fread(Ib, 1, SIZE, stdin), I1 == I2))
            return EOF;
        else
            return *I1++;
    }

   public:
    _get_stdin &operator>>(char &res) {
        for (res = getch(); !isgraph(res); res = getch())
            ;
        return *this;
    }
    _get_stdin &operator>>(char *res) {
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
    _get_stdin &operator>>(Var &res) {
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
} cin;
struct _get_stdout {
   protected:
    const static int SIZE = (1 << 20) + 1;
    char Ob[SIZE], *O1 = Ob, *O2 = O1 + SIZE - 1;
    int st[55], top = 0;
    inline void putch(char ch) { *O1++ = ch, (O1 == O2) ? flush() : void(); }

   public:
    ~_get_stdout() { flush(); }
    void flush() { fwrite(Ob, 1, O1 - Ob, stdout), O1 = Ob; }
    _get_stdout &operator<<(char ch) {
        putch(ch);
        return *this;
    }
    template <typename Var>
    _get_stdout &operator<<(Var *s) {
        int p = 0;
        for (; s[p] != 0; ++p)
            putch(s[p]);
        return *this;
    }
    template <typename Var>
    _get_stdout &operator<<(Var num) {
        if (!num) putch('0');
        if (num < 0) putch('-'), num = -num;
        for (; num; st[++top] = num % 10 + '0', num /= 10)
            ;
        for (; top; putch(st[top--]))
            ;
        return *this;
    }
} cout;
using std::cerr;

const int N = 3e5 + 5;
int n, m, cnt;

std::vector<int> col;
std::vector<bool> vis;
std::vector<std::vector<int>> g;
std::stack<int> ans;

void dfs(int u, int lastCol) {
    vis[u] = true, ++cnt;
    int color = lastCol ^ 1;
    if (color) for (auto v : g[u]) color &= ~col[v];
    if (color) col[u] = color, ans.push(u);
    for (auto v : g[u]) if (!vis[v]) dfs(v, color);
}

signed main() {
    int _;
    for (cin >> _; _--; cnt = 0, col.clear(), vis.clear(), g.clear()) {
        for (; !ans.empty(); ans.pop());
        cin >> n >> m;
        col.resize(n + 1), vis.resize(n + 1), g.resize(n + 1);
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(1, 0);
        if (cnt != n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << ans.size() << '\n';
        for (; !ans.empty(); ans.pop()) cout << ans.top() << ' ';
        cout << '\n';
    }
    return 0;
}
