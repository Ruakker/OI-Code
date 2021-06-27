/*
    Author: Ruakker
    Date: 2021-05-15 18:37:34
	LastEditTime: 2021-05-15 19:23:28
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
inline ll read() {
	ll x = 0, w = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') w = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
	return x * w;
}
void write(ll x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeln(ll x) { write(x), putchar('\n'); }
const int N = 50, P = 1e7 + 7;
int n, cnt, ans = 1, g[N];
inline ll qpow(int a, int b) {
	ll res = 1;
	for (; b; a = a * a % P, b >>= 1)
		if (b & 1) res = res * a % P;
	return res;
}
signed main() {
	n = read();
	for (int i = 49; i >= 0; --i) {
		for (int j = 49; j >= 1; --j)
			g[j] += g[j - 1];
		if (n >> i & 1) ++g[cnt++];
	}
	++g[cnt];
	for (int i = 1; i <= 49; ++i)
		ans = ans * qpow(i, g[i]) % P;
	writeln(ans);
	return 0;
}
