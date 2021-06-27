/**
 * File              : sequence.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 14:42:37
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
#define int long long
const int N = 2e5 + 5, P = 998244353, logn = 21;
int n, a[N], ans;
inline int getGcd(int a, int b) { return (b == 0) ? a : getGcd(b, a % b); }
bool MEMED;
signed main() {
	fre(sequence);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int l = 1; l <= n; ++l) {
		int max = a[l], gcd = a[l];
		(ans += max * gcd % P) %= P;
		for (int r = l + 1; r <= n; ++r) {
			max = std::max(max, a[r]);
			gcd = getGcd(gcd, a[r]);
			(ans += max * gcd % P) %= P;
		}
	}
	cout << ans << endl;
	cout.flush();
	return 0;
}

