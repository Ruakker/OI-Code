/**
 * File              : makedata.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 10:07:51
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
std::mt19937 Rand(time(nullptr));
bool MEMED;
signed main() {
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	int n = Rand() % 20000;
	int m = Rand() % n;
	freopen("tea1.in", "w", stdout);
	cout << n << ' ' << m << endl;
	freopen("tea2.in", "w", stdout);
	cout << n << ' ' << m << endl;
	cout.flush();
	return 0;
}

