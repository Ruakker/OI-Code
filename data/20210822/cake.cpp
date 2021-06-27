/**
 * File              : cake.cpp
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
#define int long long
const int N = 3e6 + 5;
int n, k, All, fst, sec;
int f[N][3];
bool MEMED;
signed main() {
	fre(cake);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		f[i][1] = 1;
	int pres = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		pres += f[i - 1][1];
		if (i > n + 1) pres -= f[i - n - 1][1];
		f[i][2] = pres;
	}
	pres = 0;
	for (int i = 1; i <= 3 * n; ++i) {
		pres += f[i - 1][2];
		if (i > n + 1) pres -= f[i - n - 1][2];
		f[i][3] = pres;
	}
	All = 1;
	for (;;) {
		if (k - f[All][3] <= 0) break;
		k -= f[All][3];
		++All;
	}
	fst = std::max(1ll, All - 2 * n);
	for (;;) {
		if (k - f[All - fst][2] <= 0) break;
		k -= f[All - fst][2];
		++fst;
	}
	sec = std::max(1ll, All - fst - n);
	while (true) {
		if (k - f[All - fst - sec][1] == 0) break;
		k -= f[All - fst - sec][1];
		++sec;
	}
	cout << fst << ' ' << sec << ' ' << All - fst - sec << endl;
	cout.flush();
	return 0;
}
