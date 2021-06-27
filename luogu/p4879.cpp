/**
 * File              : P4879.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-26 08:30:59
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
// #define int long long
constexpr int N = 1e6 + 5, M = sqrt(1e6) + 5;
int n, stn, m, q, bel[N];
ll a[N];
std::bitset<N> existed;
struct Block {
	Block() { begin = end = size = tot = 0; }
	Block(int l, int r) { begin = l, end = r, size = tot = 0; }
	int begin, end, size;
	ll tot;
} b[M];
inline void init() {
	n = 5e5, m = sqrt(5e5);
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i)
		for (int j = b[i].begin; j <= b[i].end; ++j) {
			bel[j] = i, b[i].tot += a[j];
			if (existed[j]) ++b[i].size;
		}
}
inline void modify(int pos, int val) {
	a[pos] += val, b[bel[pos]].tot += val;
}
inline void ins(int pos, int val) {
	if (existed[pos])
		b[bel[pos]].tot -= a[pos];
	else
		existed[pos] = 1, ++b[bel[pos]].size;
	a[pos] = val, b[bel[pos]].tot += val;
}
inline void del(int kth) {
	int sum = 0, pos, target = m;
	for (int i = 1; i <= m; ++i) {
		sum += b[i].size;
		if (sum >= kth) {
			target = i;
			break;
		}
	}
	sum -= b[target].size;
	for (int i = b[target].begin; i <= b[target].end; ++i) {
		if (existed[i]) ++sum;
		if (sum == kth) {
			pos = i;
			break;
		}
	}
	b[bel[pos]].tot -= a[pos], --b[bel[pos]].size;
	a[pos] = 0, existed[pos] = 0;
}
inline ll query() {
	ll res = 0;
	for (int i = 1; i <= m; ++i)
		res += b[i].tot;
	return res;
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> stn >> q;
	for (int i = 1; i <= stn; ++i)
		cin >> a[i], existed.set(i);
	init();
	for (int i = 1; i <= q; ++i) {
		char opt;
		int pos, val;
		cin >> opt;
		if (opt == 'C') {
			cin >> pos >> val;
			modify(pos, -val);
		}
		if (opt == 'I') {
			cin >> pos >> val;
			ins(pos, val);
		}
		if (opt == 'D') {
			cin >> pos;
			del(pos);
		}
		if (opt == 'Q')
			cout << query() << endl;
	}
	cout.flush();
	return 0;
}

