/*
	Author: Ruakker
	Date: 2021-06-30 19:02:23
	LastEditTime: 2021-07-01 18:19:49
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
using std::make_pair;
const int N = 2005;
int a[N][N];
int h, w, ans = inf, max = -inf, min = inf;
inline void upd(int& x, int y) {
	x = std::min(x, y);
}
inline bool chk(int k) {
	int ed = w;
	for (int i = 1; i <= h; ++i) {
		int tmp = ed;
		for (int j = 1; j <= ed; ++j)
			if (max - a[i][j] > k) {
				tmp = j - 1;
				break;
			}
		ed = tmp;
		for (int j = tmp + 1; j <= w; ++j)
			if (a[i][j] - min > k) return 0;
	}
	return 1;
}
inline int BinarySearch(int l, int r) {
	int res = inf;
	for (; l <= r;) {
		int mid = l + r >> 1;
		if (chk(mid))
			res = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return res;
}
signed main() {
	h = read<int>(), w = read<int>();
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
			a[i][j] = read<int>();
			max = std::max(a[i][j], max), min = std::min(a[i][j], min);
		}
	upd(ans, BinarySearch(0, max - min));

	for (int i = 1; i <= h; ++i)
		std::reverse(a[i] + 1, a[i] + 1 + w);

	upd(ans, BinarySearch(0, max - min));

	std::reverse(a + 1, a + 1 + h);

	upd(ans, BinarySearch(0, max - min));

	for (int i = 1; i <= h; ++i)
		std::reverse(a[i] + 1, a[i] + 1 + w);

	upd(ans, BinarySearch(0, max - min));
	write(ans, '\n');
	return 0;
}
