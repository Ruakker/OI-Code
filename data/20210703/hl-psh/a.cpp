/*
	Author: Ruakker
	Date: 2021-07-03 13:56:06
	LastEditTime: 2021-07-03 20:51:08
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
bool MEMST;
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
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
#define int long long
#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> pii;
const int N = 1e7 + 5, P = 998244353;
ll qpow(ll a, ll b) {
	ll res = 1;
	for (; b > 0; (a *= a) %= P, b >>= 1)
		if (b & 1) (res *= a) %= P;
	return res;
}
int n, f[N], rest; //f_i/{n^i}
ll ans;
bool MEMED;
signed main() {
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	// cerr << "Memory used: " << fabs(&MEMST - &MEMED) / 1048576.0 << endl;
	for (int Q = read<int>(); Q--;) {
		n = read<int>(), ans = 0;
		if (n == 1) {
			write<int>(2, '\n');
			continue;
		}
		f[1] = 0, rest = n;
		for (int i = 2; i <= n + 1; ++i) {
			f[i] = rest * (i - 1) % P;
			((rest *= n) -= f[i]) %= P;
		}
		// for (int i = 1; i <= n + 1; ++i) {
		// 	ans = plus(ans, mp(f[i] * i, qpow(n, i)));
		// 	// cerr << f[i] << endl;
		// }
		// cerr << ans.fi << '/' << ans.se << endl;
		for (int i = 1; i <= n + 1; ++i) {
			(ans += 1ll * f[i] * qpow(n, n + 1 - i) % P * i) %= P;
		}
		int cnt = n + 1;
		for (; ans % n == 0; ans /= n, --cnt)
			;
		int down = qpow(n, cnt);
		write<ll>(1ll * ans % P * qpow(down, P - 2) % P, '\n');
	}
	// cerr << "Done" << endl;
	return 0;
}
