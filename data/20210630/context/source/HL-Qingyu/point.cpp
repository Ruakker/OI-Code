#include <bits/stdc++.h>

typedef long long ll;
inline void dpu(int &x, int y) { x = std::min(x, y); }

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}

	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}

	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<1024768> io;

inline int read()
{
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void put(int x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

const int N = 1e5 + 50;

int n, L, d, a, b, x[N], got[N];
int dp[242][1 << 15];


inline int popcount(long x)
{
	return ((std::bitset<sizeof (long) * 8> *) & x) -> count();
}

int calc1()
{
	int d2 = 2 * d;
	for (int i = 0; i < (1 << d2); ++i)
	{
		int pc = popcount(i), dc = popcount(i & ~(i >> 1));
		if (a < b) dp[0][i] = a * pc;
		else dp[0][i] = (a - b) * dc + b * pc;
	}
	for (int i = 1; i <= L; ++i) memset(dp[i], 0x3f, ((1 << d2) + 1) << 2);
	const int cost[2][2] = {{0, std::min(a, b)}, {std::max(a - b, 0), std::min(a, b)}};
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < (1 << d2); ++j)
			for (int k = got[i] && !(j & 1); k < 2; ++k)
				dpu(dp[i + 1][j >> 1 | k << (d2 - 1)], dp[i][j] + cost[j >> (d2 - 1) & 1][k]);
	int res = (int) 2e9;
	for (int j = 0; j < (1 << (d2 - 1)); ++j) dpu(res, dp[L][j]);
	return res;
}

const int S = 416, T = 417, SZ = 1005;
const ll inf = 1e9, inff = 1e15;
namespace flows
{
const int N = 1005;
const int M = 1e5 + 50;
int head[N], nxt[M], ver[M], cnt = 1;
int n, m, s, t, cur[N], d[N];
ll edge[M];

inline void init()
{
	s = S, t = T;
	memset(head, 0, sizeof head);
	cnt = 1;
}

inline void add(int u, int v, long long w)
{
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = 0, head[v] = cnt;
}

inline bool bfs()
{
	std::queue<int> que;
	que.push(s);
	memset(d, 0, sizeof d);
	d[s] = 1;
	memcpy(cur, head, sizeof head);

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i]; ll w = edge[i];
			if (w && !d[y])
			{
				d[y] = d[x] + 1;
				if (y == t)
					return true;
				que.push(y);
			}
		}
	}

	return false;
}

inline ll dinic(int x, ll flow)
{
	if (x == t)
		return flow;

	ll rest = flow;

	for (int &i = cur[x]; i; i = nxt[i])
		if (edge[i] && d[ver[i]] == d[x] + 1)
		{
			int y = ver[i];
			ll k = dinic(y, std::min(rest, edge[i]));

			if (!k)
				d[y] = 0;

			edge[i] -= k, edge[i ^ 1] += k, rest -= k;

			if (!rest)
				break;
		}

	return flow - rest;
}

inline ll maxflow()
{
	ll maxflow = 0, flow;
	while (bfs())
		while (flow = dinic(s, 1e18))
			maxflow += flow;
	return maxflow;
}

}
int f[N];

ll calc2a()
{
	int i, j, k, d2 = d * 2;
	flows::init();
	for (i = 0; i < L; ++i)
	{
		if ((i / d2) & 1)
		{
			flows::add(S, i, inf);
			flows::add(i, i + L, inff);
			flows::add(i + L, T, inf + std::min(a, b));
			if (i && i % d2 == 0) 
			{
				if (f[i])
					flows::add(S, i, inff);
				else
					flows::add(i + L, T, inff);
			}
			if (got[i]) flows::add(i + d2, i, inff);
			if (a > b)
			{
				if (i == L - 1)
					flows::add(i + L, T, a - b);
				else if ((i + 1) % d2)
					flows::add(i + L, i + 1 + L, a - b);
				else if (!f[i + 1])
					flows::add(i + L, T, a - b);
			}
		}
		else
		{
			flows::add(S, i, inf + std::min(a, b));
			flows::add(i, i + L, inff);
			flows::add(i + L, T, inf);
			if (i && i % d2 == 0) 
			{
				if (f[i])
					flows::add(i + L, T, inff);
				else
					flows::add(S, i, inff);
			}
			if (got[i]) flows::add(i + L, i + L + d2, inff);
			if (a > b)
			{
				if (i == L - 1)
					flows::add(S, i, a - b);
				else if ((i + 1) % d2)
					flows::add(i + 1, i, a - b);
				else if (!f[i + 1])
					flows::add(S, i, a - b);
			}
		}
	}
	return flows::maxflow() - inf * L;
}

int calc2()
{
	int d2 = d * 2, c = L / d2;
	ll ret = (ll) 2e9;
	for (int i = 0; i < (1 << c); ++i)
	{
		for (int j = 0; j < c; ++j)
			f[(j + 1) * d2] = (i >> j & 1);
		ret = std::min(ret, calc2a());
	}
	return ret;
}

int main()
{
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	n = read(), d = read(), a = read(), b = read();
	for (int i = 0; i < n; ++i)
	{
		x[i] = read() - 1;
		got[x[i]] = 1;
		L = std::max(L, x[i]);
	}
	L += 2 * d + 1;
	printf("%d\n", d <= 7 ? calc1() : calc2());
	return 0;
}
