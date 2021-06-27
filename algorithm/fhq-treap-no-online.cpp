/**
 * @Date:   2021-May-12
 * @Email:  i@ruakker.cn
 * @Filename: Fhq-Treap-No-Online.cpp
 * @Last modified time: 2021-Jun-01
 */

/*
	Author: Ruakker
	Date: 2021-05-12 20:40:29
	LastEditTime: 2021-05-12 22:22:44
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
ll read() {
	ll x = 0, w = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') w = -1;
	for (; isdigit(ch); ch = getchar())
		x = x * 10 + (ch - '0');
	return x * w;
}
inline void write(ll x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void writeln(ll x) { write(x), putchar('\n'); }
const int N = 1e5 + 5;
struct Ruakker {
	int sz, val, weight, son[2], fa;
} tr[N];
int tot, rt, x, y, z;
void calcsize(int x) {
	tr[x].sz = 1 + tr[tr[x].son[0]].sz + tr[tr[x].son[1]].sz;
}
int newnode(int val) {
	tr[++tot].sz = 1;
	tr[tot].val = val;
	tr[tot].son[0] = tr[tot].son[1] = 0;
	tr[tot].weight = rand();
	return tot;
}
int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (tr[x].weight < tr[y].weight) {
		tr[x].son[1] = merge(tr[x].son[1], y);
		calcsize(x);
		return x;
	} else {
		tr[y].son[0] = merge(x, tr[y].son[0]);
		calcsize(y);
		return y;
	}
}
void split(int cur, int val, int& x, int& y) {
	if (!cur)
		x = y = 0;
	else {
		if (tr[cur].val <= val)
			x = cur, split(tr[cur].son[1], val, tr[cur].son[1], y);
		else
			y = cur, split(tr[cur].son[0], val, x, tr[cur].son[0]);
		calcsize(cur);
	}
}
int kth(int cur, int k) {
	while (1) {
		if (k <= tr[tr[cur].son[0]].sz)
			cur = tr[cur].son[0];
		else {
			if (k == tr[tr[cur].son[0]].sz + 1)
				return cur;
			else {
				k -= tr[tr[cur].son[0]].sz + 1;
				cur = tr[cur].son[1];
			}
		}
	}
}
void ins(int u) {
	split(rt, u, x, y);
	rt = merge(merge(x, newnode(u)), y);
}
void del(int u) {
	split(rt, u, x, z);
	split(x, u - 1, x, y);
	y = merge(tr[y].son[0], tr[y].son[1]);
	rt = merge(merge(x, y), z);
}
void getrank(int u) {
	split(rt, u - 1, x, y);
	writeln(tr[x].sz + 1);
	rt = merge(x, y);
}
void getnum(int u) {
	writeln(tr[kth(rt, u)].val);
}
void getpre(int u) {
	split(rt, u - 1, x, y);
	writeln(tr[kth(x, tr[x].sz)].val);
	rt = merge(x, y);
}
void getsuc(int u) {
	split(rt, u, x, y);
	writeln(tr[kth(y, 1)].val);
	rt = merge(x, y);
}
signed main() {
	srand(time(0));
	for (int T = read(); T--;) {
		int opt = read(), u = read();
		if (opt == 1) ins(u);
		if (opt == 2) del(u);
		if (opt == 3) getrank(u);
		if (opt == 4) getnum(u);
		if (opt == 5) getpre(u);
		if (opt == 6) getsuc(u);
	}
	return 0;
}
