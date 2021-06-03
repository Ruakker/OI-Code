
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ls now << 1
#define rs now << 1 | 1
const int M = 30005;
using namespace std;
inline int read() {
	char c = getchar();
	int x = 0, w = 1;
	while (c > '9' || c < '0') {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * w;
}
struct Q {
	int opt, l, r;
} q[M];
int n, m, st[M], val[M], tag[M << 2], tree[M << 2], K;
inline void pushup(int now) {
	tree[now] = tree[ls] + tree[rs];
}
void build(int l, int r, int now) {
	tag[now] = -1;
	if (l == r) {
		tree[now] = st[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushup(now);
}
inline void pushdown(int now, int l, int r) {
	if (tag[now] < 0) return;
	tag[ls] = tag[rs] = tag[now];
	tree[ls] = tag[now] * l;
	tree[rs] = tag[now] * r;
	tag[now] = -1;
}
void change(int L, int R, int val, int l, int r, int now) {
	if (l > R || r < L) return;
	if (l >= L && r <= R) {
		tree[now] = val * (r - l + 1);
		tag[now] = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(now, mid - l + 1, r - mid);
	change(L, R, val, l, mid, ls);
	change(L, R, val, mid + 1, r, rs);
	pushup(now);
}
int query(int L, int R, int l, int r, int now) {
	if (l > R || r < L) return 0;
	if (l >= L && r <= R) return tree[now];
	int mid = (l + r) >> 1;
	pushdown(now, mid - l + 1, r - mid);
	int Ans = 0;
	Ans += query(L, R, l, mid, ls);
	Ans += query(L, R, mid + 1, r, rs);
	return Ans;
}
inline int judge(int mid) {
	for (register int i = 1; i <= n; ++i)
		if (val[i] >= mid)
			st[i] = 1;
		else
			st[i] = 0;
	build(1, n, 1);
	for (register int i = 1; i <= m; ++i) {
		int l = q[i].l, r = q[i].r;
		if (q[i].opt == 0) {
			// 升序排列
			int num1 = query(l, r, 1, n, 1);
			change(r - num1 + 1, r, 1, 1, n, 1);
			change(l, r - num1, 0, 1, n, 1);
		} else {
			//  降序排列
			int num1 = query(l, r, 1, n, 1);
			change(l, l + num1 - 1, 1, 1, n, 1);
			change(l + num1, r, 0, 1, n, 1);
		}
	}
	int tmp = query(K, K, 1, n, 1);
	return tmp;
}
int main() {
	freopen("sort2.in", "r", stdin);
	n = read();
	m = read();
	for (register int i = 1; i <= n; ++i)
		val[i] = read();
	for (register int i = 1; i <= m; ++i) {
		q[i].opt = read();
		q[i].l = read();
		q[i].r = read();
	}
	K = read();
	int L = 1, R = n, Ans = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (judge(mid))
			L = mid + 1, Ans = mid;
		else
			R = mid - 1;
	}
	printf("%d\n", Ans);
	return 0;
}
