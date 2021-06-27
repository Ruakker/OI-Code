/**
 * File              : CF1566D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 23:13:50
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
const int N = 500;
int a[N];
std::pair<int, int> b[N];
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	int T;
	cin >> T;
	for (; T--;) {
		int n, m, ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> b[i].first;
			b[i].second = m - i + 1;
		}
		std::sort(b + 1, b + 1 + m);
		for (int i = 1; i <= m; ++i)
			for (int j = i + 1; j <= m; ++j) {
				if (b[i].second > b[j].second) ++ans;
			}
		cout << ans << endl;
	}
	cout.flush();
	return 0;
}

