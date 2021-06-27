#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

const int N = 2e5 + 5;
int n;
std::vector<std::vector<int>> g;
std::vector<std::string> p;
std::map<std::string, int> bel;

inline int getNode(std::string u) {
    if (bel.find(u) == bel.end()) {
        p.push_back(u);
        bel[u] = p.size() - 1;
        return p.size() - 1;
    }
    return bel[u];
}

signed main() {
#ifndef DEBUG
    freopen("recover.in", "r", stdin), freopen("recover.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        cin >> n;
        g.clear(), bel.clear(), p.clear();
        g.resize(n + 1), p.push_back();
        std::string s;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            int u = getNode(s.substr(0, 2)), v = getNode(s.substr(1, 2));
            g[u].push_back(v);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int n, m, u, v, del[MAX];
int du[MAX][2];  //记录入度和出度
stack<int> st;
vector<int> G[MAX];
void dfs(int now) {
    for (int i = del[now]; i < G[now].size(); i = del[now]) {
        del[now] = i + 1;
        dfs(G[now][i]);
    }
    st.push(now);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &u, &v), G[u].push_back(v), du[u][1]++, du[v][0]++;
    for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
    int S = 1, cnt[2] = {0, 0};  //记录
    bool flag = 1;  // flag=1表示,所有的节点的入度都等于出度,
    for (int i = 1; i <= n; i++) {
        if (du[i][1] != du[i][0]) flag = 0;
        if (du[i][1] - du[i][0] == 1 /*出度比入度多1*/) cnt[1]++, S = i;
        if (du[i][0] - du[i][1] == 1 /*入度比出度多1*/) cnt[0]++;
    }
    if ((!flag) && !(cnt[0] == cnt[1] && cnt[0] == 1)) return !printf("No");
    //不满足欧拉回路的判定条件，也不满足欧拉路径的判定条件，直接输出"No"
    dfs(S);
    while (!st.empty()) printf("%d ", st.top()), st.pop();
    return 0;
}
