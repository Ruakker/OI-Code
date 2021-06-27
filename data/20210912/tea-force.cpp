/**
 * File              : tea.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 07:58:36
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
inline void force() {
	std::bitset<N> vis;
	vis.reset();
	int t = 0, tmp = 0, q = 0;
	for (;;) {
		for (int i = 1; i <= n; ++i)
			if (!vis[i]) {
				p[++q] = i, ++t, tmp = i, vis[i] = true;
				break;
			}
		for (int cnt = 0, i = tmp + 1; i <= n; ++i) {
			if (cnt == k - 1 && !vis[i])
				p[++q] = i, vis[i] = true, ++t, cnt = 0;
			if (!vis[i])
				++cnt;
		}
		if (t == n) break;
	}
}
bool MEMED;
signed main() {
#ifndef DEBUG
	fre(tea2);
#endif
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	force();
	for (int i = 1; i <= n; i++)
		ans = (1ll * ans * P + p[i]) % MOD;
	cout << ans << endl;
	return 0;
}

