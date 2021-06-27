/*
	Author: Ruakker
	Date: 2021-07-14 15:34:39
	LastEditTime: 2021-07-14 15:54:40
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
ll n, id, ans, a[100010], f[100010], sum[100010];
char c[100010];
signed main() {
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	FastIO;
	cin >> n >> a[1];
	f[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> c[i] >> a[i];
		if (c[i] == '+')
			f[i] = f[i - 1] + a[i];
		else
			f[i] = f[i - 1] - a[i];
	}
	ans = f[n], id = n + 1;
	for (int i = n; i >= 1; i--) {
		sum[i] = sum[i + 1] + a[i];
		if (c[i] == '-')
			ans = std::max(ans, f[i - 1] + 2 * sum[id] - sum[i]), id = i;
	}
	cout << ans << endl;
	return 0;
}
