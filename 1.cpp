/*
    Author: Ruakker
    Date: 【数据删除】
	LastEditTime: 2021-05-16 20:00:55
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
const int BUFSIZE = (1 << 21) + 1;
static char ibuf[BUFSIZE], *i1 = ibuf, *i2 = ibuf, obuf[BUFSIZE], *o1 = obuf, *o2 = o1 + BUFSIZE - 1;
inline void flush() { fwrite(obuf, 1, o1 - obuf, stdout), o1 = obuf; }
#define getchar( ) i1 == i2 && (i2 = (i1 = ibuf) + fread(ibuf, 1, BUFSIZE, stdin), i1 == i2) ? EOF : *i1++
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
template <typename Val>
void write(Val num) {
	if (num < 0) num = -num, putchar('-');
	if (num > 9) write(num / 10);
	putchar(num % 10 + '0');
}
template <typename Val>
inline void writeln(Val num) { write<Val>(num), putchar('\n'); }
inline void readstr(char* s) {
	char ch = getchar();
	int cnt = 0;
	for (; !isgraph(ch); ch = getchar())
		;
	for (; isgraph(ch); ch = getchar())
		s[cnt++] = ch;
	s[cnt] = 0;
}
inline void writestr(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		putchar(s[i]);
}

signed main() {
1231fsfafs;
	return 0;
}
