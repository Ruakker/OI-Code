/**
 * File              : CF1594D.cpp
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
const int N = 5e5 + 5;
int n, m;
int goood, baaad, goooooood, baaaaaaad;
std::vector<int> G[N], vised;
bool vis[N], rkkr = false;

inline void dfs(int x, int fath) {
    if (rkkr) return;
    vised.push_back(x);
    vis[x] = true;
    if (x > n) {
        ++baaad;
        if (vis[x] && vis[x - n]) {
            rkkr = true;
            return;
        }
    } else {
        ++goood;
        if (vis[x] && vis[x + n]) {
            rkkr = true;
            return;
        }
    }
    for (auto v : G[x]) {
        if (!vis[v]) dfs(v, x);
    }
    // Ruakker!!!
}

signed main() {
    int T;
    cin >> T;
    for (; T--;) {
        cin >> n >> m;
        for (int i = 1; i <= 2 * n; ++i) G[i].clear();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            char ddd[10];
            cin >> x >> y >> ddd;
            if (ddd[0] == 'i') {
                G[x + n].push_back(y);
                G[y].push_back(x + n);
                G[y + n].push_back(x);
                G[x].push_back(y + n);
            } else {
                G[x + n].push_back(y + n);
                G[y + n].push_back(x + n);
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        rkkr = false;
        int rkk = 0;
        for (int i = 1; i <= 2 * n; ++i) vis[i] = false;
        for (int i = 1; i <= n; ++i) {
            if ((vis[i]) || (vis[i + n])) continue;
            vised.clear();
            goood = baaad = 0;
            ++rkk;
            dfs(i, 0);
            --rkk;
            for (auto v : vised) vis[i] = false;
            rkk += std::max(goood, baaad);
        }
        if (rkkr)
            cout << "-1" << endl;
        else
            cout << rkk << endl;
    }
    return 0;
}