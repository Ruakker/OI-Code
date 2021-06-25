/*
	Author: Ruakker
	Date: 2021-05-12 20:40:29
	LastEditTime: 2021-06-04 09:29:26
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
const int BUFSIZE = (1 << 21) + 1;
static char ibuf[BUFSIZE], *i1 = ibuf, *i2 = ibuf, obuf[BUFSIZE], *o1 = obuf, *o2 = o1 + BUFSIZE - 1;
inline void flush() { fwrite(obuf, 1, o1 - obuf, stdout), o1 = obuf; }
#define getchar() i1 == i2 && (i2 = (i1 = ibuf) + fread(ibuf, 1, BUFSIZE, stdin), i1 == i2) ? EOF : *i1++
#define putchar(x) *o1++ = x, (o1 == o2) ? flush() : void();
struct flusher {
	~flusher() { flush(); }
} io;
template <typename Val>
inline Val read() {
	Val res = 0, w = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') w = -1;
	for (; isdigit(ch); ch = getchar())
		res = (res << 3) + (res << 1) + (ch ^ 48);
	return res * w;
}
inline void readstr(char* s) {
	char ch = getchar();
	for (; !isgraph(ch); ch = getchar())
		;
	for (int cnt = -1; isgraph(ch); ch = getchar())
		s[++cnt] = ch;
}
template <typename Val>
void write(Val num) {
	if (num < 0) num = -num, putchar('-');
	if (num > 9) write(num / 10);
	putchar(num % 10 + '0');
}
template <typename Val>
inline void writeln(Val num) { write(num), putchar('\n'); }
const int N = 1e5 + 5;
struct Ruakker {
	int sz, val, weight, son[2];
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
	writeln<int>(tr[x].sz + 1);
	rt = merge(x, y);
}
void getnum(int u) {
	writeln<int>(tr[kth(rt, u)].val);
}
void getpre(int u) {
	split(rt, u - 1, x, y);
	writeln<int>(tr[kth(x, tr[x].sz)].val);
	rt = merge(x, y);
}
void getsuc(int u) {
	split(rt, u, x, y);
	writeln<int>(tr[kth(y, 1)].val);
	rt = merge(x, y);
}
signed main() {
	srand(time(0));
	for (int T = read<int>(); T--;) {
		int opt = read<int>(), u = read<int>();
		if (opt == 1) ins(u);
		if (opt == 2) del(u);
		if (opt == 3) getrank(u);
		if (opt == 4) getnum(u);
		if (opt == 5) getpre(u);
		if (opt == 6) getsuc(u);
	}
	return 0;
}