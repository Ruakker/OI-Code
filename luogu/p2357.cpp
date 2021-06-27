/**
 * File              : P2357.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-26 07:26:35
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
constexpr int N = 2e5 + 5, M = sqrt(2e5) + 5;
struct Block {
	Block(int l, int r) { begin = l, end = r, size = r - l + 1, add = tot = 0; }
	Block() { begin = end = size = add = tot = 0; }
	int begin, end, size, add, tot;
} b[M];
int a[N], bel[N], n, m, f;
bool MEMED;
inline void init() {
	m = sqrt(n);
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = b[i].begin; j <= b[i].end; ++j)
			bel[j] = i, b[i].tot += a[j];
	}
}
inline void modify(int l, int r, int val) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i)
			a[i] += val, b[bel[i]].tot += val;
		return;
	}
	for (int i = l; i <= b[bel[l]].end; ++i)
		a[i] += val, b[bel[i]].tot += val;
	for (int i = b[bel[r]].begin; i <= r; ++i)
		a[i] += val, b[bel[i]].tot += val;
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		b[i].add += val;
}
inline int query(int l, int r) {
	int res = 0;
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i)
			res += a[i] + b[bel[i]].add;
		return res;
	}
	for (int i = l; i <= b[bel[l]].end; ++i)
		res += a[i] + b[bel[i]].add;
	for (int i = b[bel[r]].begin; i <= r; ++i)
		res += a[i] + b[bel[i]].add;
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		res += b[i].tot + b[i].add * b[i].size;
	return res;
}
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> f;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	init();
	for (int i = 1; i <= f; ++i) {
		int opt, l, r, val;
		cin >> opt;
		if (opt == 1) {
			cin >> l >> r >> val;
			modify(l, r, val);
		}
		if (opt == 2) {
			cin >> val;
			modify(1, 1, val);
		}
		if (opt == 3) {
			cin >> val;
			modify(1, 1, -val);
		}
		if (opt == 4) {
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
		if (opt == 5) {
			cout << query(1, 1) << endl;
		}
	}
	cout.flush();
	return 0;
}

