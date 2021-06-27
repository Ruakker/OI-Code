/**
 * File              : P3396.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-26 09:59:06
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
bool MEMST;
#define int long long
constexpr int N = 1.5e5 + 5, M = sqrt(1.5e5) + 5;
int n, q, m, bel[N], a[N];
int table[M][M]; // table_{i,j} means the count of ans which the number % i = j
inline void init() {
	m = sqrt(n);
	for (int i = 1; i <= n; ++i)
		for (int p = 1; p <= m; ++p)
			table[p][i % p] += a[i];
}
inline int query(int p, int q) {
	if (p <= m) return table[p][q];
	int res = 0;
	for (int i = q; i <= n; i += p)
		res += a[i];
	return res;
}
inline void modify(int pos, int val) {
	for (int p = 1; p <= m; ++p)
		table[p][pos % p] -= a[pos];
	a[pos] = val;
	for (int p = 1; p <= m; ++p)
		table[p][pos % p] += a[pos];
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	init();
	for (int i = 1; i <= q; ++i) {
		char opt;
		int x, y;
		cin >> opt >> x >> y;
		if (opt == 'A') cout << query(x, y) << endl;
		if (opt == 'C') modify(x, y);
	}
	cout.flush();
	return 0;
}

