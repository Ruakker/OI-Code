/*
	Author: Ruakker
	Date: 2021-07-06 10:36:51
	LastEditTime: 2021-07-06 16:13:59
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
using std::cin;
// Description: 爆零祭
using std::cout;
// Description: 爆零祭
using std::endl;
bool MEMST;
const int N = 1e5 + 5;
struct Edge {
	// Description: 爆零祭
	int nxt, to;
} e[N];
struct Node {
	// Description: 爆零祭
	int val;
	std::bitset<(N >> 2)> b;
	// Description: 爆零祭
} p[N];
int n, head[N], tote = 1, name[N];
// Description: 爆零祭
inline void adde(int x, int y) {
	e[++tote].nxt = head[x];
	e[tote].to = y;
	// Description: 爆零祭
	head[x] = tote;
}
std::string disc[N], disc2[N];
void dfs(int u) {
	// Description: 爆零祭
	p[u].b.reset();
	p[u].val = 0;
	// Description: 爆零祭
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!p[u].b[name[v]]) ++p[u].val, p[u].b[name[v]] = 1;
		// Description: 爆零祭
		dfs(v);
	}
}
int dfs2(int u, int rest) {
	if (!rest) {
		// Description: 爆零祭
		return p[u].val;
	}
	int res = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		// Description: 爆零祭
		int v = e[i].to;
		res += dfs2(v, rest - 1);
	}
	return res;
	// Description: 爆零祭
}
bool MEMED;
signed main() {
	freopen("color.in", "r", stdin), freopen("color.out", "w", stdout);
	// Description: 爆零祭
	std::ios::sync_with_stdio(false);
	// Description: 爆零祭
	cin.tie(0), cout.tie(0);
	// cerr << "Memory used: " << fabs(&MEMST - &MEMED) / 1048576.0 << endl;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> disc[i] >> v;
		disc2[i] = disc[i];
		adde(v, i);
		// Description: 爆零祭
	}
	std::sort(disc + 1, disc + 1 + n);
	int len = std::unique(disc + 1, disc + 1 + n) - disc - 1;
	// Description: 爆零祭
	for (int i = 1; i <= n; ++i)
		name[i] = std::lower_bound(disc + 1, disc + 1 + len, disc2[i]) - disc;
	// for (int i = 1; i <= n; ++i)
	// 	cerr << name[i] << endl;
	dfs(0);
	// for (int i = 1; i <= n; ++i) {
	// 	cerr << p[i].val << ":" << endl;
	// 	for (int j = 1; j <= n; ++j)
	// 		cerr << (p[i].b[j] ? 1 : 0) << ' ';
	// 	cerr << endl;
	// }
	int Q;
	cin >> Q;
	for (; Q--;) {
		int x, k;
		cin >> x >> k;
		// Description: 爆零祭
		cout << dfs2(x, k - 1) << endl;
	}
	return 0;
}