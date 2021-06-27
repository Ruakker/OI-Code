/**
 * File              : team.cpp
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
bool st;
const int N = 1005;
int a[N][N], col[N], cntcol[2];
int n, m;
std::vector<std::unordered_set<int>> g;
std::bitset<N> vis;
std::vector<int> diff;
inline void init() {
    g.clear(), diff.clear();
    g.resize(n + 1);
    vis.set();
    m = 0;
    memset(col, 0, sizeof col);
    memset(a, 0, sizeof a);
}
bool setColor(int u, int pre) {
    vis[u] = true;
    col[u] = col[pre] ^ 1;
    cntcol[col[u]]++;
    for (auto v : g[u]) {
        if (v == pre) continue;
        if (vis[v]) {
            if (col[u] == col[v]) return false;
            continue;
        }
        if (!setColor(v, u)) return false;
    }
    return true;
}
signed main() {
    // freopen("team.in", "r", stdin);
    // freopen("team.out", "w", stdout);
    int T;
    io >> T;
    for (; T--;) {
        io >> n;
        init();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                io >> a[i][j];
                if (!a[i][j]) {
                    g[i].insert(j), g[j].insert(i);
                    vis[i] = false, vis[j] = false;
                }
            }
        bool flag = false;
        if (n == 1) {
            io << "No solution" << '\n';
            flag = true;
            continue;
        }
        for (int i = 1; i <= n; ++i)
            if (vis[i]) ++m;  // the count of the man which is not in the graph
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) {
                cntcol[0] = cntcol[1] = 0;
                if (!setColor(i, 0)) {
                    io << "No solution" << '\n';
                    flag = true;
                    break;
                }
                if (cntcol[0] > cntcol[1]) std::swap(cntcol[0], cntcol[1]);
                diff.emplace_back(abs(cntcol[0] - cntcol[1]));
            }
        if (flag) continue;
        std::sort(diff.begin(), diff.end(), std::greater<int>());
        int l = 0, r = 0;
        for (auto ele : diff)
            if (l < r)
                l += ele;
            else
                r += ele;
        if (abs(l - r) <= m)
            io << (n & 1) << '\n';
        else
            io << abs(abs(l - r) - m) << '\n';
    }
    bool ed;
    cerr << abs(&st - &ed) / 1024. / 1024. << endl;
    return 0;
}