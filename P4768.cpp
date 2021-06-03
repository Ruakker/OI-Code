/*
	Author: Ruakker
	Date: 2021-05-27 19:06:02
	LastEditTime: 2021-05-27 21:56:33
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
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
const int N = 4e5 + 5;
struct Edge {
	int nxt, to, height, dist;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y, int height, int dist) {
	e[++tote] = (Edge){head[x], y, height, dist};
	head[x] = tote;
}

int dist[N], n, m;
inline void Dijkstra(int p0) {
	memset(dist, inf, sizeof dist);
	dist[p0] = 0;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> que;
	que.push(mp(0, p0)); //first: dis,second: id;
	for (; !que.empty();) {
		int u = que.top().se;
		que.pop();
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dist[u] + e[v].dist < dist[v])
				dist[v] = dist[u] + e[v].dist,
				que.push(mp(dist[v], v));
		}
	}
}

signed main() {
	for (int T = read<int>(); T--;) {
		// init();
		n = read<int>(), m = read<int>();
		for (int i = 1; i <= m; ++i) {
			int u = read<int>(), v = read<int>(), l = read<int>(), a = read<int>();
			adde(u, v, l, a), adde(v, u, l, a);
		}
		Dijkstra(1);
		for (int i = 1; i <= n; ++i)
			cerr << dist[i] << endl;
	}
	return 0;
}
