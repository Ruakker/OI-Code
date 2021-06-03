/**
 * @Date:   2021-Jun-02
 * @Email:  i@ruakker.cn
 * @Filename: Queries.cpp
 * @Last modified time: 2021-Jun-02
**/

#include <bits/stdc++.h>
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
using std::cerr;
using std::endl;
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
bool STARTMEM;
const int N = 1e5 + 5, P = 4001;
int a[N], b[N][15], c[15], n, m;
#define lson (k << 1)
#define rson (k << 1 | 1)
struct SegTree {
	int sum, tag;
} segt[N << 2][15];
inline void pushup(int bit, int k) {
	segt[k][bit].sum = segt[lson][bit].sum + segt[rson][bit].sum;
}
inline void pushdown(int l, int r, int bit, int k) {
	if (!segt[k][bit].tag) return;
	int mid = l + r >> 1;
	segt[lson][bit].sum = mid - l + 1 - segt[lson][bit].sum;
	segt[rson][bit].sum = r - mid - segt[rson][bit].sum;
	segt[lson][bit].tag ^= 1, segt[rson][bit].tag ^= 1;
	segt[k][bit].tag = 0;
}
void modify(int L, int R, int l, int r, int bit, int k) {
	if (L <= l && r <= R) {
		segt[k][bit].sum = r - l + 1 - segt[k][bit].sum;
		segt[k][bit].tag ^= 1;
		return;
	}
	pushdown(l, r, bit, k);
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, bit, lson);
	if (mid < R) modify(L, R, mid + 1, r, bit, rson);
	pushup(bit, k);
}
int query(int L, int R, int l, int r, int bit, int k) {
	if (L <= l && r <= R) return segt[k][bit].sum;
	pushdown(l, r, bit, k);
	int mid = l + r >> 1, res = 0;
	if (L <= mid) res += query(L, R, l, mid, bit, lson);
	if (mid < R) res += query(L, R, mid + 1, r, bit, rson);
	return res;
}
inline void prebuild() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 10; ++j)
			if (a[i] >> j & 1)
				modify(i, n, 1, n, j, 1);
	}
}
bool ENDMEM;
aafsafd;
signed main() {
	// cerr<<fabs(&STARTMEM-&ENDMEM)/1048576.0<<endl;
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= n; ++i)
		a[i] = read<int>();
	prebuild();

	// for (int i = 1; i <= n; ++i, cerr << endl)
	// 	for (int j = 0; j <= 10; ++j)
	// 		cerr << b[i][j];
	// cerr << endl;

	for (; m--;) {
		int opt = read<int>();
		if (opt == 1) {
			int pos = read<int>(), val = read<int>();
			int del = a[pos] ^ val;
			for (int i = 0; i <= 10; ++i)
				if (del >> i & 1) modify(pos, n, 1, n, i, 1);
			a[pos] = val;
		} else {
			int l = read<int>(), r = read<int>();
			int ans = 0;
			for (int i = 10; i >= 0; --i) {
				(ans <<= 1) %= P;
				int sum1 = query(l - 1, r, 1, n, i, 1);
				int sum0 = r - l + 2 - sum1;
				(ans += sum1 * sum0 % P) %= P;
			}
			write<int>(ans % P, '\n');
		}
	}
	return 0;
}
