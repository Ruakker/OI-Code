/**
 * File              : LOJ6278.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-25 10:24:49
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
#define int long long
bool MEMST;
constexpr int N = 5e4 + 5, M = sqrt(5e4) + 5;
struct Block {
	Block(int a, int b) { begin = a, end = b, add = size = 0; }
	Block() { begin = end = add = size = 0; }
	int begin, end, add, size;
} b[N];
int a[N], n, m, bel[N];
std::vector<int> t[N];
inline void init() {
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = b[i].begin; j <= b[i].end; ++j)
			bel[j] = i, t[i].emplace_back(a[j]);
		b[i].size = b[i].end - b[i].begin + 1;
	}
	for (int i = 1; i <= m; ++i)
		std::sort(t[i].begin(), t[i].end());
}
inline void resort(int u) {
	t[u].clear();
	for (int i = b[u].begin; i <= b[u].end; ++i)
		t[u].emplace_back(a[i]);
	std::sort(t[u].begin(), t[u].end());
}
inline void modify(int l, int r, int val) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i)
			a[i] += val;
		resort(bel[l]);
		return;
	}
	for (int i = l; i <= b[bel[l]].end; ++i)
		a[i] += val;
	for (int i = b[bel[r]].begin; i <= r; ++i)
		a[i] += val;
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		b[i].add += val;
	resort(bel[l]), resort(bel[r]);
}
inline int query(int l, int r, int val) {
	int res = 0;
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i)
			if (a[i] + b[bel[i]].add < val) ++res;
		return res;
	}
	for (int i = l; i <= b[bel[l]].end; ++i)
		if (a[i] < val - b[bel[i]].add) ++res;
	for (int i = b[bel[r]].begin; i <= r; ++i)
		if (a[i] < val - b[bel[i]].add) ++res;
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		res += std::lower_bound(t[i].begin(), t[i].end(), val - b[i].add) - t[i].begin();
	return res;
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	m = sqrt(n);
	init();
	for (int i = 1; i <= n; ++i) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;
#ifdef DEBUG
		cerr << "i: " << i << endl;
		for (int i = 1; i <= n; ++i)
			cerr << a[i] << ' ';
		cerr << endl;
		for (int i = 1; i <= m; ++i)
			cerr << b[i].add << ' ';
		cerr << endl;
#endif
		if (opt)
			cout << query(l, r, c * c) << endl;
		else
			modify(l, r, c);
	}
	cout.flush();
	return 0;
}

