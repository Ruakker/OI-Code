/**
 * File              : makedata.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/22
 * Last Modified Date: 2021/08/22
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
bool MEMST;
const int N = 2e5;
std::mt19937 Rand(time(nullptr));
bool MEMED;
signed main() {
	fre(link);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cout << N << endl;
	for (int i = 1; i < N; ++i)
		cout << i << ' ' << i + 1 << endl;
	for (int i = 1; i <= N; ++i)
		cout << Rand() % 114514 << ' ';
	cout << endl;
	cout.flush();
	return 0;
}
