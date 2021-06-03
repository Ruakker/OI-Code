/*
	Author: Ruakker
	Date: 2021-05-25 17:47:25
	LastEditTime: 2021-05-25 19:44:50
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
	inline void getstr(char* st) {
		char Ch = getch();
		int cnt = 0;
		for (; !isgraph(Ch); Ch = getch())
			;
		for (; isgraph(Ch); Ch = getch())
			st[cnt++] = Ch;
		st[cnt] = 0;
	}
	inline void putstr(const char* st) {
		int Len = strlen(st);
		for (int i = 0; i < Len; ++i)
			putch(st[i]);
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
const int N = 1145140;
struct Edge {
	int nxt, to;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y) {
	e[++tote] = (Edge){head[x], y};
	head[x] = tote;
}
inline void upd(int& a, int b) { a = std::min(a, b); }
int n, m, k;

/* Tarjan Start */
struct Points {
	int dfn, low;
	bool cut;
} p[N];
int totp = 0;
std::vector<int> dcc[N];
std::stack<int> st;
void tarjan(int u) {
	int fa = 0;
	st.push(u);
	p[u].low = p[u].dfn = ++totp;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!p[v].dfn) {
			tarjan(v);
			upd(p[u].low, p[v].low);
			if (p[v].low >= p[u].dfn) {
				fa++, k++;
				if (u != 1 || fa > 1) p[u].cut = 1;
				dcc[k].push_back(u);
				int w = 0;
				do {
					w = st.top();
					st.pop();
					dcc[k].push_back(w);
				} while (w != v);
			}
		} else
			upd(p[u].low, p[v].dfn);
	}
}
/* Tarjan End */

inline void init() {
	memset(e, 0, sizeof e);
	memset(head, 0, sizeof head);
	memset(p, 0, sizeof p);
	for (int i = 1; i <= n; ++i)
		dcc[i].clear();
	for (; !st.empty(); st.pop())
		;
	totp = 0, n = 0, tote = 1, k = 0;
}
signed main() {
	int cnt = 0;
	for (; 1;) {
		init();
		m = read<int>();
		if (!m) return 0;
		for (int i = 1; i <= m; ++i) {
			int u = read<int>(), v = read<int>();
			adde(u, v), adde(v, u);
			n = std::max(n, std::max(u, v));
		}
		tarjan(1);
		int ans1 = 0, ans2 = 1;
		for (int i = 1; i <= k; i++) {
			int v1 = dcc[i].size(), v2 = 0;
			for (int q = 0; q < v1; q++)
				v2 += p[dcc[i][q]].cut;
			if (v2 == 1) ans1++, ans2 *= v1 - 1;
			if (v2 == 0) ans1 += 2, ans2 *= v1 * (v1 - 1) / 2;
		}
		putstr("Case "), write(++cnt, ':'), putch(' '), write(ans1, ' '), write(ans2, '\n');
	}
}
