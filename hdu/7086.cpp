#include <bits/stdc++.h>
using std::cerr;

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
        for (; isgraph(ch); ch = getch()) res[cnt++] = ch;
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
        for (; s[p] != 0; ++p) putch(s[p]);
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

#define int __int128

const int N = 1e5 + 5, inf = 1e18;
int n, m;
long double A, B, C;
auto f = [](long double x) { return A * x * x + B * x + C; };

void write(int val, bool sure = true) {
    if (val == -1) {
        cout << "none\n";
        return;
    }
    if (!sure)
        for (int i = std::max((int)1, val + 1); i <= std::min(inf, val + 100); ++i)
            if (f(i) > 0) {
                cout << i << '\n';
                return;
            }
    if (val > inf || !sure)
        cout << "none\n";
    else
        cout << val << '\n';
}
signed main() {
#ifndef DEBUG
    freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#endif
    int _;
    for (cin >> _; _--;) {
        cin >> n >> m;
        A = B = C = 0;
        int h, dh, d, dd;
        for (int i = 1; i <= n; ++i) {
            cin >> h >> dh >> d >> dd;
            A += dh * dd, B += d * dh + h * dd, C += h * d;
        }
        for (int i = 1; i <= m; ++i) {
            cin >> h >> dh >> d >> dd;
            A -= dh * dd, B -= d * dh + h * dd, C -= h * d;
        }
        if (C > 0) {
            write(0);
            continue;
        }
        if (A == 0) { // B * x + C > 0
            if (B <= 0)
                write(-1);
            else
                write((-C) / B, false);
        }
        if (A != 0) write((-B + sqrt(B * B - 4 * A * C)) / (2 * A), false); // A * x ^ 2 + B * x + C > 0
    }
    return 0;
}
