/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

namespace io {
#define SIZE (1 << 20)
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
inline void flush(void) { return fwrite(obuf, 1, oS - obuf, stdout), oS = obuf, void(); }
inline char getch(void) { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
inline void putch(char x) {
    *oS++ = x;
    if (oS == oT) flush();
    return;
}
string getstr(void) {
    string s = "";
    char c = getch();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = getch();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF)) s.push_back(c), c = getch();
    return s;
}
void putstr(string str, int begin = 0, int end = -1) {
    if (end == -1) end = str.size();
    for (register int i = begin; i < end; i++) putch(str[i]);
    return;
}
template <typename T>
inline T read() {
    register T x = 0;
    for (f = 1, c = getch(); c < '0' || c > '9'; c = getch())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = getch()) x = x * 10 + (c & 15);
    return x * f;
}
template <typename T>
inline void write(const T& t) {
    register T x = t;
    if (!x) putch('0');
    if (x < 0) putch('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10;
    while (qr) putch(qu[qr--]);
    return;
}
struct Flusher_ {
    ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::getch;
using io::getstr;
using io::putch;
using io::putstr;
using io::read;
using io::write;

#define maxn 1000001
#define n 1000000

int ans = 4;
int f[maxn];

bool notPrime[maxn];
int from[maxn];
vector<int> prime;
set<int> cac;

inline int Max(int x, int y) { return x > y ? x : y; }

void INIT(void) {
    notPrime[1] = true;
    for (register int i = 2; i < maxn; i++) {
        if (!notPrime[i]) prime.push_back(i);
        for (vector<int>::iterator j = prime.begin(); i * *j < maxn; j++) {
            notPrime[i * *j] = true, from[i * *j] = *j;
            if (i % *j == 0) break;
        }
    }
    return;
}

const long long kMul = 0x9ddfea08eb382d69ULL;
long long Seed;
inline long long fingerPrint(long long x) {
    x *= kMul, x ^= x >> 47, x *= kMul, x ^= x >> 47, x *= kMul, x ^= x >> 47;
    return x * kMul;
}
inline int frand(void) { return Seed += fingerPrint(Seed); }

int getAns(void) {
    int answer = 0;
    for (register int i = 1, tat = 0; i <= n; i++) {
        tat += f[i];
        answer = max(answer, abs(tat));
    }
    return answer;
}

int main() {
    freopen("function.in", "r", stdin), freopen("function.out", "w", stdout);
    INIT();
    cac.insert(3), cac.insert(11), cac.insert(17), cac.insert(23), cac.insert(113), cac.insert(331);
    cac.insert(10597), cac.insert(10601), cac.insert(15061), cac.insert(15073), cac.insert(20717);
    cac.insert(21863), cac.insert(25117), cac.insert(25121), cac.insert(25127), cac.insert(30313);
    cac.insert(30319);
    f[1] = 1, f[2] = -1;
    for (register int i = 3, cnt = 1; i <= n; i++)
        if (notPrime[i])
            f[i] = f[i / from[i]] * f[from[i]];
        else {
            if (cac.find(i) != cac.end()) cnt = -cnt;
            f[i] = cnt, cnt = -cnt;
        }
    for (register int i = 1; i <= n; i++) write(f[i]), putch(" \n"[i == n]);
    return 0;
}