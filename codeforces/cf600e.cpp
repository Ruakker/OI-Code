/**
 * File              : CF600E.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/07/2021
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
const int N = 1e5 + 5;
int n;
std::vector<std::vector<int>> g, rec;
struct Info {
    int col, size, son, fa;
};
std::vector<Info> p;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// std::unordered_map<int, int, custom_hash> cnt;
std::vector<int> cnt;
std::vector<long long> ans;
void dfs1(int u, int pre) {
    p[u].fa = pre, p[u].size = 1, p[u].son = 0;
    for (auto v : g[u]) {
        if (v == pre) continue;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (!p[u].son || p[p[u].son].size < p[v].size) p[u].son = v;
    }
}
int max;
long long res;
inline void add(int k) {
    cnt[k]++;
    if (cnt[k] > max)
        max = cnt[k], res = k;
    else if (cnt[k] == max)
        res += k;
}
void dfs2(int u, int pre, bool keep) {
    for (auto v : g[u]) {
        if (v == pre || v == p[u].son) continue;
        dfs2(v, u, false);
    }
    if (p[u].son) {
        dfs2(p[u].son, u, true);
        std::swap(rec[u], rec[p[u].son]);
    }
    // max = 0, res = 0;
    rec[u].emplace_back(u), add(p[u].col);
    for (auto v : g[u]) {
        if (v == pre || v == p[u].son) continue;
        for (auto w : rec[v]) rec[u].emplace_back(w), add(p[w].col);
    }
#ifdef DEBUG
    cerr << ">>> " << u << ": ";
    for (int i = 1; i <= n; ++i) cerr << cnt[i] << ' ';
    // for (auto ele : cnt) cerr << ele.second << ' ';
    cerr << endl;
#endif
    ans[u] = res;
    if (!keep)
        for (auto w : rec[u]) {
            cnt[p[w].col]--;
            res = max = 0;
        }
}
signed main() {
    cin >> n;
    g.resize(n + 1), p.resize(n + 1), rec.resize(n + 1), ans.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i].col;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, false);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}