/*
	Author: Ruakker
	Date: 2021-05-18 10:14:13
	LastEditTime: 2021-06-03 22:37:10
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
template <typename Var>
inline Var read() {
	register Var Res__ = 0, W__ = 1;
	register char Ch__ = getch();
	for (; Ch__ < '0' || Ch__ > '9'; Ch__ = getch())
		if (Ch__ == '-') W__ = -1;
	for (; Ch__ <= '9' && Ch__ >= '0'; Ch__ = getch())
		Res__ = (Res__ << 3) + (Res__ << 1) + (Ch__ ^ 48);
	return Res__ * W__;
}
template <typename Var>
inline void write(register Var Num__, const char Ch__ = '\0') {
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
const int N = 20, M = 1 << 18;
using std::cin;
using std::cout;
using std::endl;
int max, n;
double a[N][N], f[M];
signed main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	max = (1 << n) - 1, f[max] = 1;
	for (int i = max - 1; i; i--) {
		int cnt = 0, tmp = i;
		for (; tmp; cnt += tmp & 1, tmp >>= 1)
			;
		for (int j = 1; j <= n; j++) {
			if ((1 << j - 1) & i) continue;
			for (int k = 1; k <= n; k++) {
				if (!((1 << k - 1) & i)) continue;
				f[i] += (double)f[i | (1 << j - 1)] * a[k][j] / (cnt * (cnt + 1) / 2);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		// cout<<f[1<<i-1]<<' ';
		printf("%.6lf ", f[1 << i - 1]);
	return 0;
}