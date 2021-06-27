/**
 * File              : array.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 14:18:45
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define endl '\n'
bool MEMST;
const int N = 1e5 + 5, M = sqrt(1e5) + 5;
struct Block {
	Block(int l, int r) { begin = l, end = r, size = r - l + 1, add = ans = 0; }
	Block() { begin = end = add = ans = size = 0; }
	int begin, end, add, ans, size;
} b[M];
int a[N], n, m, q, bel[N];
inline int calc(int k) {
	for (int i = b[k].begin; i <= b[k].end; ++i) {
		if (a[i] > a[i])
	}
}
inline void init() {
	m = sqrt(n);
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = b[i].begin; j <= b[i].end; ++j)
			bel[j] = i;
		b[i].ans = calc(i);
	}
}
inline void modify(int l, int r, int val) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i)
			a[i] += val;
		return;
	}
	for (int i = l; i <= b[bel[l]].end; ++i)
		a[i] += val;
	for (int i = b[bel[r]].begin; i <= r; ++i)
		a[i] += val;
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		b[i].add += val;
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
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1) {
			int val;
			cin >> val;
			modify(l, r, val);
		} else
			cout << query(l, r) << endl;
	}
	cout.flush();
	return 0;
}
