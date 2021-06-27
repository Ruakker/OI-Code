/**
 * File              : P4899.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/08/2021
 */
#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
const int N = 2e5 + 5;
int n, m, q;
int x[N], y[N], st[N], ed[N], l[N], r[N];
std::vector<std::vector<int>> g;
class KruskalRefactorTree {
   protected:
    int fa[N], n;
    struct Info {
        int fa[22], l, r, val;
    } p[N];
    std::vector<std::vector<int>> g;
    int getfa(int x) { return getfa(x) == x ? x : fa[x] = getfa(fa[x]); }
    inline void merge(int u, int v, int w) {
        int fau = getfa(u), fav = getfa(v);
        if (fau == fav) return;
        fa[fau] = fav, ++n;
        g[n].emplace_back(u), g[n].emplace_back(v);
        g[u].emplace_back(n), g[v].emplace_back(n);
        p[n].val = w;
    }
    int dfnCounter = 0;
    void dfs(int u, int pre) {
        p[u].l = p[u].r = ++dfnCounter, p[u].fa[0] = pre;
        for (int i = 1; i < 22; ++i) p[u].fa[i] = p[p[u].fa[i - 1]].fa[i - 1];
        for (auto v : g[u]) {
            if (v == pre) continue;
            dfs(v, u);
            p[u].r = std::max(p[u].r, p[v].r);
        }
    }

   public:
    struct Edge {
        Edge(int a, int b, int c) { u = a, v = b, val = c; }
        int u, v, val;
        bool operator<(Edge Other) const { return this->val < Other.val; }
        bool operator>(Edge Other) const { return this->val > Other.val; }
    };
    std::vector<Edge> e;
    int ans[N];
    inline void build(int flag) {
        g.resize(::n + 1), n = ::n;
        for (int i=1;i<=n;++i)
            fa[i]=i;
        if (flag == 1)
            std::sort(e.begin(), e.end(), std::greater<Edge>()),
                p[0].val = -inf;
        if (flag == -1)
            std::sort(e.begin(), e.end(), std::less<Edge>()), p[0].val = inf;
        for (auto cur : e) merge(cur.u, cur.v, cur.val);
        dfs(n, 0);
        if (flag == 1) {
            for (int i = 1; i <= q; ++i) {
                int u = ed[i];
                for (int j = 21; ~j; --j)
                    if (p[u].fa[j] <= r[i]) u = p[u].fa[j];
                ans[i] = u;
            }
        }
        if (flag == -1) {
            for (int i = 1; i <= q; ++i) {
                int u = st[i];
                for (int j = 21; ~j; --j)
                    if (p[u].fa[j] <= l[i]) u = p[u].fa[j];
                ans[i] = u;
            }
        }
    }
} T1, T2;  // T1 is the min, and T2 is the max
signed main() {
    cin >> n >> m >> q;
    g.resize(n + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
        T1.e.emplace_back(u, v, std::min(u, v));
        T2.e.emplace_back(u, v, std::max(u, v));
    }
    for (int i = 1; i <= q; ++i) cin >> st[i] >> ed[i] >> l[i] >> r[i];

    T1.build(-1), T2.build(1);  //-1: min, 1: max
#ifdef DEBUG
    for (int i = 0; i < q; ++i) cerr << T1.ans[i] << ' ' << T2.ans[i] << endl;
#endif
    return 0;
}