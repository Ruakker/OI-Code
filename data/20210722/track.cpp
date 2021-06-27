/*
	Author: Ruakker
	Date: 2021-07-22 07:33:18
	LastEditTime: 2021-07-22 08:25:12
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fre(fileName) freopen(#fileName ".in", "r", stdin), freopen(#fileName ".out", "w", stdout)
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
bool MEMST;

const int N = 1005, W = 1e8 + 5, P = 1e9 + 7;
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return 1ll * a / gcd(a, b) * b % P; }

int head[N], tote = 1;
struct Edge {
	int nxt, to, val;
} e[N << 1];
inline void adde(int x, int y, int z) {
	e[++tote] = {head[x], y, z};
	head[x] = tote;
}

std::bitset<W> isPrime;
std::vector<int> primes;
void getPrime(int m) {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i <= m; i++) {
		if (isPrime[i]) {
			for (int j = i << 1; j <= m; j += i)
				isPrime[j] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)
		if (isPrime[i]) primes.emplace_back(i);
}

bool MEMED;
signed main() {
	fre(track);
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << '\n';
#endif

	int T;
	for (cin >> T; T--;) {
		// init();
	}

	cout.flush();
	return 0;
}
