/*
	Author: Ruakker
	Date: 2021-05-24 16:14:10
	LastEditTime: 2021-05-24 21:11:54
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
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
#define lson k << 1
#define rson k << 1 | 1
using std::cerr;
using std::endl;
const int N = 5e6 + 5;
int n, m, disc[N], cnt, ans = inf, len;
struct Interval {
	int l, r, len;
} a[N];
struct SegmentTree {
	int val, tag, max;
} segt[N << 2];
inline void upd(int& a, int b) {
	a = a > b ? a : b;
}
inline void pushup(int k) {
	segt[k].val = segt[lson].val + segt[rson].val;
	segt[k].max = std::max(segt[lson].max, segt[rson].max);
}
inline void pushdown(int l, int r, int k) {
	if (!segt[k].tag) return;
	int mid = l + r >> 1;
	segt[lson].tag += segt[k].tag;
	segt[rson].tag += segt[k].tag;
	segt[lson].val += segt[k].tag * (mid - l + 1);
	segt[rson].val += segt[k].tag * (r - mid);
	segt[lson].max += segt[k].tag;
	segt[rson].max += segt[k].tag;
	segt[k].tag = 0;
}
inline void modify(int L, int R, int l, int r, int val, int k) {
	if (l > r) return;
	if (L <= l && r <= R) {
		segt[k].val += val * (r - l + 1);
		segt[k].tag += val;
		segt[k].max += val;
		return;
	}
	pushdown(l, r, k);
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, val, lson);
	if (mid < R) modify(L, R, mid + 1, r, val, rson);
	pushup(k);
}
// inline int getsum(int L, int R, int l, int r, int k) {
// 	if (l > r) return 0;
// 	if (L <= l && r <= R) return segt[k].val;
// 	pushdown(l, r, k);
// 	int mid = l + r >> 1, res = 0;
// 	if (L <= mid) res += getsum(L, R, l, mid, lson);
// 	if (mid < R) res += getsum(L, R, mid + 1, r, rson);
// 	return res;
// }
inline bool cmp(const Interval x, const Interval y) {
	return x.len < y.len;
}
inline void discretization() {
	std::sort(disc + 1, disc + 1 + cnt);
	len = std::unique(disc + 1, disc + 1 + cnt) - disc - 1;
	for (register int i = 1; i <= n; ++i) {
		a[i].l = std::lower_bound(disc + 1, disc + 1 + len, a[i].l) - disc;
		a[i].r = std::lower_bound(disc + 1, disc + 1 + len, a[i].r) - disc;
	}
}

signed main() {
	// freopen("interval.in", "r", stdin);
	n = read<int>(), m = read<int>();
	for (register int i = 1; i <= n; ++i) {
		a[i].l = read<int>(), a[i].r = read<int>();
		a[i].len = a[i].r - a[i].l + 1;
		disc[++cnt] = a[i].l, disc[++cnt] = a[i].r;
	}
	discretization();
	std::sort(a + 1, a + 1 + n, cmp);
	// for (int i = 1; i <= n; ++i)
	// 	cerr << a[i].l << ' ' << a[i].r << endl;
	int p = 0;
	for (register int i = 1; i <= n; ++i) {
		modify(a[i].l, a[i].r, 1, len, 1, 1);
		// cerr << "max: " << segt[1].max << endl;
		// for (int i = 1; i <= n; ++i)
		// 	cerr << getsum(i, i, 1, n, 1) << ' ';
		// cerr << endl;
		for (; segt[1].max >= m;) {
			++p;
			// cerr << "i: " << i << " p: " << p << " ans: " << a[i].len - a[p].len << endl;
			ans = std::min(ans, a[i].len - a[p].len);
			modify(a[p].l, a[p].r, 1, len, -1, 1);
			// for (int i = 1; i <= n; ++i)
			// 	cerr << getsum(i, i, 1, n, 1) << ' ';
			// cerr << endl;
		}
	}
	write((ans == inf) ? -1 : ans, '\n');
	return 0;
}
