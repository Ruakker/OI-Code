/**
 * File              : charity-correct.cpp
 * T1uthor            : Ruakker <i@ruakker.cn>
 * Date              : 10/05/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;

const int N = 4e6 + 5;
struct info {
    info(int a, int b) : x(a), y(b) {}
    int x, y, z;
};
int n, valb[N], tot, fa[N];
int ida[N], idb[N], dfn[N], siz[N];
long long ans;
std::vector<info> e;
std::vector<int> T1[N], T2[N];
class Fenwick {
   private:
    int val[N];
    inline int lowbit(int x) { return x & -x; }

   public:
    inline void add(int k, int w) {
        for (; k; k -= lowbit(k)) val[k] += w;
    }
    inline int ask(int k) {
        int res = 0;
        for (; k <= 2 * n - 1; k += lowbit(k)) res += val[k];
        return res;
    }
} T;
inline bool cmpa(info x, info y) {
    return std::min(x.x, x.y) > std::min(y.x, y.y);
}
inline bool cmpb(info x, info y) {
    return std::max(x.x, x.y) < std::max(y.x, y.y);
}
inline int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
inline void init(int x) {
    siz[x] = 1, dfn[x] = ++tot;
    for (auto y : T1[x]) init(y), siz[x] += siz[y];
}
inline void dfs(int x) {
    int now = valb[x];
    if (x == idb[now]) {
        ans += T.ask(dfn[ida[now]]) - T.ask(dfn[ida[now]] + siz[ida[now]]);
        T.add(dfn[ida[now]], 1);
    }
    for (auto y : T2[x]) dfs(y);
    if (x == idb[now]) T.add(dfn[ida[now]], -1);
}
signed main() {
    freopen("charity.in", "r", stdin);
    freopen("charity.out", "w", stdout);
    io >> n;
    for (int i = 1, u; i <= n; ++i) {
        io >> u;
        if (i == 1) continue;
        e.emplace_back(i, u);
    }
    std::sort(e.begin(), e.end(), cmpa);
    for (int i = 1; i <= n; ++i) ida[i] = idb[i] = i;
    tot = n;
    for (int i = 1; i <= 2 * n - 1; ++i) fa[i] = i;
    for (auto ele : e) {
        int x = getfa(ele.x), y = getfa(ele.y), val = std::min(ele.x, ele.y);
        fa[x] = fa[y] = ida[val] = ++tot;
        T1[tot].emplace_back(x), T1[tot].emplace_back(y);
    }
    for (int i = 1; i <= 2 * n - 1; ++i) valb[i] = i;
    std::sort(e.begin(), e.end(), cmpb);
    tot = n;
    for (int i = 1; i <= 2 * n - 1; ++i) fa[i] = i;
    for (auto ele : e) {
        int x = getfa(ele.x), y = getfa(ele.y), val = std::max(ele.x, ele.y);
        fa[x] = fa[y] = idb[val] = ++tot;
        valb[tot] = val, T2[tot].emplace_back(x), T2[tot].emplace_back(y);
    }
    tot = 0, init(2 * n - 1);
    dfs(2 * n - 1);
    io << ans << '\n';
    return 0;
}