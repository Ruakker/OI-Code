#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
using std::cerr;
using std::cout;

#define int long long
const int N = 1e6 + 5;

std::vector<int> g[N];

int n, m;

struct info {
    int dfn, low, color, size = 1;
    bool cut = false;
} p[N];

std::stack<int> st;
bool inst[N], vis[N];

int dfnCounter;
long long ans;
void tarjan(int u, int pre) {
    p[u].dfn = p[u].low = ++dfnCounter;
    st.push(u);
    for (auto v : g[u]) {
        if (v == pre) continue;
        if (!p[v].dfn) {
            tarjan(v, u);
            if (p[v].low >= p[u].dfn) {
                int cnt = 2;
                for (; st.top() != v; st.pop()) ++cnt;
                st.pop();
                ans += cnt * (cnt - 1) >> 1;
            }
            p[u].low = std::min(p[u].low, p[v].low);
        } else
            p[u].low = std::min(p[u].low, p[v].dfn);
    }
}

signed main() {
#ifndef DEBUG
    freopen("graph.in", "r", stdin), freopen("graph.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!p[i].dfn) {
            dfnCounter = 0;
            tarjan(i, 0);
        }

    cout << ans << '\n';

    return 0;
}

/*
14 18
1 2
2 3
3 4
4 1
3 6
1 5
5 6
1 7
7 8
8 9
6 9
9 10
9 11
11 12
10 12
8 13
8 14
14 9
*/
