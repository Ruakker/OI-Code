#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 1e6 + 50;
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

inline long long f(long long k)
{
	return k * (k - 1) / 2;
}

inline int get(long long n, long long target)
{
	long long l = 1, r = n, ans = -1;
	while (l <= r)
	{
		const long long mid = l + r >> 1;
		if (f(mid) <= target) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

inline void solve(long long n)
{
	long long L = 0;
	while (f(L) < n) ++L;
	long long target = f(L) - n;
	int o = 0;
	while (L)
	{
		int i = get(L, target);
		{
			if (f(i) <= target)
			{
				target -= f(i);
				L -= i;
				for (int j = 0; j < i; ++j) printf("%d", o);
				assert(target >= 0);
			}
		}
		o = !o;
	}
	putchar('\n');
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T = read();
	while (T--) solve(read());
	return 0;
}
