/**
 * File              : path.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-29 15:14:21
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
int n, m;
namespace S1 {
const int N = 1005;
int dis[N][N];
inline void Main() {
	memset(dis, inf, sizeof dis);
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		if (i == n)
			dis[n][1] = dis[1][n] = tmp;
		else
			dis[i][i + 1] = dis[i + 1][i] = tmp;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) std::swap(u, v);
		cout << dis[u][v] << endl;
	}
}
} // namespace S1
namespace S2 {
const int N = 5e5 + 5;
int dis[N], prefix[N], q;
inline void Main() {
	for (int i = 1; i <= n; ++i) {
		cin >> dis[i];
		prefix[i] = prefix[i - 1] + dis[i];
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) std::swap(u, v);
		cout << std::min(prefix[v - 1] - prefix[u - 1], prefix[u - 1] + prefix[n] - prefix[v - 1]) << endl;
	}
}
} // namespace S2
bool MEMED;
signed main() {
	fre(path);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> m;
	if (m)
		S1::Main();
	else
		S2::Main();
	cout.flush();
	return 0;
}

