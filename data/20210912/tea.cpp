/**
 * File              : tea.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 07:58:36
 *
 * 哼哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
 * FUCK THIS PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
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
bool MEMST;
const int N = 2e7 + 5, P = 19260817, MOD = 998244353;
int n, k, p[N];
long long ans;
struct Fenwick {
	inline int lowbit(int x) { return x & -x; }
	int c[N], n;
	inline void build() {
		for (int i = 1; i <= n; ++i) {
			++c[i];
			int j = i + lowbit(i);
			if (j <= n) c[j] += c[i];
		}
	}
	inline void add(int k, int val) {
		for (; k <= n; k += lowbit(k))
			c[k] += val;
	}
	inline int query(int k) {
		int res = 0;
		for (; k >= 1; k -= lowbit(k))
			res += c[k];
		return res;
	}
	inline int query(int l, int r) {
		return query(r) - query(l - 1);
	}
} t;
inline bool check(int k, int val) {
	return !(t.query(k) >= val);
}
inline int binarySearch(int val, int l = 0, int r = n + 1) { // 查找 l 到 r 中前缀和为 val 的第一个点。
	int res = -1;
	for (; l + 1 < r;) {
		int mid = (l + r) >> 1;
#ifdef DEBUG
		cerr << "Mid: " << mid << " l: " << l << " r: " << r << endl;
#endif
		if (check(mid, val))
			l = mid;
		else
			res = r = mid;
	}
#ifdef DEBUG
	if (res != -1 && t.query(res) != val)
		cerr << "ERROR" << endl;
#endif
	return res;
}
inline void init() {
	int cnt = 0;
	for (; cnt < n;) {
		int st = binarySearch(1);
		t.add(st, -1), p[++cnt] = st;
		if (cnt >= n) break;
		for (;;) {
			int cur = binarySearch(t.query(cur) + k, st - 1);
			if (cur == -1) break;
			t.add(cur, -1), p[++cnt] = cur, st = cur;
		}
	}
}
bool MEMED;
signed main() {
#ifndef DEBUG
	fre(tea);
#endif
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	t.n = n;
	t.build();
	init();
#ifdef DEBUG
	cerr << ">>> ";
	for (int i = 1; i <= n; ++i)
		cerr << p[i] << ' ';
	cerr << endl;
#endif
	for (int i = 1; i <= n; ++i)
		ans = (1ll * ans * P + p[i]) % MOD;
	cout << ans << endl;
	return 0;
}

