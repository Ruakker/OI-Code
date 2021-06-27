/**
 * File              : CF1566A.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 22:33:01
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

bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	int T;
	cin >> T;
	for (; T--;) {
		int n, m;
		cin >> n >> m;
		int ans = m / (n / 2 + 1);
		cout << ans << endl;
	}
	cout.flush();
	return 0;
}

