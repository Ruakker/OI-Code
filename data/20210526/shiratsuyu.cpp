/*
	Author: Ruakker
	Date: 2021-05-26 09:57:45
	LastEditTime: 2021-05-26 14:11:38
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
#define int long long
const int P = 1000000007;
const int N = 25, M = (1 << 17) + 5;
int n, m, a[N];
ll fac[M], inv[M], f[N][M];
inline int count(int x) {
	int res = 0;
	while (x) {
		res += (x & 1);
		x >>= 1;
	}
	return res;
}
inline ll C(int n, int m) {
	if ((n < m) || (m < 0))
		return 0;
	else
		return fac[n] * inv[m] % P * inv[n - m] % P;
}
inline bool cmp(const int a, const int b) {
	return a > b;
}
inline void init() {
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= M - 5; ++i)
		fac[i] = fac[i - 1] * i % P;
	for (int i = 2; i <= M - 5; ++i)
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2; i <= M - 5; ++i)
		inv[i] = inv[i] * inv[i - 1] % P;
}
signed main() {
	freopen("shiratsuyu.in", "r", stdin), freopen("shiratsuyu.out", "w", stdout);
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= m; ++i)
		a[i] = read<int>();
	init();
	std::sort(a + 1, a + m + 1, cmp);
	f[0][0] = 1;
	for (int i = 1; i <= m; ++i)
		for (int S = 0; S < (1 << n); ++S) {
			f[i][S] = (f[i][S] + f[i - 1][S]) % P;
			for (int k = 0; k < n; ++k) {
				if ((S >> k) & 1) continue;
				f[i][S | (1 << k)] = (f[i][S | (1 << k)] + f[i - 1][S] * C(((1 << n) - S - a[i]), (1 << k) - 1) % P * fac[1 << k] % P) % P;
			}
		}
	ll ans = 0;
	for (int S = 0; S < (1 << n); ++S) {
		int x = count(S);
		if (x & 1)
			(ans += P - (f[m][S] * fac[(1 << n) - S - 1] % P)) %= P;
		else
			(ans += (f[m][S] * fac[(1 << n) - S - 1] % P)) %= P;
	}
	write<ll>(ans * (1 << n) % P, '\n');
	return 0;
}