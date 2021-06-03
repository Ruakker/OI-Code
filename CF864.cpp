/*
	Author: Ruakker
	Date: 2021-06-02 20:07:40
	LastEditTime: 2021-06-02 21:12:42
*/
#include <bits/stdc++.h>
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
using std::endl;
using std::pair;
const int N = 3001, M = 4e5 + 7;
int n, m, k;
int ans[M] = {};
std::vector<pair<int, int> > q[N][N];
std::vector<int> a[N];
int qq[N], top = 0, tmp = 0;
bool vis1[N], vis2[N];
int root = 0, cnt[N];

void dfs(int x) {
	qq[++top] = x;
	if (!tmp) {
		for (int i = 0; i < q[root][x].size(); i++) {
			int kk = q[root][x][i].first;
			int id = q[root][x][i].second;
			if (kk <= top) ans[id] = qq[kk];
		}
	}
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (vis2[y]) continue;
		if (!vis1[y])
			vis1[y] = 1, dfs(y);
		else
			++tmp, cnt[y]++;
	}
	--top, tmp -= cnt[x], cnt[x] = 0, vis2[x] = 1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x=read<int>(), y=read<int>();
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		std::sort(a[i].begin(), a[i].end());
	for (int i = 1; i <= k; i++) {
		int x = read<int>(), y = read<int>(), z = read<int>();
		q[x][y].push_back(std::make_pair(z, i));
		ans[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		tmp = 0, root = i, top = 0;
		for (int j = 1; j <= n; j++)
			vis1[j] = vis2[j] = 0;
		dfs(i);
	}
	for (int i = 1; i <= k; i++)
		write(ans[i], '\n');
	return 0;
}