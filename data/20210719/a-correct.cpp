/*
	Author: Ruakker
	Date: 2021-07-19 17:43:50
	LastEditTime: 2021-07-19 21:24:21
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(0), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool MEMST;

#define int long long
const int N = 1e6 + 5;
std::bitset<N> notPrime;
std::vector<int> primes;
int f[N], g[N], ans[N];

inline void init(int m) {
	notPrime.reset();
	f[1] = 1, notPrime.set(1);
	for (int i = 2; i <= m; ++i) {
		if (!notPrime[i]) primes.emplace_back(i), f[i] = -1;
		for (int j = 0; j < primes.size() && primes[j] * i <= m; ++j) {
			notPrime[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				f[i * primes[j]] = 0;
				break;
			}
			f[i * primes[j]] = -f[i];
		}
	}
	for (int j = 1; j <= m; ++j)
		for (int i = j; i <= m; i += j)
			g[i] += f[j] * j;
	for (int j = 1; j <= m; ++j)
		for (int i = j; i <= m; i += j)
			ans[i] += (j * (j + 1) >> 1) * g[i / j];
	for (int i = 1; i < N; ++i)
		ans[i] *= i;
}

bool MEMED;
signed main() {
	// fre(a);
	std::ifstream fin("a.in");
	std::ofstream fout("a.out");
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	init(1ll * 1e6);
	int T;
	for (fin >> T; T--;) {
		int n;
		fin >> n;
		fout << ans[n] << '\n';
	}
	fout.flush();
	fin.close();
	fout.close();
	return 0;
}
