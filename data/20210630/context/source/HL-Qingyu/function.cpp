#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 1e6 + 50;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

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

fast_io<N> io;

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

int pri[N], f[N], tot;
bool np[N];

inline void init(int n)
{
	np[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (!np[i])
		{
			pri[++tot] = i;
		}
		for (int j = 1; j <= tot && i * pri[j] <= n; ++j)
		{
			np[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
}

int main()
{
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	init(1e6);
	f[1] = 1;
	const int n = 1e6;
	for (int i = 1; i <= tot; ++i)
		if (pri[i] % 3 == 1) f[pri[i]] = 1;
		else f[pri[i]] = -1;
	for (int d = 1; d <= n; ++d)
		for (int i = d + d; i <= n; i += d)
			f[i] = f[d] * f[i / d];
	for (int i = 1; i <= n; ++i) output(f[i]);
	return 0;
}
