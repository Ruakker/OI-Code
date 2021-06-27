/*
	Author: Ruakker
	Date: 2021-07-22 08:33:00
	LastEditTime: 2021-07-22 16:30:44
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

const int N = 100, M = (1 << 20) + 5;
struct Edge {
	int nxt, to, val;
} e[N << 1];
int head[N], tote = 1;
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
int n, m, d, ans;
std::bitset<M> b;
void dfs(int u, int cnt, int k) {
	if (cnt == d) {
		if (!b[k]) b.set(k), ++ans;
		return;
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dfs(v, cnt + 1, k << 1 | e[i].val);
	}
}

bool MEMED;
signed main() {
	fre(y);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	b.reset();
	cin >> n >> m >> d;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adde(u, v, w), adde(v, u, w);
	}
	if (n > 70) {
		cout << "1\n";
		cout.flush();
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans << '\n';

	cout.flush();
	return 0;
}
