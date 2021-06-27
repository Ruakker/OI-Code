/**
 * File              : makedata.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 16:09:13
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
const int N = 1e6 + 5;
std::mt19937 Rand(time(nullptr));
bool MEMED;
signed main() {
	freopen("light.in", "w", stdout);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	for (int i = 1; i <= 1e6; ++i)
		cout << (Rand() & 1);
	cout << endl;
	cout << Rand() % 1000000 << endl;
	cout.flush();
	return 0;
}

