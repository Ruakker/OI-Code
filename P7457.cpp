/*
	Author: Ruakker
	Date: 2021-05-31 14:56:02
	LastEditTime: 2021-06-02 13:30:51
*/
// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO {
static const int BUFSIZE = (1 << 20) + 1;
static char Ibuf[BUFSIZE], *I1 = Ibuf, *I2 = Ibuf, Obuf[BUFSIZE], *O1 = Obuf, *O2 = O1 + BUFSIZE - 1;
static int ST[55], Top;
inline void flush() { fwrite(Obuf, 1, O1 - Obuf, stdout), O1 = Obuf; }
struct flusher {
	~flusher() { flush(); }
} IO;
inline char getch() { return I1 == I2 && (I2 = (I1 = Ibuf) + fread(Ibuf, 1, BUFSIZE, stdin), I1 == I2) ? EOF : *I1++; }
inline void putch(char Ch) { *O1++ = Ch, (O1 == O2) ? flush() : void(); }
inline int getstr(char* S) {
	char Ch = getch();
	int cnt = 0;
	for (; !isgraph(Ch); Ch = getch())
		;
	for (; isgraph(Ch); Ch = getch())
		S[cnt++] = Ch;
	S[cnt] = 0;
	return cnt;
}
inline void putstr(const char* S) {
	int Len = strlen(S);
	for (int i = 0; i < Len; ++i)
		putch(S[i]);
}
template <typename Var>
inline Var read() {
	register Var Res = 0, W = 1;
	register char Ch = getch();
	for (; Ch < '0' || Ch > '9'; Ch = getch())
		if (Ch == '-') W = -1;
	for (; Ch <= '9' && Ch >= '0'; Ch = getch())
		Res = (Res << 3) + (Res << 1) + (Ch ^ 48);
	return Res * W;
}
inline double readDB() {
	register double ResB = 0, Cnt = 1;
	register char Ch = getch();
	register int ResA = 0, W = 1;
	if (Ch != '.') {
		for (; Ch < '0' || Ch > '9'; Ch = getch())
			if (Ch == '-') W = -1;
		for (; Ch <= '9' && Ch >= '0'; Ch = getch())
			ResA = (ResA << 3) + (ResA << 1) + (Ch ^ 48);
		if (Ch != '.') return ResA * W;
	}
	Ch = getch();
	for (; Ch <= '9' && Ch >= '0'; Ch = getch())
		ResB += (Ch ^ 48) * (Cnt *= 0.1);
	return (ResA + ResB) * W;
}
template <typename Var>
inline void write(register Var Num, const char Ch = '\0') {
	if (!Num) putch('0');
	if (Num < 0) putch('-'), Num = -Num;
	for (; Num; ST[++Top] = Num % 10 + '0', Num /= 10)
		;
	for (; Top; putch(ST[Top--]))
		;
	if (Ch != '\0') putch(Ch);
}
} // namespace FastIO
using namespace FastIO;
// 1. divide with time
// 2. UFS the edge
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N = 1e6 + 5;
#define int long long
std::map<pii, pii> tmp;
pii query[N], bas[N];
int n, q, ans[N];

namespace UnionFindSet {
struct UFS {
	int sz, fa;
} p[N];
std::stack<pii> st;
int getfa(int x) {
	return (p[x].fa == x) ? x : getfa(p[x].fa);
}
inline void merge(int x, int y) {
	// cerr << "merge:" << x << ' ' << y << endl;
	x = getfa(x), y = getfa(y);
	if (x == y) return;
	if (p[x].fa > p[y].fa) std::swap(x, y);
	p[x].fa = y;
	p[y].sz += p[x].sz;
	st.push(mp(x, y));
}
inline void revoke(int x, int y) {
	p[x].fa = x, p[y].sz -= p[x].sz;
}
inline bool chk(int x, int y) {
	if (!x || !y) return 0;
	// cerr << "Check: " << x << " & " << y << " Result: " << (getfa(x) == getfa(y)) << endl;
	return getfa(x) == getfa(y);
}
inline void init(int n) {
	for (int i = 0; i <= n; ++i)
		p[i] = (UFS){1, i};
}
} // namespace UnionFindSet
using namespace UnionFindSet;

namespace SegmentTree {
#define lson (1 << k)
#define rson (1 << k | 1)
std::vector<pair<pii, int> > segt[N << 2];
void modify(int L, int R, int l, int r, pii edge, int level, int k) {
	if (L <= l && r <= R)
		return segt[k].pb(mp(edge, level)), void();
	//, cerr << "Edge-add: " << edge.fi << ' ' << edge.se << " Level: " << level << endl, void();
	int mid = l + r >> 1;
	if (L <= mid) modify(L, R, l, mid, edge, level, lson);
	if (mid < R) modify(L, R, mid + 1, r, edge, level, rson);
}
void dfs(int l, int r, int level, int k) {
	int top = st.size();
	for (int i = 0; i < segt[k].size(); ++i) {
		pair<pii, int> cur = segt[k][i];
		if (cur.se <= level) merge(cur.fi.fi, cur.fi.se);
	}
	if (l >= r) {
		// cerr << "Now at:" << l << " Level: " << level << endl;
		if (ans[l] == -1 && chk(query[l].fi, query[l].se))
			ans[l] = level;
	} else {
		int mid = l + r >> 1;
		dfs(l, mid, level, lson), dfs(mid + 1, r, level, rson);
	}
	for (; top < st.size(); st.pop())
		revoke(st.top().fi, st.top().se);
	// cerr << "revoke:" << st.top().fi << ' ' << st.top().se << endl;
}
#undef lson
#undef rson
} // namespace SegmentTree
using namespace SegmentTree;

signed main() {
	n = read<int>(), q = read<int>();
	for (int i = 1; i <= q; ++i) {
		int opt = read<int>(), x = read<int>() + 1, y = read<int>() + 1;
		if (x > y) std::swap(x, y);
		if (opt == 2) {
			query[i] = mp(x, y);
			continue;
		}
		if (tmp.find(mp(x, y)) == tmp.end()) {
			tmp[mp(x, y)] = mp(read<int>(), i);
		} else {
			modify(tmp[mp(x, y)].se + 1, i, 1, q, mp(x, y), tmp[mp(x, y)].fi, 1);
			tmp.erase(mp(x, y));
		}
	}
	for (std::map<pii, pii>::iterator i = tmp.begin(); i != tmp.end(); i++)
		modify((i->se).se + 1, q, 1, q, i->fi, (i->se).fi, 1);
	init(n);
	memset(ans, -1, sizeof ans);
	for (int i = 0; i <= 10; ++i) {
		// init(n);
		dfs(1, q, i, 1);
	}
	for (int i = 1; i <= q; ++i)
		if (query[i].fi && query[i].se) write(ans[i], '\n');
	// for (int i = 1; i <= q; ++i)
	// cerr << ans[i] << ' ';
	// cerr << endl;
	return 0;
}