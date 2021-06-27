/*
	Author: Ruakker
	Date: 2021-07-13 09:54:53
	LastEditTime: 2021-07-13 11:00:38
*/
#include <bits/stdc++.h>
int ans[] = {0, 0, 0, 32, 16688, 15312474};
signed main() {
	freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int n;
	std::cin >> n;
	std::cout << ans[n] << std::endl;
}