/*
	Author: Ruakker
	Date: 2021-06-03 08:32:57
	LastEditTime: 2021-06-03 09:17:18
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
const int N = 1e5 + 5;
std::vector<int> e[N];
inline void adde(int x, int y) {
	e[x].push_back(y);
}
int n, m, totp;
struct Node {
	int dfn, low, dgr;
} p[N];
std::vector<int> ans;
std::bitset<N> iscut;
inline void upd(int& x, int y) {
	x = std::min(x, y);
}
void tarjan(int u, int rt) {
	p[u].dfn = p[u].low = ++totp;
	int child = 0;
	for (int v : e[u]) {
		if (p[v].dfn) {
			upd(p[u].low, p[v].dfn);
			continue;
		}
		tarjan(v, u);
		upd(p[u].low, p[v].low);
		if (p[v].low >= p[u].dfn && u != rt)
			iscut[u] = 1;
		if (u == rt)
			child++;
	}
	if (child >= 2 && u == rt)
		iscut[u] = 1;
}
signed main() {
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= m; ++i) {
		int u = read<int>(), v = read<int>();
		adde(u, v), adde(v, u);
		++p[u].dgr, ++p[v].dgr;
	}
	iscut.reset();
	for (int i = 1; i <= n; ++i)
		if (!p[i].dfn) tarjan(i, i);
	for (int i = 1; i <= n; ++i)
		if (!iscut[i] && m - p[i].dgr == n - 2)
			ans.push_back(i);
	write<unsigned ll>(ans.size(), '\n');
	for (int t : ans)
		write(t, ' ');
	putch('\n');
	return 0;
}
