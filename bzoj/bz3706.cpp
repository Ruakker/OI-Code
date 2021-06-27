/**
 * File              : BZ3706.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-03 08:34:36
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
const int N = 1e6 + 5;
struct Edge {
	int u, v, col;
} e[N];
int n, m, q, ans, fa[N], dgr[N], cnt[2], size[N];
inline int getfa(int x) { return (fa[x] == x) ? x : fa[x] = getfa(fa[x]); }
inline void merge(int x, int y) {
	int fax = getfa(x), fay = getfa(y);
	if (fax != fay) fa[fax] = fay;
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = (Edge){u, v, w}, merge(u, v);
		if (w)
			++dgr[u], ++dgr[v];
		else
			dgr[u] += 2, dgr[v] += 2;
	}
	for (int i = 1; i <= n; ++i)
		++cnt[dgr[i] & 1];
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, col = e[i].col, fau = getfa(u);
		if (col) {
			if (!size[fau]) ++ans; // 每个连通块都需要一次 ans
			++size[fau];
		}
	}
#ifdef DEBUG
	cerr << ">>> " << cnt[0] << ' ' << cnt[1] << endl;
	for (int i = 1; i <= n; ++i)
		cerr << size[i] << ' ';
	cerr << endl
	     << "ans: " << ans << endl;
#endif
	cin >> q;
	for (int opt, x; q--;) {
		cin >> opt;
		if (opt == 2)
			cout << (cnt[1] ? -1 : ans) << endl;
		else {
			cin >> x;
			++x;
			int u = e[x].u, v = e[x].v, col = e[x].col;
			int fau = getfa(u);
			if (!col) {
				--cnt[dgr[u] & 1], --cnt[dgr[v] & 1], --dgr[u], --dgr[v], ++cnt[dgr[u] & 1], ++cnt[dgr[v] & 1];
				if (!size[fau]) ++ans;
				++size[fau];
			} else {
				--cnt[dgr[u] & 1], --cnt[dgr[v] & 1], ++dgr[u], ++dgr[v], ++cnt[dgr[u] & 1], ++cnt[dgr[v] & 1];
				--size[fau];
				if (!size[fau]) --ans;
			}
			e[x].col ^= 1;
		}
	}
	cout.flush();
	return 0;
}

