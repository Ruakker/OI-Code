/**
 * File              : P3842.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 08:39:12
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#	define endl '\n'
#endif
bool MEMST;
const int N = 2e4 + 5;
int dp[N][2], n;
std::pair<int, int> info[N];
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> info[i].first >> info[i].second;
	dp[1][0] = info[1].first - 1 + info[1].second - info[1].first, dp[1][1] = info[1].second - 1 + info[1].second - info[1].first;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = std::min(dp[i - 1][0] + abs(info[i - 1].first - info[i].second) + abs(info[i].second - info[i].first), dp[i - 1][1] + abs(info[i - 1].second - info[i].second) + abs(info[i].second - info[i].first));
		dp[i][1] = std::min(dp[i - 1][0] + abs(info[i - 1].first - info[i].first) + abs(info[i].first - info[i].second), dp[i - 1][1] + abs(info[i - 1].second - info[i].first) + abs(info[i].first - info[i].second));
	}
	cout << std::min(dp[n][0], dp[n][1]) << endl;
	cout.flush();
	return 0;
}

