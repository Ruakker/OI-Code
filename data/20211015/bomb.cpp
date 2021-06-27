#include <bits/stdc++.h>
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
using std::cout;
using std::cerr;
#define endl '\n'

const int N = 1e6 + 5;

std::vector<int> g[N], ng[N];

int n, m, ans;
int inDgr[N], len[N];

struct info {
    info() { size = 1; }
    int dfn, low, color, size;
} p[N];

std::stack<int> st;
bool inst[N];

int dfnCounter;

void tarjan(int u) {
    p[u].low = p[u].dfn = ++dfnCounter;
    st.push(u), inst[u] = true;
    for (auto v : g[u]) {
        if (!p[v].dfn) {
            tarjan(v);
            p[u].low = std::min(p[u].low, p[v].low);
        } else if (inst[v]) 
            p[u].low = std::min(p[u].low, p[v].dfn);
    }
    if (p[u].dfn == p[u].low)
        for (; !st.empty();) {
            int top = st.top();
            st.pop();
            inst[top] = false;
            p[top].color = u;
            if (u == top) break;
            ++p[u].size;
        }
}

std::queue<int> Q;

void Kahn() {
    for (;!Q.empty(); Q.pop()) {
        int u = Q.front();
        for (auto v : ng[u]) {
                len[v] = std::max(len[v], len[u] + p[p[v].color].size);
            if (p[v].color == v && !--inDgr[v]) {
                Q.push(v);
            }    
        }
    }
}

signed main() {
#ifndef DEBUG
    freopen("bomb.in", "r", stdin), freopen("bomb.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }

    for (int i = 1; i <= n; ++i) p[i].color = i;

    for (int i = 1; i <= n; ++i)
        if (!p[i].dfn) tarjan(i);

#ifdef DEBUG
    for (int u = 1; u <= n; ++u)
        cerr << p[u].color << ' ';
    cerr << endl;
#endif

    for (int u = 1; u <= n; ++u) {
        for (auto v : g[u]) {
            if (p[v].color != p[u].color)
                ng[p[u].color].emplace_back(p[v].color);
        }
    }

    for (int u = 1; u <= n; ++u)
        if (p[u].color == u)
            for (auto v : ng[u])
                inDgr[v]++;

    for (int i = 1; i <= n; ++i)
        if (!inDgr[i] && p[i].color == i)
            Q.push(i), len[i] = p[i].size;

    Kahn();

    for (int i = 1; i <= n; ++i)
        ans = std::max(ans, len[i]);

    cout << ans << endl;

    return 0;
}
