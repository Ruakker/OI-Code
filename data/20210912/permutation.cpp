/**
 * File              : permutation.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 10:30:54
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
const int N = 114514, P = 998244353;
int n, k, a[N], ans;
std::bitset<N> vis;
inline void check() {
	for (int i = 1; i <= n; ++i)
		if (abs(a[i] - i) == k) return;
	++ans;
	if (ans >= P) ans -= P;
#ifdef DEBUG
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << ' ';
	cerr << endl;
#endif
}
void dfs(int depth) {
	if (depth > n) return check();
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		a[depth] = i;
		vis.set(i);
		dfs(depth + 1);
		vis.reset(i);
	}
}
bool MEMED;
signed main() {
#ifndef DEBUG
	fre(permutation);
#endif
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	dfs(1);
	cout << ans << endl;
	return 0;
}

