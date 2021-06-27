/**
 * File              : P3806.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/21
 * Last Modified Date: 2021/08/21
 */
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define endl '\n'
using std::cerr;
using std::cin;
using std::cout;
constexpr int N = 1e4 + 5;
int n, m, sum, root;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
struct Edge {
	int nxt, to, val;
} e[N << 1];
struct Info {
	int Size, maxSonSize;
} p[N];
int head[N], tote = 1;
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
std::bitset<N> vis;
void calcSize(int u, int pre) {
	p[u].maxSonSize = 0, p[u].Size = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == pre || vis[v]) continue;
		calcSize(v, u);
		p[u].maxSonSize = max(p[u].maxSonSize, p[v].Size);
		p[u].Size += p[v].Size;
	}
	p[u].maxSonSize = max(p[u].maxSonSize, sum - p[u].Size);
	if (p[u].maxSonSize < p[root].maxSonSize) root = u;
}
void dfz(int u, int pre) {
}
signed main() {
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	vis.reset();
	cin >> n >> m;
	sum = n, root = 0;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adde(u, v, w), adde(v, u, w);
	}
	calcSize(1, -1);
	calcSize(root, -1);
}
