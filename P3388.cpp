/*
	Author: Ruakker
	Date: 2021-05-25 19:05:11
	LastEditTime: 2021-05-25 19:08:36
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
	inline void getstr(char* S) {
		char Ch = getch();
		int cnt = 0;
		for (; !isgraph(Ch); Ch = getch())
			;
		for (; isgraph(Ch); Ch = getch())
			S[cnt++] = Ch;
		S[cnt] = 0;
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
const int N = 114514;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1, n, m;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
inline void upd(int& a, int b) { a = std::min(a, b); }

/* Tarjan Start */
struct Points {
	int dfn, low;
	bool cut;
} p[N];
int totp = 0;
void tarjan(int u, int rt) {
	p[u].dfn = p[u].low = ++totp;
	int child = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (p[v].dfn) {
			upd(p[u].low, p[v].dfn);
			continue;
		}
		tarjan(v, u);
		upd(p[u].low, p[v].low);
		if (p[v].low >= p[u].dfn && u != rt)
			p[u].cut = 1;
		if (u == rt)
			child++;
	}
	if (child >= 2 && u == rt)
		p[u].cut = 1;
}
/* Tarjan End */

signed main() {
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= m; ++i) {
		int u = read<int>(), v = read<int>();
		adde(u, v), adde(v, u);
	}
	for (int i = 1; i <= m; ++i)
		if (!p[i].dfn) tarjan(i, i);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (p[i].cut) ++ans;
	write<int>(ans, '\n');
	for (int i = 1; i <= n; ++i)
		if (p[i].cut) write(i, ' ');
	putch('\n');
	return 0;
}
