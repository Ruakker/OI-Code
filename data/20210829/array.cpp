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
const int N = 1e5 + 5;
int n, q, a[N], b[N];
inline void modify(int l, int r, int val) {
	for (int i = l; i <= r; ++i)
		a[i] += val;
}
inline int query(int l, int r) {
	int res = 0;
	for (int i = l; i <= r; ++i)
		b[i] = a[i];
	b[l - 1] = b[r + 1] = 0;
	bool flag = 1;
	for (;;) {
		flag = 1;
		for (int i = l; i <= r; ++i)
			if (b[i] && !b[i - 1])
				++res;
		for (int i = l; i <= r; ++i) {
			if (b[i]) --b[i];
			if (b[i]) flag = 0;
		}
		if (flag) break;
	}
	return res;
}
bool MEMED;
signed main() {
	fre(array);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
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

