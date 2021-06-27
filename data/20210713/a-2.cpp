/*
	Author: Ruakker
	Date: 2021-07-13 15:38:02
	LastEditTime: 2021-07-13 21:25:07
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0), std::cerr.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define int long long
inline int max(int a, int b) { return a > b ? a : b; }
int n, m, k, p, tmp;
int sum(int x, int y) {
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	int res = y - x + 1;
	if (res & 1)
		return (res % p) * ((x + y >> 1) % p) % p;
	else
		return ((res + 1 >> 1) % p) * ((x + y) % p) % p;
}
int calc(int n, int m, int k) {
	if (n < 0 || m < 0) return 0;
	if (n == 0 && m == 0) return max(((n - 1) ^ (m - 1)) - k, tmp) % p;
	if (n < m) std::swap(n, m);
	int l = 0, t;
	for (; 1ll << l <= n + 1; ++l)
		;
	t = (1ll << --l) - 1;
	if (t <= m)
		return ((t + 1) % p * sum(-k, t - k) % p + (n - t + m - t) % p * sum(t + 1 - k, t + t + 1 - k) % p + calc(n - t - 1, m - t - 1, k)) % p;
	else
		return ((m + 1) % p * sum(max(-k, tmp), max(tmp, t - k)) % p + calc(n - t - 1, m, k - t - 1)) % p;
}
signed main() {
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	FastIO;
	int T;
	for (cin >> T; T--;) {
		cin >> n >> m >> k >> p;
		cout << calc(n - 1, m - 1, k) << endl;
	}
	return 0;
}
