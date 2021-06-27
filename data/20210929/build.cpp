/**
 * File              : build.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/30/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;

#define int long long
const int N = 1e5 + 5, logN = 20;
std::vector<int> g[N];
int n, q;
struct info {
    info() { size = depth = 0; }
    int size, depth, fsum, gsum, sum;
    int fa[21];
} p[N];
void dfs(int u, int fa = 0) {
    p[u].fa[0] = fa;
    p[u].size = 1;
    p[u].depth = p[fa].depth + 1;
    for (int i = 1; i <= 20; ++i)
        p[u].fa[i] = p[p[u].fa[i - 1]].fa[i - 1];
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        p[u].size += p[v].size;
    }
}
int lca(int u, int v) {
    if (p[u].depth < p[v].depth) std::swap(u, v);
    for (int i = 20; ~i; --i)
        if (p[p[u].fa[i]].depth >= p[v].depth) u = p[u].fa[i];
    if (v == u) return u;
    for (int i = 20; ~i; --i)
        if (p[u].fa[i] != p[v].fa[i]) u = p[u].fa[i], v = p[v].fa[i];
    return p[u].fa[0];
}
inline int dist(int u, int v) {
    return p[u].depth + p[v].depth - (p[lca(u, v)].depth << 1);
}
inline int goUp(int u, int k) {
    for (int i = 20; ~i; --i)
        if (k >> i & 1) u = p[u].fa[i];
    return u;
}

void getSum(int u) {
    p[u].fsum = 0;
    for (auto v : g[u]) {
        if (v == p[u].fa[0]) continue;
        p[v].sum = p[u].sum - p[v].size + (n - p[v].size);
        getSum(v);
        p[u].fsum += p[v].fsum + p[v].size;
    }
    p[u].gsum = p[u].sum - p[u].fsum;
}
signed main() {
    freopen("build.in", "r", stdin);
    freopen("build.out", "w", stdout);
    io >> n;
    for (int i = 1, u, v; i < n; ++i) {
        io >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        p[1].sum += p[i].depth - 1;
    getSum(1);
#ifdef DEBUG
    cerr << p[1].sum << endl;
    cerr << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].fsum << ' ';
    cerr << endl << ">>> ";
    for (int i = 1; i <= n; ++i)
        cerr << p[i].gsum << ' ';
    cerr << endl;
#endif
    io >> q;
    for (int u, v; q--;) {
        io >> u >> v;
        if (u == v) {
            io << p[u].sum << '\n';
            continue;
        }
        if (p[u].depth < p[v].depth) std::swap(u, v);  // let the depth: u > v
        int x = goUp(u, dist(u, v) / 2);
        int y = p[x].fa[0];
        int ans = p[u].sum + p[v].sum + p[x].size - p[y].sum -
                  (n - p[x].size) * dist(u, y) - p[x].size * dist(x, v);
        io << ans << '\n';
    }
    return 0;
}