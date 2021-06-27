/**
 * File              : 7025.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/21
 * Last Modified Date: 2021/08/21
 */
//#include <bits/stdc++.h>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
#define int long long
#define inf 0x3f3f3f3f
bool MEMST;
const int N = 2e7 + 5;
int n, ans;
std::bitset<N> isPrime;
std::vector<int> prime, b;
inline void getPrime(int n) {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i <= n; ++i)
		if (isPrime[i]) {
			prime.emplace_back(i);
			if (i & 1) b.emplace_back(i / 2 + 1);
			for (int j = 1ll * i * i; j <= n; j += i)
				isPrime[j] = 0;
		}
}
inline bool checkPrime(int x) { return x >= 2 && isPrime[x]; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
bool MEMED;
signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef DEBUG
	cerr << abs(&MEMST - &MEMED) / 1048576.0 << endl;
#endif
	getPrime(2e7);
	int T;
	for (cin >> T; T--;) {
		cin >> n;
		if (checkPrime(n)) { // r-l+1=1
			cout << 1 << endl;
			continue;
		}
		if (checkPrime(n + n - 1) || checkPrime(n + n + 1)) { // r-l+1=2
			cout << 2 << endl;
			continue;
		}
		if (n <= -9999999) {
			cout << 20000003 << endl;
			continue;
		}
		/*
		 * r-l+1=p
		 * r-l=p-1
		 */
		ans = inf;
		int tmp = 0;
		if (n >= 0) {
			tmp = *std::lower_bound(prime.begin(), prime.end(), n);
			ans = min(ans, 2 * tmp);
			tmp = *std::lower_bound(b.begin(), b.end(), n);
			ans = min(ans, 2 * tmp - 1);
		} else {
			tmp = *std::lower_bound(prime.begin(), prime.end(), -n + 1);
			ans = min(ans, 2 * tmp);
			tmp = *std::lower_bound(b.begin(), b.end(), -n + 2);
			ans = min(ans, 2 * tmp - 1);
		}
		cout << ans << endl;
	}
	cout.flush();
}
