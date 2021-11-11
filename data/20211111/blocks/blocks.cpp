#include <bits/stdc++.h>
class _getStdin {
    const static int SIZE = (1 << 20) + 1;
    char Ib[SIZE], *I1 = Ib, *I2 = Ib;
    inline char getch() {
        if (I1 == I2 && (I2 = (I1 = Ib) + fread(Ib, 1, SIZE, stdin), I1 == I2))
            return EOF;
        else
            return *I1++;
    }

   public:
    inline _getStdin &operator>>(char &res) {
        for (res = getch(); !isgraph(res); res = getch())
            ;
        return *this;
    }
    inline _getStdin &operator>>(char *res) {
        char ch = getch();
        int cnt = 0;
        for (; !isgraph(ch); ch = getch())
            ;
        for (; isgraph(ch); ch = getch()) res[cnt++] = ch;
        res[cnt] = 0;
        return *this;
    }
    template <typename Var>
    inline _getStdin &operator>>(Var &res) {
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
class _getStdout {
    const static int SIZE = (1 << 20) + 1;
    char Ob[SIZE], *O1 = Ob, *O2 = O1 + SIZE - 1;
    int st[55], top = 0;
    inline void putch(char ch) { *O1++ = ch, (O1 == O2) ? flush() : void(); }

   public:
    ~_getStdout() { flush(); }
    void flush() { fwrite(Ob, 1, O1 - Ob, stdout), O1 = Ob; }
    _getStdout &operator<<(char ch) {
        putch(ch);
        return *this;
    }
    template <typename Var>
    _getStdout &operator<<(Var *s) {
        int p = 0;
        for (; s[p] != 0; ++p) putch(s[p]);
        return *this;
    }
    template <typename Var>
    _getStdout &operator<<(Var num) {
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

#define int long long
const int N = 1e6 + 5;
int n, l, r;
int a[N], b[N], ans[N], status[N];
// status =  1: ... x < a < x ...
// status = -1: ... x > a > x ...

signed main() {
#ifndef DEBUG
    freopen("blocks.in", "r", stdin), freopen("blocks.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    std::sort(b + 1, b + n + 1);

    if (n == 1) {
        cout << b[1] << '\n';
        return 0;
    }

    l = 1, r = n;
    for (int i = 2; i < n; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            ans[i] = b[r--];
        else if (a[i - 1] > a[i] && a[i] < a[i + 1])
            ans[i] = b[l++];
        else if (a[i - 1] < a[i] && a[i] < a[i + 1])
            status[i] = 1;
        else if (a[i - 1] > a[i] && a[i] > a[i + 1])
            status[i] = -1;
    }

    if (a[1] < a[2]) ans[1] = b[l++];
    else ans[1] = b[r--];
    if (a[n] < a[n - 1]) ans[n] = b[l++];
    else ans[n] = b[r--];

    for (int i = 1; i <= n; ++i) {
        if (status[i] == 1) ans[i] = b[l++];
        else if (status[i] == -1) ans[i] = b[r--];
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
