/*
	Author: Ruakker
	Date: 2021-07-14 07:37:39
	LastEditTime: 2021-07-14 15:39:45
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#define int long long
#define fi first
#define se second
const int N = 1e1 + 5;
int n, dp[N];
std::pair<int, int> a[N]; //first: -1 means '-', 1 means '+'; second: the number
signed main() {
	// freopen("a.in","r",stdin),freopen("a.out","w",stdout);
	FastIO;
	a[1].fi = 1;
	cin >> n >> a[1].se;
	for (int i = 2; i <= n; ++i) {
		char ch;
		cin >> ch >> a[i].se;
		if (ch == '+')
			a[i].fi = 1;
		else if (ch == '-')
			a[i].fi = -1;
		else
			cerr << "Error" << endl;
	}

	for (int i = 1; i <= n; ++i) {
		int max = -inf, l = 0, r = 0;
		for (int j = 1; j <= i; ++j) { // the brackets is from j to i.
			int res = 0, tmp = a[j].se;
			for (int k = 1; k < j; ++k)
				res += a[k].fi * a[k].se;
			for (int k = j + 1; k <= i; ++k)
				tmp += a[k].fi * a[k].se;
			res += tmp * a[j].fi;
			if (res > max) l = j, r = i;
		}
		int res = a[l].se;
		for (int j = l + 1; j <= r; ++j) {
			res += a[j].fi * a[j].se;
			a[j] = std::make_pair(0, 0);
		}
		a[l].se = res;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += a[i].fi * a[i].se;
	cout << ans << endl;
	return 0;
}
