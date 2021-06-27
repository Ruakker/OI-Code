/*
	Author: Ruakker
	Date: 2021-07-22 13:48:43
	LastEditTime: 2021-07-22 16:14:36
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
bool MEMST;

const int N = 105;
bool f[N][N][40];
int dis[N][N];
int n, m;

bool MEMED;
signed main() {
	fre(run);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	memset(dis, inf, sizeof dis);
	cin >> n >> m;
	if (n == 1) {
		cout << "0\n";
		cout.flush();
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		f[u][v][0] = 1;
	}

	for (int t = 1; t <= 30; ++t)
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					f[i][j][t] |= f[i][k][t - 1] & f[k][j][t - 1];

	for (int t = 0; t <= 30; ++t)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (f[i][j][t]) dis[i][j] = 1;

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

	cout << dis[1][n] << '\n';

	cout.flush();
	return 0;
}