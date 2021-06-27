/**
 * File              : CF1566A.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-12 22:33:01
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
		int cnt0 = 0, cnt2 = 0, cnt1 = 0;
		std::string s;
		cin >> s;
		s = s + 'k';
		for (int i = 1; i <= s.size(); ++i) {
			if (s[i] != s[i - 1] && s[i - 1] == '0') ++cnt0;
		}
		cout << std::min(cnt0, 2) << endl;
	}
	cout.flush();
	return 0;
}
