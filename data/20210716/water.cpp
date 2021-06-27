/*
    Author: Ruakker
    Date: 2021-07-16 07:34:34
	LastEditTime: 2021-07-16 14:35:50
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const int N = 305;
const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};

struct Node {
	int x, y, val;
	inline bool operator<(const Node &x) const { return val < x.val; }
	inline bool operator>(const Node &x) const { return val > x.val; }
	inline bool operator<=(const Node &x) const { return val <= x.val; }
	inline bool operator>=(const Node &x) const { return val >= x.val; }
	inline bool operator==(const Node &x) const { return val == x.val; }
	inline bool operator!=(const Node &x) const { return val != x.val; }
};
int n, m;
int a[N][N], ans[N][N];
bool vis[N][N];
std::priority_queue<Node, std::vector<Node>, std::greater<Node> > Q;
// #define DEBUG
signed main() {
	freopen("water.in", "r", stdin), freopen("water.out", "w", stdout);
	FastIO;

	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		Q.push((Node){i, 0, 0}), Q.push((Node){i, m + 1, 0});
	for (int i = 1; i <= m; ++i)
		Q.push((Node){0, i, 0}), Q.push((Node){n + 1, i, 0});
	for (; !Q.empty();) {
		Node cur = Q.top(); // Current top node (lowest)
		Q.pop();
		ans[cur.x][cur.y] = cur.val;
		for (int i = 1; i <= 4; ++i) {
			int tx = cur.x + dx[i], ty = cur.y + dy[i];
			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (vis[tx][ty]) continue;
			vis[tx][ty] = 1;
			Q.push((Node){tx, ty, std::max(cur.val, a[tx][ty])});
		}
	}

#ifdef DEBUG
	for (int i = 1; i <= n; ++i, cerr << endl)
		for (int j = 1; j <= n; ++j)
			cerr << ans[i][j] << ' ';
#endif
	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= m; ++j)
			cout << ans[i][j] - a[i][j] << ' ';
	return 0;
}
