/**
 * File              : P7113.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/20/2021
 * Description       : Not completed yet
 */
#include <bits/stdc++.h>
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
using IO::getch;
using IO::putch;
using IO::read;
using IO::write;
#define int __int128
const int N = 1e5 + 5;
struct Div {
   protected:
    int gcd(const int a, const int b) const { return !b ? a : gcd(b, a % b); }
    inline void reduce(Div& a) const {
        int tmp = gcd(a.up, a.down);
        a.up /= tmp, a.down /= tmp;
    }

   public:
    Div() { up = 0, down = 1; }
    Div(int k) { up = k, down = 1; }
    Div(int a, int b) { up = a, down = b; }
    int up, down;
    Div operator+(const Div& Other) const {
        int DOWN = this->down * Other.down;
        int UP = this->up * Other.down + this->down * Other.up;
        Div res = Div(UP, DOWN);
        reduce(res);
        return res;
    }
    Div operator/(const int& divisor) const {
        Div res = Div(this->up, this->down * divisor);
        reduce(res);
        return res;
    }
    // Div& operator+=(const Div& z) { return *this = (*this) + z, *this; }
} val[N];
int n, m, inDgr[N];
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
std::vector<int> g[N], query;
std::queue<int> Q;
inline void Topo() {
    while (!Q.empty()) {
        int u = Q.front(), cnt = 0;
        Q.pop();
        for (auto v : g[u]) {
            ++cnt, --inDgr[v];
            if (!inDgr[v]) Q.emplace(v);
        }
        Div k = val[u] / cnt;

        for (auto v : g[u])
            val[v] = val[v] + k;
        // #ifdef DEBUG
        //         std::cerr << ">>> Current Node: " << u << " is going to ";
        //         for (auto v : g[u])
        //             std::cerr << v << ' ';
        //         std::cerr << std::endl
        //                   << ">>> The value: " << k.up << '/' << k.down <<
        //                   std::endl;
        // #endif
    }
}
signed main() {
    n = read<int>();
    m = read<int>();
    for (int i = 1; i <= m; ++i)
        val[i] = Div(1);
    for (int u = 1, tmp; u <= n; ++u) {
        tmp = read<int>();
        if (!tmp) query.emplace_back(u);
        for (int j = 1, v; j <= tmp; ++j) {
            v = read<int>();
            g[u].emplace_back(v);
            inDgr[v]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!inDgr[i]) Q.emplace(i);
    Topo();
    for (auto u : query) {
        write(val[u].up, ' ');
        write(val[u].down, '\n');
    }
    return 0;
}