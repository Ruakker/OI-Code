/**
 * File              : P2048.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 2021/08/21
 * Last Modified Date: 2021/08/21
 */
#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
#define ll long long
constexpr int N = 1e6 + 5, logN = 19;
int n, k, L, R;
ll ans;
int a[N], sum[N];

namespace ST {
int st[N][logN], logn[N];
inline int max(int a, int b) { return a > b ? a : b; }
inline void init() {
	logn[1] = 0, logn[2] = 1;
	for (int i = 3; i <= 1000000; ++i)
		logn[i] = logn[i >> 1] + 1;
	for (int i = 1; i <= n; i++)
		st[i][0] = i;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
			st[i][j] = sum[x] > sum[y] ? x : y;
		}
}
int query(int l, int r) {
	int k = logn[r - l + 1];
	int x = st[l][k], y = st[r - (1 << k) + 1][k];
	return sum[x] > sum[y] ? x : y;
}
//inline void init(){
//	for (int i=1;i<=n;++i)
//		st[i][0]=a[i];
//	logn[1]=0, logn[2]=1;
//	for (int i=3;i<=N;++i)
//		logn[i]=logn[i>>1]+1;
//	for (int j=1;j<=logN;++j)
//		for (int i=1;i+(1<<j)-1<=n;++i)
//			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
//}
//inline int query(int l,int r){
//	int s=logn[r-l+1];
//	int x=st[l][s],y=st[r-(1<<s)+1][s];
//	return
//	return max(st[l][s]>st[r-(1<<s)+1][s]?l:r-(1<<s)+1);
//}
} // namespace ST

struct Elements {
	Elements(int a, int b, int c) { st = a, l = b, r = c, ed = ST::query(l, r); }
	int st, l, r, ed;
	bool operator>(const Elements &Other) const {
		return sum[this->ed] - sum[this->st - 1] > sum[Other.ed] - sum[Other.st - 1];
	}
	bool operator<(const Elements &Other) const {
		return sum[this->ed] - sum[this->st - 1] < sum[Other.ed] - sum[Other.st - 1];
	}
};
std::priority_queue<Elements> Q;

signed main() {
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> k >> L >> R;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	ST::init();
	for (int i = 1; i <= n - L + 1; ++i)
		Q.push(Elements(i, i + L - 1, std::min(i + R - 1, n)));
	for (; k--;) {
		Elements cur = Q.top();
		Q.pop();
		ans += sum[cur.ed] - sum[cur.st - 1];
		if (cur.l < cur.ed) Q.push(Elements(cur.st, cur.l, cur.ed - 1));
		if (cur.r > cur.ed) Q.push(Elements(cur.st, cur.ed + 1, cur.r));
	}
	cout << ans << endl;
	cout.flush();
	return 0;
}
