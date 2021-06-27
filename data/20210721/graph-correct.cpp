/*
	Author: Ruakker
	Date: 2021-07-21 07:36:04
	LastEditTime: 2021-07-21 18:30:52
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

const int N = 3e6 + 5;
struct Edge {
	int nxt, to, val;
} e[N];
struct AnotherEdge {
	int val, node, ans;
	AnotherEdge(int x, int y, int z) { this->val = x, this->node = y, this->ans = z; }
	inline bool operator>(const AnotherEdge &Other) const { return this->ans > Other.ans; }
	inline bool operator<(const AnotherEdge &Other) const { return this->ans < Other.ans; }
	inline bool operator>=(const AnotherEdge &Other) const { return this->ans >= Other.ans; }
	inline bool operator<=(const AnotherEdge &Other) const { return this->ans <= Other.ans; }
	inline bool operator==(const AnotherEdge &Other) const { return this->ans == Other.ans; }
	inline bool operator!=(const AnotherEdge &Other) const { return this->ans != Other.ans; }
};
int tote = 1, head[N];
inline void adde(int x, int y, int z) {
	e[++tote] = (Edge){head[x], y, z};
	head[x] = tote;
}
int n, m, ans;
std::priority_queue<AnotherEdge, std::vector<AnotherEdge>, std::less<AnotherEdge>> Q;

bool MEMED;
signed main() {
	fre(graph);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adde(u, v, w);
	}
	for (int i = 1; i <= n; ++i)
		adde(0, i, 0), Q.emplace(AnotherEdge(0, i, 0));
	for (; !Q.empty();) {
		auto cur = Q.top();
		Q.pop();
		ans = std::max(ans, cur.ans);
		int u = cur.node;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (cur.val < e[i].val) Q.emplace(AnotherEdge(e[i].val, v, cur.ans + 1));
		}
	}
	cout << ans << '\n';

	cout.flush();
	return 0;
}
