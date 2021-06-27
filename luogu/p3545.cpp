/*
	Author: Ruakker
	Date: 2021-07-16 19:01:03
	LastEditTime: 2021-07-16 19:44:07
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(0)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define int long long
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;

const int N = 5e5 + 5;
int n, a[N], b[N], rest, ans;
std::priority_queue<pii, std::vector<pii>, std::less<pii> > Q;
std::bitset<N> vis;

signed main() {
	// freopen("4.in", "r", stdin), freopen("4.ans", "w", stdout);
	FastIO;
	vis.reset();
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		rest += a[i];
		if (rest >= b[i])
			rest -= b[i], Q.push(make_pair(b[i], i)), vis.set(i), ++ans;
		else if (!Q.empty() && Q.top().first > b[i])
			rest += Q.top().first - b[i], vis.reset(Q.top().second), vis.set(i), Q.pop(), Q.push(make_pair(b[i], i));
	}
	cerr << "Rest Goods: " << rest << endl;
	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
		if (vis[i]) cout << i << ' ';
	cout << endl;
	return 0;
}
