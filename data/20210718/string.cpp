/*
	Author: Ruakker
	Date: 2021-07-18 14:47:27
	LastEditTime: 2021-07-18 14:53:21
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

const int N = 3e6 + 5;
char a[N], b[N];
int n, ans, f[N], tot;

bool MEMED;
signed main() {
	fre(string);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif

	cin >> n >> (a + 1) >> (b + 1);
	if (!strcmp(a + 1, b + 1)) {
		cout << 0 << endl;
		return 0;
	}
	int x = 0;
	for (int j = n, i = n; j >= 1; j--) {
		i = std::min(i, j);
		if (i <= j && a[i] != b[j]) {
			for (; i >= 1 && a[i] != b[j]; --i)
				;
			if (!i) {
				cout << "-1" << endl;
				return 0;
			}
			++x, ++f[i + x];
			ans = std::max(ans, ++tot);
		}
		tot -= f[j + x];
		f[j + x] = 0;
	}
	cout << ans << endl;
	return 0;
}