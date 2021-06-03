/*
	Author: Ruakker
	Date: 2021-05-24 08:24:37
	LastEditTime: 2021-05-24 15:57:45
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define lson k << 1
#define rson k << 1 | 1
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
bool STMEM;
const int N = 5e6 + 5;
int n, m, src[N], a[N], Obj;
struct SegmentTree {
	int sum1, tag;
} segt[N << 2];
struct Operation {
	int drct, l, r;
} opt[N];

/* Segment Tree Start */
inline void pushup(int k) {
	segt[k].sum1 = segt[lson].sum1 + segt[rson].sum1;
}
inline void pushdown(int l, int r, int k) {
	if (segt[k].tag == -1) return;
	int mid = l + r >> 1;
	segt[lson].tag = segt[rson].tag = segt[k].tag;
	segt[lson].sum1 = segt[k].tag * (mid - l + 1);
	segt[rson].sum1 = segt[k].tag * (r - mid);
	segt[k].tag = -1;
}
void build(int l, int r, int k) {
	segt[k].tag = -1;
	if (l >= r) return segt[k].sum1 = a[l], void();
	int mid = l + r >> 1;
	build(l, mid, lson), build(mid + 1, r, rson);
	pushup(k);
}
void modify(int L, int R, int l, int r, int val, int k) {
	if (L > R) return;
	if (L <= l && r <= R) {
		segt[k].sum1 = (r - l + 1) * val;
		segt[k].tag = val;
		return;
	}
	if (k > N) cerr << "here!l: " << l << " r: " << r << endl
		            << "L: " << L << " R: " << R << endl;
	pushdown(l, r, k);
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, val, lson);
	if (mid < R) modify(L, R, mid + 1, r, val, rson);
	pushup(k);
}
int query(int L, int R, int l, int r, int k) {
	// cerr<<"nmsl-l:"<<l<<" r:"<<r<<" L:"<<L<<" R:"<<R<<endl;
	// if (l>=r) return segt[k].sum1;
	if (L <= l && r <= R) return segt[k].sum1;
	pushdown(l, r, k);
	int res = 0, mid = l + r >> 1;
	if (L <= mid) res += query(L, R, l, mid, lson);
	if (mid < R) res += query(L, R, mid + 1, r, rson);
	return res;
}
/* Segment Tree End */

/* Binary Search Start */
inline void sortdown(int l, int r) {
	int tmp = query(l, r, 1, n, 1);
	modify(l, l + tmp - 1, 1, n, 1, 1);
	modify(l + tmp, r, 1, n, 0, 1);
}
inline void sortup(int l, int r) {
	int tmp = query(l, r, 1, n, 1);
	modify(r - tmp + 1, r, 1, n, 1, 1);
	modify(l, r - tmp, 1, n, 0, 1);
}
inline void init(int num) {
	memset(segt, 0, sizeof(segt));
	for (int i = 1; i <= n; ++i)
		a[i] = (src[i] >= num);
	build(1, n, 1);
}
inline bool chk(int ans) {
	init(ans);
	for (int i = 1; i <= m; ++i)
		opt[i].drct ? sortdown(opt[i].l, opt[i].r) : sortup(opt[i].l, opt[i].r);
	return query(Obj, Obj, 1, n, 1);
}
inline int BinarySearch(int l, int r) {
	int res = 0;
	for (; l <= r;) {
		int mid = l + r >> 1;
		if (chk(mid))
			res = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return res;
}
/* Binary Search End */
bool EDMEM;
signed main() {
	// freopen("sort2.in", "r", stdin);
	cerr << fabs(&STMEM - &EDMEM) / 1024.0 / 1024.0 << endl;
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= n; ++i)
		src[i] = read<int>();
	for (int i = 1; i <= m; ++i)
		opt[i].drct = read<int>(), opt[i].l = read<int>(), opt[i].r = read<int>();
	Obj = read<int>();

	write<int>(BinarySearch(1, n), '\n');

	return 0;
}