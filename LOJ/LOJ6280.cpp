/*
	Author: Ruakker
	Date: 2021-05-23 10:36:37
	LastEditTime: 2021-06-04 18:54:44
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
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
using std::pair;
const int N = 5e4 + 5, sqrtN = 250;
pii a[N], sum[sqrtN]; //fi: val, se: id
int n, len;
inline void add(int l, int r, int num) {
	if (a[l].se == a[r].se) {
		for (int i = l; i <= r; ++i)
			a[i].fi += num;
		sum[a[l].se].fi += (r - l + 1) * num;
		return;
	}
	for (int i = l; a[i].se == a[l].se; ++i)
		a[i].fi += num, sum[a[i].se].fi += num;
	for (int i = a[l].se + 1; i < a[r].se; ++i)
		sum[i].se += num, sum[i].fi += len * num;
	for (int i = r; a[i].se == a[r].se; --i)
		a[i].fi += num, sum[a[i].se].fi += num;
}
inline ll query(int l, int r, int p) {
	ll ans = 0;
	if (a[l].se == a[r].se) {
		for (int i = l; i <= r; ++i)
			(ans += a[i].fi + sum[a[l].se].se) %= p;
		return ans;
	}
	for (int i = l; a[i].se == a[l].se; ++i)
		(ans += a[i].fi + sum[a[l].se].se) %= p;
	for (int i = a[l].se + 1; i < a[r].se; ++i)
		(ans += sum[i].fi) %= p;
	for (int i = r; a[i].se == a[r].se; --i)
		(ans += a[i].fi + sum[a[r].se].se) %= p;
	return ans;
}
signed main() {
	n = read<int>();
	len = std::sqrt(n);
	for (int i = 1; i <= n; ++i)
		a[i].fi = read<int>(), a[i].se = (i - 1) / len + 1, sum[a[i].se].fi += a[i].fi;
	for (int i = 1; i <= n; ++i) {
		int opt = read<int>(), l = read<int>(), r = read<int>(), c = read<int>();
		if (opt == 0) add(l, r, c);
		if (opt == 1) write(query(l, r, c + 1), '\n');
	}
	return 0;
}
