/*
	Author: Ruakker
	Date: 2021-07-18 07:59:43
	LastEditTime: 2021-07-18 13:22:07
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

// #define DEBUG
#define int long long

const int N = 1005, P = 1e9 + 7;
int n, m, fibo[N], f[N][N], g[N][N];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline void getFibonacci(int n) {
	fibo[1] = 1, fibo[0] = 0;
	for (int i = 2; i <= n; ++i)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % P;
}

bool MEMED;
signed main() {
	fre(fibonacci);
	FastIO;

#ifdef DEBUG
	cerr << "Memory used: " << (&MEMST - &MEMED) / 1048576. << endl;
#endif

	getFibonacci(1001);
	for (int i = 1; i <= 1000; ++i)
		for (int j = 1; j <= 1000; ++j)
			f[i][j] = gcd(fibo[i], fibo[j]);

#ifdef DEBUG
	cerr << endl;
	for (int i = 1; i <= 20; ++i, cerr << endl)
		for (int j = 1; j <= 20; ++j)
			cerr << f[i][j] << '\t';
	cerr << endl;
#endif

	for (int i = 1; i <= 1000; ++i)
		for (int j = 1; j <= 1000; ++j)
			g[i][j] = (f[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1]) % P;

	int T;
	for (cin >> T; T--;) {
		cin >> n >> m;
		cout << g[n][m] << endl;
	}
	return 0;
}
