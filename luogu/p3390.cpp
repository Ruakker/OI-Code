/**
 * File              : P3390.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021-09-11 14:15:34
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
bool MEMST;
#define int long long
constexpr int N = 200, P = 1e9 + 7;
struct Matrix {
	Matrix() { memset(val, 0, sizeof val); }
	inline void build(int n) {
		for (int i = 1; i <= n; ++i)
			val[i][i] = 1;
	}
	long long val[N][N];
	/* Matrix operator*(const Matrix &Other) const {
		Matrix res;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					(res.val[i][j] += this->val[i][k] * Other.val[k][j] % P) %= P;
		return res;
	}
	Matrix operator*=(const Matrix &Other) const {
		Matrix res;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					(res.val[i][j] += this->val[i][k] * Other.val[k][j] % P) %= P;
		return res;
	} */
} origin;
int n, k;
Matrix operator*(const Matrix &a, const Matrix &b) {
	Matrix res;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				(res.val[i][j] += a.val[i][k] * b.val[k][j] % P) %= P;
	return res;
}
inline Matrix mpow(Matrix x, int k) {
	Matrix res;
	res.build(n);
	for (; k; k >>= 1) {
		if (k & 1) res = res * x;
		x = x * x;
	}
	return res;
}
bool MEMED;
signed main() {
	FastIO;
#ifdef DEBUG
	cerr << "Memory used: " << abs(&MEMST - &MEMED) / 1048576. << endl;
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> origin.val[i][j];
	Matrix ans = mpow(origin, k);
	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= n; ++j)
			cout << ans.val[i][j] << ' ';
	cout.flush();
	return 0;
}

