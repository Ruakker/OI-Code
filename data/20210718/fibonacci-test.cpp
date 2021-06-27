/*
	Author: Ruakker
	Date: 2021-07-18 07:59:43
	LastEditTime: 2021-07-18 08:28:15
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

#define DEBUG

const int N = 1e6 + 5, P = 1e9 + 7;
int n, m;
ll ans, fibo[N];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline void getFibonacci(int n) {
	fibo[1] = 1, fibo[0] = 0;
	for (int i = 2; i <= n; ++i)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % P;
}

bool MEMED;
signed main() {
	// fre(fibonacci);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << (&MEMST - &MEMED) / 1048576. << endl;
#endif
	getFibonacci(1e6);
	int T;
	cin >> T;
	cout << '\\' << '\t';
	for (int i = 1; i <= T; ++i)
		cout << i << '\t';
	cout << endl
	     << 1 << '\t';
	for (int n = 1; n <= T; cout << endl
	                             << ++n << '\t')
		for (int m = 1; m <= T; ++m) {
			ans = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					(ans += gcd(fibo[i], fibo[j])) %= P;
			cout << ans << '\t';
		}
	return 0;
}
