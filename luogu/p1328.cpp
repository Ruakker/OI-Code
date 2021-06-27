/**
 * File              : rps.cpp
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
constexpr int N = 2005;
constexpr bool table[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}};
int n, na, nb, tmp;
int ansa, ansb;
std::vector<int> a, b;
bool MEMED;
signed main() {
	fre(rps);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> na >> nb;
	for (int i = 1; i <= na; ++i) {
		cin >> tmp;
		a.emplace_back(tmp);
	}
	for (int i = 1; i <= nb; ++i) {
		cin >> tmp;
		b.emplace_back(tmp);
	}
	for (int i = 0, j = 0; n--;) {
		ansa += table[a[i]][b[j]];
		ansb += table[b[j]][a[i]];
		++i, ++j;
		if (i >= na) i = 0;
		if (j >= nb) j = 0;
	}
	cout << ansa << ' ' << ansb << endl;
	cout.flush();
	return 0;
}
