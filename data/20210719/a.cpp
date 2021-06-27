/*
	Author: Ruakker
	Date: 2021-07-19 13:36:12
	LastEditTime: 2021-07-19 21:24:35
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
const int N = 1e6 + 5;
int n, ans;

inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

bool MEMED;
signed main() {
	// fre(a);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	int T;
	for (cin >> T; T--;) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			ans += lcm(i, n);
		cout << ans << endl;
	}
	return 0;
}
