/*
	Author: Ruakker
	Date: 2021-07-13 07:56:37
	LastEditTime: 2021-07-13 14:56:14
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
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
#define fi first
#define se second
typedef pair<int, int> pii;
const int N = 5005, P = 666623333;
int n, p, q, a, b, totl, totr, dire[N];
pii dp[N][N]; // dp_{i,j}: remain left i people, right j people.
ll qpow(ll a, ll b) {
	ll res = 1;
	for (; b; (a *= a) %= P, b >>= 1)
		(res *= a * (b & 1)) %= P;
	return res;
}
// a*qpow(b,P-2)%P
signed main() {
	// freopen("d.in","r",stdin),freopen("d.out","w",stdout);
	n = read<int>(), p = read<int>(), q = read<int>(), a = read<int>(), b = read<int>();
	for (int i = 1; i <= n; ++i) {
		char ch = getch();
		for (; ch == ' '; ch = getch())
			;
		if (ch == 'L')
			dire[i] = 0, ++totl; //left
		else if (ch == 'R')
			dire[i] = 1, ++totr; //right
		else
			return cerr << "Fuck error" << endl, 0;
	}
	for (int i = 1, cnt = 0; i <= n; ++i) {
		if (dire[i]) ++cnt; //if current person is going right,++cnt;
		if (!dire[i]) dp[totl][0]
	}

	return 0;
}
