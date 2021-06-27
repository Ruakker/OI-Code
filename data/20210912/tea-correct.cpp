/**
 * File              : tea-correct.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 15:38:28
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
int n, k, f[N], g[N], p[N], fuck;
long long ans;
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		if (i % k == 1)
			f[i] = 1;
		else
			f[i] = f[i - (i + k - 1) / k] + 1;
	for (int i = 1; i <= n; i++)
		fuck = std::max(fuck, f[i]), g[f[i]]++;
	for (int i = 1; i <= fuck; i++)
		g[i] += g[i - 1];
	for (int i = n; i; i--)
		p[g[f[i]]--] = i;
	for (int i = 1; i <= n; ++i)
		ans = (1ll * ans * P + p[i]) % MOD;
	cout << ans << endl;
	cout.flush();
	return 0;
}

