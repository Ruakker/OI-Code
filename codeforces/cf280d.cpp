/*
	Author: Ruakker
	Date: 2021-05-28 08:13:33
	LastEditTime: 2021-05-28 16:12:14
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
const int maxn = 100010, mod = 998244353;
#define lson o << 1, l, mid
#define rson o << 1 | 1, mid + 1, r
inline int read() {
	int x = 0, f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
int n, m, a[maxn], ls[maxn], rs[maxn], tp;
inline bool chkmax(int& x, int y) {
	if (y > x) return x = y, true;
	return false;
}
inline bool chkmin(int& x, int y) {
	if (y < x) return x = y, true;
	return false;
}
struct node {
	int l, r, sum, lmax, rmax, amax, lx, rx, llx, rrx, lmin, rmin, amin, ln, rn, lln, rrn;
	node operator+(const node& nd) const {
		node ans;
		ans.l = l;
		ans.r = nd.r;
		ans.sum = sum + nd.sum;
		ans.lmax = lmax;
		ans.llx = llx;
		if (chkmax(ans.lmax, sum + nd.lmax)) ans.llx = nd.llx;
		ans.rmax = nd.rmax;
		ans.rrx = nd.rrx;
		if (chkmax(ans.rmax, nd.sum + rmax)) ans.rrx = rrx;
		ans.amax = amax;
		ans.lx = lx;
		ans.rx = rx;
		if (chkmax(ans.amax, nd.amax)) ans.lx = nd.lx, ans.rx = nd.rx;
		if (chkmax(ans.amax, rmax + nd.lmax)) ans.lx = rrx, ans.rx = nd.llx;
		ans.lmin = lmin;
		ans.lln = lln;
		if (chkmin(ans.lmin, sum + nd.lmin)) ans.lln = nd.lln;
		ans.rmin = nd.rmin;
		ans.rrn = nd.rrn;
		if (chkmin(ans.rmin, nd.sum + rmin)) ans.rrn = rrn;
		ans.amin = amin;
		ans.ln = ln;
		ans.rn = rn;
		if (chkmin(ans.amin, nd.amin)) ans.ln = nd.ln, ans.rn = nd.rn;
		if (chkmin(ans.amin, rmin + nd.lmin)) ans.ln = rrn, ans.rn = nd.lln;
		return ans;
	}
} seg[maxn * 4];
bool rev[maxn * 4];
inline void setrev(int o) {
	rev[o] ^= 1;
	seg[o].sum *= -1;
	int tlmax = seg[o].lmax, trmax = seg[o].rmax, tamax = seg[o].amax;
	int tlx = seg[o].lx, trx = seg[o].rx, tllx = seg[o].llx, trrx = seg[o].rrx;
	seg[o].lmax = -seg[o].lmin;
	seg[o].rmax = -seg[o].rmin;
	seg[o].amax = -seg[o].amin;
	seg[o].lmin = -tlmax;
	seg[o].rmin = -trmax;
	seg[o].amin = -tamax;
	std::swap(seg[o].lx, seg[o].ln);
	std::swap(seg[o].rx, seg[o].rn);
	std::swap(seg[o].llx, seg[o].lln);
	std::swap(seg[o].rrx, seg[o].rrn);
}
inline void pushdown(int o) {
	if (rev[o]) {
		setrev(o << 1);
		setrev(o << 1 | 1);
		rev[o] = 0;
	}
}
void build(int o, int l, int r) {
	if (l == r) return void(seg[o] = (node){l, l, a[l], a[l], a[l], a[l], l, l, l, l, a[l], a[l], a[l], l, l, l, l});
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void update(int o, int l, int r, int p, int v) {
	if (l == r) return void(seg[o] = (node){l, l, v, v, v, v, l, l, l, l, v, v, v, l, l, l, l});
	pushdown(o);
	int mid = (l + r) >> 1;
	if (mid >= p)
		update(lson, p, v);
	else
		update(rson, p, v);
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void reverse(int o, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return setrev(o);
	pushdown(o);
	int mid = (l + r) >> 1;
	if (mid >= ql) reverse(lson, ql, qr);
	if (mid < qr) reverse(rson, ql, qr);
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
node query(int o, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return seg[o];
	pushdown(o);
	int mid = (l + r) >> 1;
	if (mid < ql) return query(rson, ql, qr);
	if (mid >= qr) return query(lson, ql, qr);
	return query(lson, ql, qr) + query(rson, ql, qr);
}
int main() {
	n = read<int>();
	for (int i = 1; i <= n; ++i)
		a[i] = read<int>();
	build(1, 1, n);
	m = read<int>();
	while (m--) {
		int op = read<int>(), x = read<int>(), y = read<int>();
		if (op) {
			int k = read<int>(), s = 0, ans = 0;
			tp = 0;
			while (k--) {
				node nd = query(1, 1, n, x, y);
				ls[++tp] = nd.lx;
				rs[tp] = nd.rx;
				chkmax(ans, s += nd.amax);
				reverse(1, 1, n, nd.lx, nd.rx);
			}
			while (tp)
				reverse(1, 1, n, ls[tp], rs[tp]), tp--;
			write(ans, '\n');
		} else
			update(1, 1, n, x, y);
	}
}