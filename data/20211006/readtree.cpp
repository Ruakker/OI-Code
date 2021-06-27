/**
 * File              : readtree.cpp
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
const int N = 3e5 + 5;
const unsigned long long hashBase = 233;
class StringHash {
   private:
    unsigned long long hash[N], base[N];
    char s[N];
    int len;

   public:
    StringHash() { init(); }
    inline void init() {
        len = 0;
        hash[0] = 0, base[0] = 1;
    }
    inline void append(char ch) {
        s[++len] = ch;
        base[len] = base[len - 1] * hashBase;
        hash[len] = hash[len - 1] * hashBase + ch;
    }
    inline void del() { --len; }
    inline int length() { return len; }
    inline unsigned long long getHash(int l, int r) {
        return hash[r] - hash[l - 1] * base[r - l + 1];
    }
    inline unsigned long long getHash() { return hash[len]; }
} s;
std::vector<int> g[N];
int n, ans[N];
char val[N];
std::unordered_map<unsigned long long, int> S;
void dfs(int u, int fa) {
    s.append(val[u]);
    if (S.find(s.getHash()) == S.end())
        S.insert(std::make_pair(s.getHash(), 1));
    else
        S[s.getHash()]++;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    ans[u] = S.size();
    S[s.getHash()]--;
    if (S[s.getHash()] == 0) S.erase(s.getHash());
    s.del();
}
void dfs2(int u, int fa) {
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        ans[u] += ans[v];
    }
}
signed main() {
    // freopen("readtree.in", "r", stdin);
    // freopen("readtree.out", "w", stdout);
    io >> n;
    io >> &val[1];
    for (int i = 1, u, v; i < n; ++i) {
        io >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) io << ans[i] << ' ';
    io << '\n';
    return 0;
}