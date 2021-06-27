/**
 * File              : coin.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 07:33:03
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
#define int long long
constexpr int N = 2e5 + 5, M = 2e7 + 5;
int n, m = 2e7, a, b;
int ans[M];
inline int min(int a, int b) { return a < b ? a : b; }
inline int min(int a, int b, int c) { return min(a, min(b, c)); }
inline int min(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }
bool MEMED;
signed main() {
#ifndef DEBUG
	fre(coin);
#endif
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	memset(ans, 0x3f, sizeof ans);
	ans[0] = 0;
	cin >> n >> a >> b;
	for (int i = 1; i <= m; ++i) {
		// ans[i] = ans[i - 1] + a;
		if (i & 1)
			ans[i] = min(ans[i - 1] + a, ans[(i + 1) >> 1] + a + b);
		else
			ans[i] = min(ans[i - 1] + a, ans[i >> 1] + b);
	}
#ifdef DEBUG
	cerr << ">>> ";
	for (int i = 1; i <= 20; ++i)
		cerr << ans[i] << ' ';
	cerr << endl;
#endif
	for (int i = 1, c; i <= n; ++i) {
		cin >> c;
		cout << ans[c] << ' ';
	}
	cout << endl;
	return 0;
}

