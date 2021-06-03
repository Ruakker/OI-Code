/*
	Author: Ruakker
	Date: 2021-05-15 15:14:33
	LastEditTime: 2021-05-15 15:49:33
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define lson segt[k].left
#define rson segt[k].right
inline ll read() {
	ll x = 0, w = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') w = -1;
	for (; isdigit(ch); ch = getchar())
		x = x * 10 + (ch - '0');
	return x * w;
}
void write(ll x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeln(ll x) { write(x), putchar('\n'); }
const int N = 2e5 + 5;
struct Ruakker {
	int val, left, right;
} segt[N << 5];
int cnt, n, m, a[N], rt;
inline void newnode(int &k) { segt[k = ++cnt].val = lson = rson = 0; }
void ins(int val, int l, int r, int &k) {
}
signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	build(1, n, rt);
	return 0;
}
