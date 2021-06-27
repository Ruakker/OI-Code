#include <bits/stdc++.h>
/*
* @ legendgod
* 纵使前路是无底深渊，下去了也是前程万里
*/
using namespace std;

//#define Fread
//#define Getmod

#ifdef Fread
char buf[1 << 21], *iS, *iT;
#define gc() (iS == iT ? (iT = (iS = buf) + fread (buf, 1, 1 << 21, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
#endif // Fread

template <typename T>
void r1(T &x) {
	x = 0;
	char c(getchar());
	int f(1);
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(; '0' <= c && c <= '9';c = getchar()) x = (x * 10) + (c ^ 48);
	x *= f;
}

#ifdef Getmod
const int mod  = 1e9 + 7;
template <int mod>
struct typemod {
    int z;
    typemod(int a = 0) : z(a) {}
    inline int inc(int a,int b) const {return a += b - mod, a + ((a >> 31) & mod);}
    inline int dec(int a,int b) const {return a -= b, a + ((a >> 31) & mod);}
    inline int mul(int a,int b) const {return 1ll * a * b % mod;}
    typemod<mod> operator + (const typemod<mod> &x) const {return typemod(inc(z, x.z));}
    typemod<mod> operator - (const typemod<mod> &x) const {return typemod(dec(z, x.z));}
    typemod<mod> operator * (const typemod<mod> &x) const {return typemod(mul(z, x.z));}
    typemod<mod>& operator += (const typemod<mod> &x) {*this = *this + x; return *this;}
    typemod<mod>& operator -= (const typemod<mod> &x) {*this = *this - x; return *this;}
    typemod<mod>& operator *= (const typemod<mod> &x) {*this = *this * x; return *this;}
    int operator == (const typemod<mod> &x) const {return x.z == z;}
    int operator != (const typemod<mod> &x) const {return x.z != z;}
};
typedef typemod<mod> Tm;
#endif

template <typename T,typename... Args> inline void r1(T& t, Args&... args) {
    r1(t);  r1(args...);
}

//#define int long long
const int maxn = 1e6 + 5;
const int maxm = maxn << 1;
int n;

int pr[maxn], tot(0);
int vis[maxn];

void init(int x) {
    for(int i = 2; i <= x; ++ i) {
        if(!vis[i]) pr[++ tot] = i;
        for(int j = 1, k; k = i * pr[j], j <= tot && k <= x; ++ j) {
            vis[k] = 1;
            if(!(i % pr[j])) break;
        }
    }
}
int g[maxn], d[maxn], ans(2e9);
void Check(int x) {
//    d[1] = 1;
//d[1] = 1,
//d[2] = -1,
//d[3] = -1,
//d[5] = -1,
//d[7] = -1,
//d[11] = 1,
//d[13] = -1,
//d[17] = -1,
//d[19] = 1,
//d[23] = -1,
//d[29] = 1,
//d[31] = 1,
//d[37] = -1,
//d[41] = -1,
//d[43] = -1,
//d[47] = -1;
d[1] = 1;
    for(int i = 2; i <= x; ++ i) {
        if(!vis[i]) {
            pr[++ tot] = i;
            if(tot & 1) d[i] = -1;
            else d[i] = 1;
        }
        for(int j = 1, k; k = i * pr[j], j <= tot && k <= x; ++ j) {
            d[k] = d[i] * d[pr[j]];
            vis[k] = 1;
            if(!(i % pr[j])) break;
        }
    }
    int res(1), sum(1);
    for(int i = 2; i <= x; ++ i) sum += d[i], res = max(res, abs(sum));
    if(ans > res) {
        ans = res;
        for(int i = 1; i <= x; ++ i) g[i] = d[i];
    }
}

signed main() {
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);
    int i, j;
    srand(time(0));
    r1(n);
//    for(i = 1; i <= 100; ++ i)
    Check(n);
    for(i = 1; i <= (int)(n); ++ i) printf("%d ", g[i]);
    printf("%d\n", ans);
	return 0;
}
/*
d[1] = 1,
d[2] = -1,
d[3] = -1,
d[5] = -1,
d[7] = -1,
d[11] = 1,
d[13] = -1,
d[17] = -1,
d[19] = 1,
d[23] = -1,
d[29] = 1,
d[31] = 1,
d[37] = -1,
d[41] = -1,
d[43] = -1,
d[47] = -1,
*/
