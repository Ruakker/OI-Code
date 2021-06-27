/**
 * File              : CF1566C.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 22:54:47
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

bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	int T;
	cin >> T;
	for (; T--;) {
		int n, ans = 0;
		cin >> n;
		std::string s1, s2;
		cin >> s1;
		cin >> s2;
		s1 = s1 + 'k';
		s2 = s2 + 'k';
		for (int i = 0; i < n; ++i) {
			if ((s1[i] == '0' && s2[i] == '1') || (s1[i] == '1' && s2[i] == '0')) {
				ans += 2;
				continue;
			}
			if ((s1[i + 1] == '1' && s2[i + 1] == '1') && (s1[i] == '0' && s2[i] == '0')) {
				ans += 2;
				++i;
				continue;
			}
			if ((s1[i + 1] == '0' && s2[i + 1] == '0') && (s1[i] == '1' && s2[i] == '1')) {
				ans += 2;
				++i;
				continue;
			}
			if (s1[i] == '0' && s2[i] == '0') {
				ans += 1;
				continue;
			}
		}
		cout << ans << endl;
	}
	cout.flush();
	return 0;
}

