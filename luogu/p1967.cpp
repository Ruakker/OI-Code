/*
	Author: Ruakker
	Date: 2021-05-25 13:40:20
	LastEditTime: 2021-05-25 15:30:20
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
using std::cerr;
using std::endl;
bool STARTMEM;
const int N = 5e4 + 5;
int n, m;
struct Edge {
	int nxt, to, val;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y, int z) {
	e[++tote].to = y;
	e[tote].val = z;
	e[tote].nxt = head[x];
	head[x] = tote;
}

/* Kruskal Start */
struct Edge1 {
	int u, v, len;
} e1[N];
inline bool cmp(const Edge1 a, const Edge1 b) {
	return a.len > b.len;
}
int fa[N];
int getfa(int a) {
	return (fa[a] == a) ? a : fa[a] = getfa(fa[a]);
}
inline void merge(int a, int b) {
	fa[getfa(a)] = getfa(b);
}
inline bool chk(int a, int b) {
	return getfa(a) == getfa(b);
}
inline void Kruskal() {
	// cerr << "Start Kruskal" << endl;
	std::sort(e1 + 1, e1 + 1 + m, cmp);
	for (int i = 1; i <= m; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		if (!chk(e1[i].u, e1[i].v)) {
			merge(e1[i].u, e1[i].v);
			// cerr << e1[i].u << ' ' << e1[i].v << endl;
			adde(e1[i].u, e1[i].v, e1[i].len), adde(e1[i].v, e1[i].u, e1[i].len);
		}
	}
	// cerr << "End Kruskal" << endl;
}
/* Kruskal End */

/* Doubled Start */
struct Points {
	int depth, fa[30], val[30];
	bool vis;
} p[N];
inline void upd(int& a, int b) {
	a = std::min(a, b);
}
void dfs(int u) {
	p[u].vis = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (p[v].vis) continue;
		p[v].depth = p[u].depth + 1;
		p[v].fa[0] = u, p[v].val[0] = e[i].val;
		dfs(v);
	}
}
inline void initLCA() {
	for (int i = 1; i <= n; ++i)
		if (!p[i].vis) dfs(i);
	for (int i = 1; i <= 25; i++)
		for (int j = 1; j <= n; j++) {
			p[j].fa[i] = p[p[j].fa[i - 1]].fa[i - 1];
			p[j].val[i] = std::min(p[j].val[i - 1], p[p[j].fa[i - 1]].val[i - 1]);
		}
}
inline int lca(int x, int y) {
	if (!chk(x, y)) return -1;
	if (p[x].depth > p[y].depth) std::swap(x, y);
	int ans = inf, diff = p[y].depth - p[x].depth;
	for (int i = 0; diff; ++i, diff >>= 1)
		if (diff & 1) upd(ans, p[y].val[i]), y = p[y].fa[i];
	if (x == y) return ans;
	for (int i = 25; ~i && x != y; --i) {
		if (!(p[x].fa[i] == p[y].fa[i])) {
			upd(ans, p[x].val[i]), upd(ans, p[y].val[i]);
			x = p[x].fa[i], y = p[y].fa[i];
		}
	}
	upd(ans, p[x].val[0]), upd(ans, p[y].val[0]);
	return ans;
}
/* Doubled End */

bool ENDMEM;
signed main() {
	cerr << fabs(&STARTMEM - &ENDMEM) / 1024.0 / 1024.0 << endl;
	n = read<int>(), m = read<int>();
	for (int i = 1; i <= m; ++i)
		e1[i].u = read<int>(), e1[i].v = read<int>(), e1[i].len = read<int>();
	Kruskal();
	initLCA();
	for (int Q = read<int>(); Q--;) {
		int u = read<int>(), v = read<int>();
		write(lca(u, v), '\n');
	}
	return 0;
}
