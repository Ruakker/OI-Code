/**
 * File              : charity.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/02/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;

using pii = std::pair<int, int>;
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }
inline int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }
inline pii merge_pair(pii a, pii b) {
    return std::make_pair(min(a.first, a.second, b.first, b.second),
                          max(a.first, a.second, b.first, b.second));
}
constexpr int N = 2e6 + 5;
std::vector<int> g[N];
int n, sum, root;
struct info {
    int size, sonSize;  // sonSize means the max son-tree of this node.
} p[N];
std::bitset<N> vis;
void calcsize(int u, int pre) {
    p[u].size = 1, p[u].sonSize = 0;
    for (auto v : g[u]) {
        if (v == pre || vis[v]) continue;
        calcsize(v, u);
        p[u].size += p[v].size;
        p[u].sonSize = max(p[u].sonSize, p[v].size);
    }
    p[u].sonSize = max(p[u].sonSize, sum - p[u].size);
    if (p[u].sonSize < p[root].sonSize) root = u;
}
pii minmax[N];
std::pair<pii, int> st1[N], st2[N];
std::set<pii> ans;
int top1 = 0, top2 = 0;
inline pii getminmax(int a, pii b) {
    return std::make_pair(min(a, b.first), max(a, b.second));
}
inline bool check(pii a, pii b) {
    return min(a.first, a.second) == min(b.first, b.second) &&
           max(a.first, a.second) == max(b.first, b.second);
}
void calcminmax(int u, int pre) {
    minmax[u] = getminmax(u, minmax[pre]);
    if (u == minmax[u].first) st1[++top1] = std::make_pair(minmax[u], u);
    if (u == minmax[u].second) st2[++top2] = std::make_pair(minmax[u], u);
    for (auto v : g[u]) {
        if (v == pre || vis[v]) continue;
        calcminmax(v, u);
    }
}
std::vector<std::pair<pii, int>> rec1, rec2;
void dfz(int u, int pre) {
    // cerr << u << endl;
    vis[u] = true;
    for (auto v : g[u]) {
        if (v == pre || vis[v]) continue;
        minmax[v] = std::make_pair(min(u, v), max(u, v));
        if (v == minmax[v].first) st1[++top1] = std::make_pair(minmax[v], v);
        if (v == minmax[v].second) st2[++top2] = std::make_pair(minmax[v], v);
        for (auto w : g[v])
            if (v != w && !vis[w]) calcminmax(w, v);
#ifdef Ruakker
        cerr << "=======" << endl;
        for (int i = 1; i <= top; ++i) {
            cerr << st[i].first.first << ' ' << st[i].first.second << ' ';
            cerr << st[i].second << ' ' << u << endl;
        }
#endif
        for (int i = 1; i <= top1; ++i)  // for its own
            if (check(st1[i].first, std::make_pair(st1[i].second, u)))
                ans.insert(st1[i].first);
        for (int i = 1; i <= top2; ++i)  // for its own
            if (check(st2[i].first, std::make_pair(st2[i].second, u)))
                ans.insert(st2[i].first);

        // for (int i = 1; i <= top; ++i)  // for all in rec[]
        //     for (auto ele : rec) {
        //         pii nowminmax = merge_pair(ele.first, st[i].first);
        //         if (check(nowminmax, std::make_pair(ele.second, st[i].second)))
        //             ans.insert(nowminmax);
        //     }
        std::sort()
        for (int i = 1; i <= top1; ++i)  // for all in rec[]
            for (auto ele : rec2) {
                pii nowminmax = merge_pair(ele.first, st1[i].first);
                if (check(nowminmax, std::make_pair(ele.second, st1[i].second)))
                    ans.insert(nowminmax);
            }
        for (int i = 1; i <= top2; ++i)  // for all in rec[]
            for (auto ele : rec1) {
                pii nowminmax = merge_pair(ele.first, st2[i].first);
                if (check(nowminmax, std::make_pair(ele.second, st2[i].second)))
                    ans.insert(nowminmax);
            }

        for (int i = 1; i <= top1; ++i)
            rec1.emplace_back(st1[i]);
        for (int i = 1; i <= top2; ++i)
            rec2.emplace_back(st2[i]);
        top1 = top2 = 0;
    }
    rec1.clear(), rec2.clear();
    for (auto v : g[u]) {
        if (v == pre || vis[v]) continue;
        sum = p[v].size, root = 0, p[root].sonSize = inf;
        calcsize(v, u);
        calcsize(root, -1);
        assert(root);
        dfz(root, u);
    }
}

signed main() {
    // freopen("charity.in", "r", stdin);
    // freopen("charity.out", "w", stdout);
    io >> n;
    for (int i = 1, k; i <= n; ++i) {
        io >> k;
        if (k == 0) continue;
        g[k].emplace_back(i), g[i].emplace_back(k);
    }
    sum = n, root = 0, p[0].sonSize = inf, vis.reset();
    calcsize(1, -1);
    calcsize(root, -1);

    dfz(root, -1);
    io << ans.size() << '\n';
#ifdef Ruakker
    for (auto ele : ans) {
        io << ele.first << ' ' << ele.second << '\n';
    }
#endif
    return 0;
}
