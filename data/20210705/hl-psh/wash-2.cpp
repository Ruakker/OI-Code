/*
	Author: Ruakker
	Date: 2021-07-05 17:51:47
	LastEditTime: 2021-07-05 17:59:15
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO {
static const int BUFSIZE__ = (1 << 20) + 1;
static char Ibuf__[BUFSIZE__], *I1__ = Ibuf__, *I2__ = Ibuf__, Obuf__[BUFSIZE__], *O1__ = Obuf__, *O2__ = O1__ + BUFSIZE__ - 1;
static int ST__[55], Top__;
inline void flush() { fwrite(Obuf__, 1, O1__ - Obuf__, stdout), O1__ = Obuf__; }
struct flusher__ {
	~flusher__() { flush(); }
} IO__;
inline char getch() { return I1__ == I2__ && (I2__ = (I1__ = Ibuf__) + fread(Ibuf__, 1, BUFSIZE__, stdin), I1__ == I2__) ? EOF : *I1__++; }
inline void putch(char Ch__) { *O1__++ = Ch__, (O1__ == O2__) ? flush() : void(); }
inline void getstr(char* S__) {
	char Ch__ = getch();
	int cnt__ = 0;
	for (; !isgraph(Ch__); Ch__ = getch())
		;
	for (; isgraph(Ch__); Ch__ = getch())
		S__[cnt__++] = Ch__;
	S__[cnt__] = 0;
}
inline void putstr(const char* S__) {
	int Len__ = strlen(S__);
	for (int i__ = 0; i__ < Len__; ++i__)
		putch(S__[i__]);
}
template <typename Var__>
inline Var__ read() {
	register Var__ Res__ = 0, W__ = 1;
	register char Ch__ = getch();
	for (; Ch__ < '0' || Ch__ > '9'; Ch__ = getch())
		if (Ch__ == '-') W__ = -1;
	for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
		Res__ = (Res__ << 3) + (Res__ << 1) + (Ch__ ^ 48);
	return Res__ * W__;
}
inline double readDB() {
	register double ResB__ = 0, Cnt__ = 1;
	register char Ch__ = getch();
	register int ResA__ = 0, W__ = 1;
	if (Ch__ != '.') {
		for (; Ch__ < '0' || Ch__ > '9'; Ch__ = getch())
			if (Ch__ == '-') W__ = -1;
		for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
			ResA__ = (ResA__ << 3) + (ResA__ << 1) + (Ch__ ^ 48);
		if (Ch__ != '.') return ResA__ * W__;
	}
	Ch__ = getch();
	for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
		ResB__ += (Ch__ ^ 48) * (Cnt__ *= 0.1);
	return (ResA__ + ResB__) * W__;
}
template <typename Var__>
inline void write(register Var__ Num__, const char Ch__ = '\0') {
	if (!Num__) putch('0');
	if (Num__ < 0) putch('-'), Num__ = -Num__;
	for (; Num__; ST__[++Top__] = Num__ % 10 + '0', Num__ /= 10)
		;
	for (; Top__; putch(ST__[Top__--]))
		;
	if (Ch__ != '\0') putch(Ch__);
}
} // namespace FastIO
using namespace FastIO;
#define int long long
const int N = 1e7 + 5;
int n, m, t1, t2, t[N], f[N], g[N], sum;
inline int calc(int now) { return (now > 0) ? std::max(t[now] + t2, f[now + 1]) : f[now + 1]; }
signed main() {
	freopen("wash.in", "r", stdin), freopen("wash.out", "w", stdout);
	n = read<int>(), t1 = read<int>(), m = read<int>();
	for (int i = 1; i <= n; ++i)
		t[i] = read<int>();
	f[n] = t[n] + t1;
	for (int i = n - 1; i >= 1; --i)
		f[i] = std::max(f[i + 1], t[i] + (n - i + 1) * t1);
	int now = n, ans = 0;
	for (int i = 1; i <= t1; ++i)
		ans ^= (i * (t[n] + i));
	for (t2 = t1 + 1; t2 <= m; ++t2) {
		for (; calc(now - 1) <= calc(now) && now >= 1; --now)
			;
		ans ^= t2 * calc(now);
	}
	write(ans, '\n');
	return 0;
}