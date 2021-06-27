/**
 * File              : P4168.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-26 14:02:06
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#	define endl '\n'
#endif
using std::make_pair;
bool MEMST;
#define int long long
constexpr int N = 4e5 + 5;
int n, q, len, a[N], cnt[N];
int disc[N], original[N];
inline int query(int l, int r) {
	int max = -inf, res = l;
	for (int i = l; i <= r; ++i)
		cnt[a[i]] = 0;
	for (int i = l; i <= r; ++i)
		++cnt[a[i]];
	for (int i = l; i <= r; ++i)
		if (max < cnt[a[i]] || (max == cnt[a[i]] && a[i] < a[res]))
			max = cnt[a[i]], res = i;
	return original[res];
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		disc[i] = original[i] = a[i];
	}
	std::sort(disc + 1, disc + 1 + n);
	len = std::unique(disc + 1, disc + 1 + n) - disc - 1;
	for (int i = 1; i <= n; ++i)
		a[i] = std::lower_bound(disc + 1, disc + 1 + len, a[i]) - disc;
#ifdef DEBUG
	cerr << ">>> After Discretization, the max number is " << len << endl
	     << ">>> ";
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << ' ';
	cerr << endl
	     << ">>> The Disc[]: " << endl
	     << ">>> ";
	for (int i = 1; i <= len; ++i)
		cerr << disc[i] << ' ';
	cerr << endl;
#endif
	int lastAns = 0;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		// decrypt(l, r, lastAns);
		l = (l + lastAns - 1) % n + 1, r = (r + lastAns - 1) % n + 1;
		if (l > r) std::swap(l, r);
		lastAns = query(l, r);
		cout << lastAns << endl;
	}
	cout.flush();
	return 0;
}
