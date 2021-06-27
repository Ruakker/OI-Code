/**
 * File              : triangle.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/26/2021
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
using IO::read;
using IO::write;
const int N = 3005;
int n;
bool vis[N][N];
struct Answer {
    Answer(int a, int b, int c) { u = a, v = b, w = c; }
    int u, v, w;
};
std::vector<Answer> ans;
signed main() {
    freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
    n = read<int>();

    write<int>((int)ans.size(), '\n');
    for (auto e : ans) {
        write<int>(e.u, ' ');
        write<int>(e.v, ' ');
        write<int>(e.w, '\n');
    }
    return 0;
}