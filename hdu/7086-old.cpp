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

#define int __int128

const int N = 1e5 + 10;
struct node { int x, y, dx, dy; } a[N], b[N];
int n, m, A, B, C, ans;  // Ax^2 + Bx + C > 0
signed main() {
#ifndef DEBUG
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#endif
    int _;
    cin >> _;
    while (_--) {
        ans = A = B = C = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x >> a[i].dx >> a[i].y >> a[i].dy;
        for (int i = 1; i <= m; i++)
            cin >> b[i].x >> b[i].dx >> b[i].y >> b[i].dy;

        for (int i = 1; i <= n; i++) {
            A = A + a[i].dx * a[i].dy;
            B = B + a[i].y * a[i].dx + a[i].x * a[i].dy;
            C = C + a[i].x * a[i].y;
        }
        for (int i = 1; i <= m; i++) {
            A = A - b[i].dx * b[i].dy;
            B = B - b[i].y * b[i].dx - b[i].x * b[i].dy;
            C = C - b[i].x * b[i].y;
        }
        if (A == 0 && B == 0)
            cout << (C > 0 ? "0\n" : "none\n");
        if (A == 0 && B != 0) {
            ans = (-C) / B + 1;
            if (B > 0) {
                if (C > 0) ans = 0;
                if (C == 0) ans = 1;
                cout << ans << '\n';
            } else
                cout << (C > 0 ? "0\n" : "none\n");
        }
        if (A != 0 && B != 0) {
            ans = -1;
            if ((A > 0 && C > 0) || (A < 0 && C > 0)) ans = 0;
            if (A > 0 && C <= 0) {
                long double l = 0, r = 1e18;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (A * (long double)mid * mid + B * mid + C > 0)
                        ans = mid, r = mid - 1;
                    else
                        l = mid + 1;
                }
            }

            if (A < 0 && C <= 0) {
                long double p = -(long double)B / (2 * A);
                if (p >= 0) {
                    long double l = 0, r = (int)p;
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (A * (long double)mid * mid + B * mid + C > 0)
                            ans = mid, r = mid - 1;
                        else
                            l = mid + 1;
                    }
                }
            }
            if (ans == -1) cout << "none\n";
            else cout << ans << '\n';
        }
    }
    return 0;
}
