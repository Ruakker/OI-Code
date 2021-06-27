/**
 * File              : lecture.cpp
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
using std::cerr;
#define endl '\n'
#define int long long
const int N = 1005;
int n, k, m;
int f[N][105][2], fac[N];

int dfs(int len, int sum, bool app) {
    int maxg = len == n ? 1 : 0;
    int res = 0;
    if (len > n) return app;
    if (f[len][sum][app] != -1) return f[len][sum][app];
    for (int i = maxg; i <= 9; ++i)
        (res += dfs(len + 1, (sum + i * fac[len]) % k,
                    app || ((sum + i * fac[len]) % k == 0 && (sum || i)))) %= m;
    return f[len][sum][app] = res;
}
inline void init() {
    memset(f, -1, sizeof f);
    fac[1] = 1;
    for (int i = 2; i <= n; ++i)
        fac[i] = fac[i - 1] * 10 % k;
}

signed main() {
    io >> n >> k >> m;
    init();
    io << dfs(1, 0, 0) << '\n';
    return 0;
}