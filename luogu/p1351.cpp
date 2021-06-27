/**
 * File              : link-correct.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/22
 * Last Modified Date: 2021/08/22
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
#define int long long
constexpr int N = 2e5 + 5, P = 10007;
std::vector<int> g[N];
std::bitset<N> vis;
int n, a[N], ans1 = -inf, ans2 = 0;
bool MEMED;
signed main() {
	fre(link);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int u = 1; u <= n; ++u) {
		int max1 = -inf, max2 = -inf, sum1 = 0, sum2 = 0;
		for (auto v : g[u]) {
			sum1 += a[v], sum2 += a[v] * a[v];
			if (a[v] > max1) {
				max2 = max1;
				max1 = a[v];
			} else {
				if (a[v] <= max1 && a[v] > max2)
					max2 = a[v];
			}
		}
		ans1 = std::max(ans1, max1 * max2);
		(ans2 += sum1 * sum1 - sum2) %= P;
	}
	cout << ans1 << ' ' << ans2 << endl;
	cout.flush();
	return 0;
}
