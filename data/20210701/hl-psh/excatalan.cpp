/*
	Author: Ruakker
	Date: 2021-07-01 18:29:37
	LastEditTime: 2021-07-02 09:53:43
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
#define int long long
const int N = 1e6 + 5, P = 998244353;
int n, m, b[N];
char s[N];
inline void chk(char* s) {
	// putstr(s + 1), putch('\t');
	std::stack<char> sta;
	sta.push(s[1]);
	for (int i = 2; i <= n; ++i)
		if (sta.empty())
			sta.push(s[i]);
		else if (sta.top() == '(' && s[i] == ')')
			sta.pop();
		else
			sta.push(s[i]);
	int cnt = 0;
	for (; !sta.empty(); sta.pop(), ++cnt)
		;
	// write(cnt, '\n');
	b[cnt]++;
}
void dfs(int rest, int k) {
	if (k > n) {
		if (!rest)
			chk(s);
		return;
	}
	// if (n - k == rest) {
	// 	s[k] = '(';
	// 	dfs(res - 1, k + 1);
	// 	return;
	// }
	// if (!rest) {
	// 	s[k] = ')';
	// 	dfs(rest, k + 1);
	// 	return;
	// }
	s[k] = '(';
	dfs(rest - 1, k + 1);
	s[k] = ')';
	dfs(rest, k + 1);
}
signed main() {
	freopen("excatalan.in", "r", stdin), freopen("excatalan.out", "w", stdout);
	n = read<int>() << 1, m = read<int>() << 1;
	if (m == 0) {
		n >>= 1;
		b[0] = 1;
		for (int i = 1; i <= n; i++)
			(b[i] = b[i - 1] * ((i << 2) - 2) / (i + 1)) %= P;
		write(b[n], '\n');
		return 0;
	}
	if (m == n - 2) {
		write(n - 1, '\n');
		return 0;
	}
	dfs(n >> 1, 1);
	write(b[m] % P, '\n');
	return 0;
}
