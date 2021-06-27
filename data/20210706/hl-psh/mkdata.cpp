/*
	Author: Ruakker
	Date: 2021-07-06 08:33:38
	LastEditTime: 2021-07-06 10:04:46
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
const int N = 3e5 + 5;
int n, a[N], cnt;
void dfs(int k) {
	if (!k) return;
	std::vector<int> ans;
	for (int i = 1; i <= n - 2; ++i)
		if (a[i] < a[i + 1] && a[i + 1] < a[i + 2])
			ans.push_back(i);
	if (ans.empty()) return;
	std::random_shuffle(ans.begin(), ans.end());
	std::swap(a[ans[0]], a[ans[0] + 2]);
	++cnt;
	dfs(k - 1);
}
signed main() {
	// freopen("swap.in", "w", stdout);
	srand(time(0));
	int k;
	scanf("%d%d", &n, &k);
	// for (; scanf("%d%d", &n, &k) != EOF;) {
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	dfs(k);
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	puts("");
	printf("Swap: %d\n", cnt);
	// }
	return 0;
}
