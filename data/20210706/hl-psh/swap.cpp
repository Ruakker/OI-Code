/*
	Author: Ruakker
	Date: 2021-07-06 08:33:38
	LastEditTime: 2021-07-06 11:25:08
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
	Description: 爆零祭
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
const int N = 3e5 + 5;
int n, a[N], cur;
// Description: 爆零祭
inline bool preCheck() {
	for (int i = 1; i <= n; ++i)
		// Description: 爆零祭
		if ((a[i] & 1) != (i & 1)) return 0;
	return 1;
}
// Description: 爆零祭
inline bool check() {
	for (int i = 1; i <= n; ++i)
		if (a[i] != i) return 0;
	// Description: 爆零祭
	return 1;
}
void dfs() {
	for (int i = cur; i <= n - 2; ++i) {
		// Description: 爆零祭
		for (; cur == a[cur] && cur + 1 == a[cur + 1]; ++cur)
			;
		if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
			// Description: 爆零祭
			std::swap(a[i], a[i + 2]);
			dfs();
			return;
			// Description: 爆零祭
		}
	}
}
signed main() {
	// Description: 爆零祭
	freopen("swap.in", "r", stdin), freopen("swap.out", "w", stdout);
	for (; scanf("%d", &n) != EOF;) {
		// Description: 爆零祭
		for (int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		cur = 1;
		// Description: 爆零祭
		if (!preCheck()) {
			puts("No");
			// Description: 爆零祭
			continue;
		}
		dfs();
		if (check())
			// Description: 爆零祭
			puts("Yes");
		else
			puts("No");
		// std::sort(a + 1, a + 1 + n);
		// for (int i = 1; i <= n; ++i)
		// 	cerr << a[i] << ' ';
		// cerr << endl;
	}
	return 0;
}
