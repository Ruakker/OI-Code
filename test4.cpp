/*
	Author: Ruakker
	Date: 2021-05-24 23:42:00
	LastEditTime: 2021-05-25 00:30:47
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
using namespace std;
#define int long long
const int P = 998244353, N = 1e6;
int f[N + 5], g[N + 5], d[N + 5], num[N + 5], prime[N + 5], vis[N + 5];
inline void fun(ll n) {
	memset(vis, 0, sizeof(vis));
	num[1] = d[1] = 1;
	prime[0] = 0;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			prime[++prime[0]] = i;
			d[i] = 1;
			num[i] = 2;
		}
		for (int j = 1; j <= prime[0] && i <= n / prime[j]; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				d[i * prime[j]] = d[i] + 1;
				num[i * prime[j]] = num[i] / (d[i] + 1) * (d[i] + 2);
				break;
			}
			d[i * prime[j]] = 1;
			num[i * prime[j]] = num[i] * 2;
		}
	}
}
signed main() {
	// for (int i = 1; i <= 100; ++i)
	// 	write(d[i], ' ');
	// for (int i = 1; i <= N; ++i)
	// 	write(d[i], ' ');
	int n = read<int>();
	fun(n);
	f[1] = g[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (f[i - 1] + g[i - 1]) % P;
		g[i] = (f[i] + num[i] - 1) % P;
	}
	write(g[n], '\n');
	return 0;
}
