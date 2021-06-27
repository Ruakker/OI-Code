/**
 * @Date:   2021-Jun-01
 * @Email:  i@ruakker.cn
 * @Filename: P6406.cpp
 * @Last modified time: 2021-Jun-01
 */

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
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
const int N = 5e5 + 5, logN = 25, P = 1e9;
int n, ans, a[N], S1[N], S2[N], S3[N], S1_[N], S2_[N], S3_[N];
void divide(int l, int r) {
	if (l == r) return (ans += a[l] * a[l] % P) %= P, void();
	if (l + 1 == r)
		return (ans += (a[l] * a[l] % P + a[r] * a[r] % P + a[l] * a[r] % P * 2 % P) % P) %= P, void();
	int mid = l + r >> 1, min = a[mid], max = a[mid], i = mid, j = mid, k = mid;
	int MIN = a[mid + 1], MAX = a[mid + 1];
	S1[mid] = S2[mid] = S3[mid] = S1_[mid] = S2_[mid] = S3_[mid] = 0;
	for (int i = mid + 1; i <= r; ++i) {
		MIN = std::min(MIN, a[i]), MAX = std::max(MAX, a[i]);
		(S1[i] = S1[i - 1] + MIN * (i - (mid + 1) + 1) % P) %= P, (S1_[i] = S1_[i - 1] + MIN) %= P;
		(S2[i] = S2[i - 1] + MAX * (i - (mid + 1) + 1) % P) %= P, (S2_[i] = S2_[i - 1] + MAX) %= P;
		(S3[i] = S3[i - 1] + MIN * MAX % P * (i - (mid + 1) + 1) % P) %= P, (S3_[i] = S3_[i - 1] + MIN * MAX % P) %= P;
	}
	for (; i >= l;) {
		min = std::min(min, a[i]), max = std::max(max, a[i]);
		for (; j < r && a[j + 1] > min; ++j)
			;
		for (; k < r && a[k + 1] < max; ++k)
			;
		int w1 = std::min(j, k), w2 = std::max(j, k);
		if (w1 > mid) (ans += min * max % P * ((mid + 1 - i + 1 + w1 - i + 1) * (w1 - (mid + 1) + 1) / 2 % P) % P) %= P;
		if (j > w1)
			(ans += min * ((S2[j] - S2[w1] + P) % P + (mid - i + 1) * (S2_[j] - S2_[w1] + P) % P) % P) %= P;
		if (k > w1)
			(ans += max * ((S1[k] - S1[w1] + P) % P + (mid - i + 1) * (S1_[k] - S1_[w1] + P) % P) % P) %= P;
		(ans += ((S3[r] - S3[w2] + P) % P + (mid - i + 1) * (S3_[r] - S3_[w2] + P) % P) % P) %= P;
		--i;
	}
	divide(l, mid), divide(mid + 1, r);
}
signed main() {
	n = read<int>();
	for (int i = 1; i <= n; ++i)
		a[i] = read<int>();
	divide(1, n);
	write<ll>(ans % P, '\n');
	return 0;
}
