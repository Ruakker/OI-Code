/**
 * File              : readtree-correct.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/06/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;

const int N = 1e6 + 5;
int n, dfnCounter;
int dfn[N], son[N][26], size[N], ans[N];
char s[N];
std::vector<int> g[N];
int merge(int x, int y) {
    if (!x || !y) return x ^ y;
    size[x] = 1;
    for (int i = 0; i < 26; ++i) {
        son[x][i] = merge(son[x][i], son[y][i]);
        size[x] += size[son[x][i]];
    }
    return x;
}
void dfs(int u, int fa) {
    dfn[u] = ++dfnCounter, size[dfn[u]] = 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dfn[u] = merge(dfn[u], dfn[v]);
    }
    int p = ++dfnCounter;
    size[p] = size[dfn[u]] + 1;
    son[p][s[u] - 'a'] = dfn[u];
    dfn[u] = p;
    ans[u] = size[dfn[u]] - 1;
}
int val[N];
signed main() {
    // freopen("readtree.in", "r", stdin);
    // freopen("readtree.out", "w", stdout);
    io >> n;
    for (int i = 1; i <= n; ++i) io >> val[i];
    io >> (s + 1);
    for (int i = 1, u, v; i < n; ++i) {
        io >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; ++i) io << ans[i] << " ";
    int max = 0, count = 0;
    for (int i = 1; i <= n; ++i) {
        if (max < ans[i] + val[i]) {
            max = ans[i] + val[i];
            count = 1;
        } else if (max == ans[i] + val[i])
            ++count;
    }
    io << max << '\n' << count << '\n';
    return 0;
}
