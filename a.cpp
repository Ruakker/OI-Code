/*
	Author: Ruakker
	Date: 2021-05-31 08:19:41
	LastEditTime: 2021-05-31 14:01:25
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO {
static const int BUFSIZE = (1 << 20) + 1;
static char Ibuf[BUFSIZE], *I1 = Ibuf, *I2 = Ibuf, Obuf[BUFSIZE], *O1 = Obuf, *O2 = O1 + BUFSIZE - 1;
static int ST[55], Top;
inline void flush() { fwrite(Obuf, 1, O1 - Obuf, stdout), O1 = Obuf; }
struct flusher {
	~flusher() { flush(); }
} IO;
inline char getch() { return I1 == I2 && (I2 = (I1 = Ibuf) + fread(Ibuf, 1, BUFSIZE, stdin), I1 == I2) ? EOF : *I1++; }
inline void putch(char Ch) { *O1++ = Ch, (O1 == O2) ? flush() : void(); }
inline int getstr(char* S) {
	char Ch = getch();
	int cnt = 0;
	for (; !isgraph(Ch); Ch = getch())
		;
	for (; isgraph(Ch); Ch = getch())
		S[cnt++] = Ch;
	S[cnt] = 0;
	return cnt;
}
inline void putstr(const char* S) {
	int Len = strlen(S);
	for (int i = 0; i < Len; ++i)
		putch(S[i]);
}
template <typename Var>
inline Var read() {
	register Var Res = 0, W = 1;
	register char Ch = getch();
	for (; Ch < '0' || Ch > '9'; Ch = getch())
		if (Ch == '-') W = -1;
	for (; Ch <= '9' && Ch >= '0'; Ch = getch())
		Res = (Res << 3) + (Res << 1) + (Ch ^ 48);
	return Res * W;
}
inline double readDB() {
	register double ResB = 0, Cnt = 1;
	register char Ch = getch();
	register int ResA = 0, W = 1;
	if (Ch != '.') {
		for (; Ch < '0' || Ch > '9'; Ch = getch())
			if (Ch == '-') W = -1;
		for (; Ch <= '9' && Ch >= '0'; Ch = getch())
			ResA = (ResA << 3) + (ResA << 1) + (Ch ^ 48);
		if (Ch != '.') return ResA * W;
	}
	Ch = getch();
	for (; Ch <= '9' && Ch >= '0'; Ch = getch())
		ResB += (Ch ^ 48) * (Cnt *= 0.1);
	return (ResA + ResB) * W;
}
template <typename Var>
inline void write(register Var Num, const char Ch = '\0') {
	if (!Num) putch('0');
	if (Num < 0) putch('-'), Num = -Num;
	for (; Num; ST[++Top] = Num % 10 + '0', Num /= 10)
		;
	for (; Top; putch(ST[Top--]))
		;
	if (Ch != '\0') putch(Ch);
}
} // namespace FastIO
using namespace FastIO;
const int N = 3e5 + 5;
struct Query {
	int opt, l, r;
} q[N];
int a[N], n, m;
namespace sub1 {
void Main() {
	for (int i = 1; i <= m; ++i) {
		int opt = q[i].opt, l = q[i].l, r = q[i].r;
		if (opt == 1)
			for (int i = l; i < r; ++i)
				a[i] = std::max(a[i], a[i + 1]);
		if (opt == 2) {
			int max = -inf, ans = 0;
			for (int i = l; i <= r; ++i)
				if (a[i] > max) max = a[i], ans += a[i];
			write<int>(ans, '\n');
		}
	}
}
} // namespace sub1
signed main() {
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	n = read<int>(),
	m = read<int>();
	for (int i = 1; i <= n; ++i)
		a[i] = read<int>();
	for (int i = 1; i <= m; ++i) {
		int opt = read<int>(), l = read<int>(), r = read<int>();
		q[i] = (Query){opt, l, r};
	}
	// if (n <= 2000 && m <= 2000)
	sub1::Main();
	return 0;
}
