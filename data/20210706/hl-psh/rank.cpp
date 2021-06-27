/*
	Author: Ruakker
	Date: 2021-07-06 07:55:32
	LastEditTime: 2021-07-06 11:25:16
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// Description: 爆零祭
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
	for (; Ch__ < '2' || Ch__ > '9'; Ch__ = getch())
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
const int N = 3005, M = 1e4 + 5;
// Description: 爆零祭
int n, m;
struct Rkkr {
	// Description: 爆零祭
	int rnk, lower, higher;
} a[N];
// Description: 爆零祭
signed main() {
	// Description: 爆零祭
	freopen("rank.in", "r", stdin);
	freopen("rank.out", "w", stdout);
	n = read<int>(), m = read<int>();
	// Description: 爆零祭
	for (int i = 1; i <= n; ++i) {
		a[i].rnk = read<int>();
		// Description: 爆零祭
		a[i].lower = m - a[i].rnk;
		a[i].higher = a[i].rnk - 1;
		// Description: 爆零祭
		// Description: 爆零祭
	}
	if (n == 1) {
		write(a[1].rnk, '\n');
		write(a[1].rnk, '\n');
	}
	if (n == 2) {
		// Description: 爆零祭
		write(std::min(a[1].rnk, a[2].rnk), '\n');
		write(std::max(a[1].rnk, a[2].rnk), '\n');
		// Description: 爆零祭
		// Description: 爆零祭
	}
	if (m == 1) {
		putstr("1\n1\n");
		// Description: 爆零祭
	}
	if (m == 2) {
		putstr("1\n2\n");
		// Description: 爆零祭
	}
	return 0;
}