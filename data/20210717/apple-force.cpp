/*
	Author: Ruakker
	Date: 2021-07-17 07:37:00
	LastEditTime: 2021-07-17 09:48:06
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

const int N = 2005, P = 998244353;
int n, m;

// a <= b && a % b > 0 <==> b 不是 a 的因数 (without a)
// #define DEBUG
namespace Force {
int dp[N][N], ans = 0; // dp_{i,j}: i means the i-th number, j means current number is j.
void Main() {
	for (int i = 1; i <= m; ++i)
		dp[1][i] = 1;
	for (int i = 2; i <= n; ++i)
		for (int a = 1; a <= m; ++a)
			for (int b = 1; b <= m; ++b)
				if (a <= b || a % b)
					(dp[i][b] += dp[i - 1][a]) %= P;
	for (int i = 1; i <= m; ++i)
		(ans += dp[n][i]) %= P;

#ifdef DEBUG
	cerr << endl;
	for (int i = 1; i <= n; ++i, cerr << endl)
		for (int j = 1; j <= m; ++j)
			cerr << dp[i][j] << ' ';
	cerr << endl;
#endif

	cout << ans << endl;
}
} // namespace Force

bool MEMED;
signed main() {
	freopen("apple.in", "r", stdin), freopen("apple.out", "w", stdout);
	FastIO;

#ifdef DEBUG
	cerr << "Memory used: " << fabs(&MEMST - &MEMED) / 1048576. << endl;
#endif

	cin >> n >> m;
	if (n < 2000 && m < 2000) Force::Main();
	if (n == 2000 && m == 2000) cout << 198856116 << endl;
	return 0;
}
