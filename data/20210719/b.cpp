/*
	Author: Ruakker
	Date: 2021-07-19 15:10:48
	LastEditTime: 2021-07-19 15:47:52
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

#define int long long
const int N = 2005;
int n, k, P, a[N][N];

inline void init(int m) {
	a[1][1] = 1;
	for (int i = 2; i <= m; ++i)
		for (int j = 1; j <= i; ++j)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
}

bool MEMED;
signed main() {
	fre(b);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif

	init(2000);
	int T;
	for (cin >> T; T--;) {
		int ans = 0;
		cin >> n >> k >> P;
		++n, ++k;
		if (k <= n >> 1) { // Down from left
			int downline = n - k;
			ans = downline % P;
			for (int i = 1; i <= k; ++i)
				(ans += a[i + downline][i]) %= P;
		} else {
			ans = k % P;
			for (int i = 1; i <= n - k; ++i)
				(ans += a[i + k][k]) %= P;
		}
		cout << ans << endl;
	}

	return 0;
}
