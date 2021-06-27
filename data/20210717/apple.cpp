/*
	Author: Ruakker
	Date: 2021-07-17 07:37:00
	LastEditTime: 2021-07-17 09:06:30
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
const int N = 2005, P = 998244353;
int n, m, divers[N], dp[N][N];
std::bitset<N> isprime;
std::vector<int> primes;

#define DEBUG
void GetPrime(int m) {
	isprime.set();
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i * i <= m; i++) {
		if (isprime[i]) {
			for (int j = i << 1; j <= m; j += i)
				isprime[j] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)
		if (isprime[i]) primes.push_back(i);

#ifdef DEBUG
	cerr << endl;
	for (auto i = primes.begin(); i != primes.end(); i++)
		cerr << *i << ' ';
	cerr << endl
	     << endl;
#endif
}

void GetDiver(int m) {
	std::fill(divers + 1, divers + 1 + m, 1);
	for (std::vector<int>::iterator i = primes.begin(); i != primes.end(); i++) {
		for (int j = 1; j <= m; ++j) {
			int cnt = 0;
			for (int num = j, diver = *i; num % diver == 0; num /= diver, ++cnt)
				;
			divers[j] *= cnt + 1;
		}
	}

#ifdef DEBUG
	cerr << endl;
	for (int i = 1; i <= m; ++i)
		cerr << divers[i] << ' ';
	cerr << endl
	     << endl;
#endif
}

signed main() {
	// freopen("apple.in", "r", stdin), freopen("apple.out", "w", stdout);
	FastIO;
	cin >> n >> m;
	GetPrime(m);
	GetDiver(m);
	for (int i = 1; i <= m; ++i)
		dp[1][i] = 1;
	// for (int i = 2; i <= n; ++i)
	// 	for (int a = 1; a <= m; ++a)
	// 		for (int b = 1; b <= m; ++b)
	// 			if (a <= b || a % b)
	// 				(dp[i][b] += dp[i - 1][a]) %= P;
	// for (int i = 1; i <= m; ++i)
	// 	(ans += dp[n][i]) %= P;

	return 0;
}
