/**
 * File              : P4168.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-08-26 14:02:06
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
using std::make_pair;
bool MEMST;
#define int long long
constexpr int N = 4e6 + 5, M = sqrt(4e6) + 5;
struct Block {
	Block(int l, int r) { begin = l, end = r, size = r - l + 1; }
	Block() {}
	int begin, end, size;
	int prefix[M]; // b[i].prefix[j]: the count of value j before and on the block i
} b[M];
int n, q, m, len, bel[N], a[N], cnt[N];
std::pair<int, int> table[M][M]; //table[i][j]: the crowd of value from block i to j; first contain the value (a[k]), and the second contain the count.
int disc[N], original[N];
inline void init() {
	m = sqrt(n);
	for (int i = 1; i <= m; ++i)
		b[i] = Block(n / m * (i - 1) + 1, n / m * i);
	b[m].end = n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= len; ++j)
			b[i].prefix[j] = b[i - 1].prefix[j];
		for (int j = b[i].begin; j <= b[i].end; ++j)
			bel[j] = i, ++b[i].prefix[a[j]];
	}
	for (int i = 1; i <= m; ++i) {
		memset(cnt, 0, sizeof cnt);
		for (int j = i; j <= m; ++j) {
			std::pair<int, int> res = make_pair(1, -inf);
			for (int k = b[j].begin; k <= b[j].end; ++k) {
				++cnt[a[k]];
				if (res.second < cnt[a[k]] || (res.second == cnt[a[k]] && res.first > a[k]))
					res.second = cnt[a[k]], res.first = a[k];
			}
			table[i][j] = res;
		}
	}
}
inline void decrypt(int &l, int &r, int lastAns) {
	l = (l + lastAns - 1) % n + 1, r = (r + lastAns - 1) % n + 1;
	if (l > r) std::swap(l, r);
}
inline int query(int l, int r) {
	// memset(cnt, 0, sizeof cnt);
	if (bel[r] - bel[l] <= 2) {
		int res = 0, max = -inf;
		for (int i = l; i <= r; ++i)
			cnt[a[i]] = 0;
		for (int i = l; i <= r; ++i) {
			++cnt[a[i]];
			if (max < cnt[a[i]] || (max == cnt[a[i]] && a[i] < res))
				max = cnt[a[i]], res = a[i];
		}
		return disc[res];
	}
	int max = 0, L = bel[l] + 1, R = bel[r] - 1;
	int res = table[L][R].first;
	// cnt[res] = b[R].prefix[res] - b[L - 1].prefix[res];
	cnt[res] = 0;
	for (int i = l; i <= b[bel[l]].end; ++i)
		cnt[a[i]] = b[R].prefix[a[i]] - b[L - 1].prefix[a[i]];
	for (int i = b[bel[r]].begin; i <= r; ++i)
		cnt[a[i]] = b[R].prefix[a[i]] - b[L - 1].prefix[a[i]];
	for (int i = l; i <= b[bel[l]].end; ++i) {
		++cnt[a[i]];
		if (max < cnt[a[i]] || (max == cnt[a[i]] && a[i] < res)) max = cnt[a[i]], res = a[i];
	}
	for (int i = b[bel[r]].begin; i <= r; ++i) {
		++cnt[a[i]];
		if (max < cnt[a[i]] || (max == cnt[a[i]] && a[i] < res)) max = cnt[a[i]], res = a[i];
	}
	if (max < table[L][R].second + cnt[table[L][R].first] || (max == table[L][R].second + cnt[table[L][R].first] && table[L][R].first < res))
		return disc[table[L][R].first];
	return disc[res];
}
bool MEMED;
signed main() {
	// fre(P4168_1);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		disc[i] = original[i] = a[i];
	}
	std::sort(disc + 1, disc + 1 + n);
	len = std::unique(disc + 1, disc + 1 + n) - disc - 1;
	for (int i = 1; i <= n; ++i)
		a[i] = std::lower_bound(disc + 1, disc + 1 + len, a[i]) - disc;
#ifdef DEBUG
	cerr << ">>> After Discretization, the max number is " << len << endl
	     << ">>> ";
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << ' ';
	cerr << endl
	     << ">>> The Disc[]: " << endl
	     << ">>> ";
	for (int i = 1; i <= len; ++i)
		cerr << disc[i] << ' ';
	cerr << endl;
#endif
	init();
	int lastAns = 0;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		decrypt(l, r, lastAns);
		lastAns = query(l, r);
		cout << lastAns << endl;
	}
	cout.flush();
	return 0;
}
