/*
	Author: Ruakker
	Date: 2021-07-08 08:26:06
	LastEditTime: 2021-07-08 10:35:17
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
const int N = 3e5 + 5;
struct Rkkr {
	int l, r, pos;
} a[N];
int n;
using std::cerr;
using std::endl;
namespace SubTask1 {
int dp[N], t[N], ans = -inf;
inline int lowbit(int x) { return x & -x; }
void add(int k, int num) {
	while (k <= n)
		t[k] = std::max(t[k], num), k += lowbit(k);
}
int getmax(int k) {
	int res = 0;
	while (k > 0)
		res = std::max(res, t[k]), k -= lowbit(k);
	return res;
}
inline bool cmp(const Rkkr a, const Rkkr b) {
	return a.l < b.l;
}
void Main() {
	std::fill(dp + 1, dp + 1 + n, 1);
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) {
		if (a[i].l == a[i - 1].l)
			dp[a[i].pos] = std::max(dp[a[i].pos], getmax(a[i].pos - 1)), add(a[i].pos, dp[a[i].pos]);
		else
			dp[a[i].pos] = std::max(dp[a[i].pos], getmax(a[i].pos - 1) + 1), add(a[i].pos, dp[a[i].pos]);
	}
	for (int i = 1; i <= n; ++i)
		ans = std::max(ans, dp[i]);
	write<int>(ans, '\n');
	// for (int i = 1; i <= n; ++i)
	// 	cerr << dp[i] << ' ';
	// cerr << endl
	//      << endl;
	// for (int i = 1; i <= n; ++i)
	// 	cerr << getmax(i) << ' ';
	// cerr << endl;
}
} // namespace SubTask1
signed main() {
	freopen("price.in", "r", stdin), freopen("price.out", "w", stdout);
	n = read<int>();
	bool flag = 1;
	for (int i = 1; i <= n; ++i) {
		a[i].l = read<int>(), a[i].r = read<int>(), a[i].pos = i;
		if (a[i].l != a[i].r)
			flag = 0;
	}
	if (flag) SubTask1::Main();
	return 0;
}
