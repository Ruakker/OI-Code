/*
	Author: Ruakker
	Date: 2021-07-20 13:32:48
	LastEditTime: 2021-07-20 14:20:13
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

#define int long long
const int N = 1e6 + 5;
const double pi = acos(-1.);
int n, m, Anslen, Len;

struct Complex {
	double x, y;
	Complex(double xx = 0, double yy = 0) { x = xx, y = yy; }
	inline Complex operator+(Complex const &Other) const { return Complex(x + Other.x, y + Other.y); }
	inline Complex operator-(Complex const &Other) const { return Complex(x - Other.x, y - Other.y); }
	inline Complex operator*(Complex const &Other) const { return Complex(x * Other.x - y * Other.y, x * Other.y + y * Other.x); }
	inline Complex operator/(Complex const &Other) const {
		double c = Other.x * Other.x + Other.y * Other.y;
		return Complex((x * Other.x + y * Other.y) / c, (y * Other.x - x * Other.y) / c);
	}
} f[N << 1], g[N << 1], sav[N << 1];

inline void FFT(Complex *f, int len, bool flag) {
	if (len == 1) return;
	Complex *fL = f, *fR = f + (len >> 1);
	for (int k = 0; k <= len - 1; k++)
		sav[k] = f[k];
	for (int k = 0; k <= len / 2 - 1; k++) {
		fL[k] = sav[k << 1];
		fR[k] = sav[k << 1 | 1];
	}
	FFT(fL, len >> 1, flag), FFT(fR, len >> 1, flag);
	Complex Base(cos(2 * pi / len), sin(2 * pi / len)), buf(1, 0);
	if (!flag) Base.y *= -1;
	for (int k = 0; k <= len / 2 - 1; k++) {
		sav[k] = fL[k] + buf * fR[k];
		sav[k + len / 2] = fL[k] - buf * fR[k];
		buf = buf * Base;
	}
	for (int k = 0; k <= len - 1; k++)
		f[k] = sav[k];
}

bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif

	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		cin >> f[i].x;
	for (int i = 0; i <= m; ++i)
		cin >> g[i].x;
	Anslen = m + n, Len = 1;
	for (; Len <= Anslen;)
		Len <<= 1;
	FFT(f, Len, 1), FFT(g, Len, 1);
	for (int i = 0; i <= Len - 1; ++i)
		f[i] = f[i] * g[i];
	FFT(f, Len, 0);
	for (int i = 0; i < Len; ++i)
		f[i].x /= Len;
	for (int i = 0; i <= Anslen; ++i)
		cout << (int)(.5 + f[i].x) << ' ';
	cout << endl;
	return 0;
}