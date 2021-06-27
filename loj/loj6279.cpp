/**
 * File              : LOJ6279.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-25 14:52:54
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
constexpr int N = 1e5 + 5, M = sqrt(1e5) + 5;
struct Block {
	Block(int a, int b) { begin = a, end = b, add = size = 0; }
	Block() { begin = end = add = size = 0; }
	int begin, end, add, size;
} b[N];
int a[N], n, m, bel[N];
std::set<int> s[M];
inline void init() {
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = b[i].begin; j <= b[i].end; ++j)
			bel[j] = i, s[i].insert(a[j]);
		b[i].size = b[i].end - b[i].begin + 1;
	}
}
inline void modify(int l, int r, int val) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i) {
			s[bel[i]].erase(a[i]);
			a[i] += val;
			s[bel[i]].insert(a[i]);
		}
		return;
	}
	for (int i = l; i <= b[bel[l]].end; ++i) {
		s[bel[i]].erase(a[i]);
		a[i] += val;
		s[bel[i]].insert(a[i]);
	}
	for (int i = b[bel[r]].begin; i <= r; ++i) {
		s[bel[i]].erase(a[i]);
		a[i] += val;
		s[bel[i]].insert(a[i]);
	}
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
		b[i].add += val;
}
inline int query(int l, int r, int val) {
	int res = -1;
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; ++i) {
			int cur = a[i] + b[bel[i]].add;
			if (cur < val && cur > res) res = cur;
		}
		return res;
	}
	for (int i = l; i <= b[bel[l]].end; ++i) {
		int cur = a[i] + b[bel[i]].add;
		if (cur < val && cur > res) res = cur;
	}
	for (int i = b[bel[r]].begin; i <= r; ++i) {
		int cur = a[i] + b[bel[i]].add;
		if (cur < val && cur > res) res = cur;
	}
	for (int i = bel[l] + 1; i <= bel[r] - 1; ++i) {
		auto iter = s[i].lower_bound(val - b[i].add);
		if (iter == s[i].begin()) continue;
		res = std::max(*(--iter) + b[i].add, res);
	}
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
			cout << query(l, r, c) << endl;
		else
			modify(l, r, c);
	}
	cout.flush();
	return 0;
}

