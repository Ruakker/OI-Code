/**
 * File              : light.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 15:46:17
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
const int N = 2e6 + 5;
int n, k, a[N], ans;
namespace fw {
int t[N];
inline int lowbit(int a) { return a & -a; }
inline void modify(int k) {
	for (; k <= n; k += lowbit(k))
		++t[k];
}
inline int query(int k) {
	int res = 0;
	for (; k >= 1; k -= lowbit(k))
		res += t[k];
	return res;
}
} // namespace fw
bool MEMED;
signed main() {
	fre(light);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	std::string s;
	cin >> s;
	n = s.size();
	cin >> k;
	for (int i = 0; i < n; ++i)
		a[i + 1] = s[i] - '0';
	for (int i = 1; i <= n - k + 1; ++i) {
		a[i] ^= (fw::query(i) - fw::query(i - k)) & 1;
		if (a[i] != 0) fw::modify(i), ++ans, a[i] ^= 1;
	}
	bool flag = 1;
	for (int i = n - k + 2; i <= n; ++i) {
		a[i] ^= (fw::query(i) - fw::query(i - k)) & 1;
		if (a[i]) flag = 0;
	}
	if (!flag)
		cout << "so hard" << endl;
	else
		cout << ans << endl;
#ifdef DEBUG
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << ' ';
	cerr << endl;
	cerr << "Ans: " << ans << endl;
#endif
	cout.flush();
	return 0;
}

