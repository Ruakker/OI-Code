#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1e6 + 5;int n;
int a[N];
std::vector<int> g, inDgr;
std::vector<bool> vis;
std::queue<int> Q;

void Topo() {
    for (int i = 1; i <= n; ++i)
        if (!inDgr[i]) Q.push(i), vis[i] = true;
    for (; !Q.empty();) {
        int u = Q.front();
        Q.pop();
        int v = g[u];
        --inDgr[v];
        if (!inDgr[v] && !vis[v]) Q.push(v), vis[v] = true;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int _;
    for (cin >> _; _--;) {
        cin >> n;
        g.clear(), inDgr.clear(), vis.clear();
        g.resize(n + 1), inDgr.resize(n + 1), vis.resize(n + 1);
        for (; !Q.empty(); Q.pop());
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            g[i] = i - a[i];
            inDgr[i - a[i]]++;
        }

        Topo();
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) ++cnt;
        cout << cnt << '\n';
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
