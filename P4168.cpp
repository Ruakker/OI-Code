/*
	Author: Ruakker
	Date: 2021-05-26 14:55:47
	LastEditTime: 2021-05-30 20:29:56
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
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
#define pii pair<int, int>
#define mp make_pair
bool STARTMEM;
const int N = 5e4 + 5;
int n, m, prefix[N], len;
struct BlockArray {
	int val, l, r, d[N];
} bar[250]; //每个块中各种花种的个数，bar[250][0].val 存当前块的众数
struct Node {
	int
} inline void Disc() {
	int disc[N];
	memcpy(disc, a, sizeof a);
	std::sort(disc + 1, disc + 1 + n);
	int k = std::unique(disc + 1, disc + 1 + n) - disc;
	for (int i = 1; i <= n; ++i)
		a[i].first = std::lower_bound(disc + 1, disc + 1 + k, a[i].second) - disc;
}

/* Block-Array Begin */
inline Build() {
	inline void add(int l, int r, int num) {
		if (a[l].se == a[r].se) {
			for (int i = l; i <= r; ++i)
				a[i].fi += num;
			sum[a[l].se].fi += (r - l + 1) * num;
			return;
		}
		for (int i = l; a[i].se == a[l].se; ++i)
			a[i].fi += num, sum[a[i].se].fi += num;
		for (int i = a[l].se + 1; i < a[r].se; ++i)
			sum[i].se += num, sum[i].fi += len * num;
		for (int i = r; a[i].se == a[r].se; --i)
			a[i].fi += num, sum[a[i].se].fi += num;
	}
	/* Block-Array End */

	bool ENDMEM;
	signed main() {
		cerr << fabs(&STARTMEM - &ENDMEM) / 1048576.0 << endl;
		n = read<int>(), m = read<int>();
		len = sqrt(n);
		for (int i = 1; i <= n; ++i)
			prefix[i] = (a[i].second = read<int>()) + prefix[i - 1];
		Disc();
		Build();
		return 0;
	}
