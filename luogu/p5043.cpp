/**
 * File              : P5043.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/26/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
const int N = 100;
int m;
struct Tree {
   protected:
    unsigned seed = 233;
    unsigned long long hash[N], base[N];
    unsigned size[N];
    void dfs(int u) {
        int sum = 0, cnt = 0;
        size[u] = 1;
        if (g[u].empty()) {
            hash[u] = 1;
            return;
        }
        for (auto v : g[u]) {
            ++cnt;
            dfs(v);
            sum += hash[v] * base[cnt - 1];
            size[u] += size[v];
        }
        hash[u] = size[u] * sum;
    }
    inline void getRoot() {}

   public:
    int n, root;
    std::vector<int> g[N];
    inline void init() {
        base[0] = 1;
        for (int i = 1; i < N; ++i)
            base[i] = base[i - 1] * seed;
        getRoot();
        dfs(root);
#ifdef DEBUG
        for (int i = 1; i <= n; ++i)
            cerr << hash[i] << ' ';
        cerr << endl;
        for (int i = 1; i <= n; ++i)
            cerr << size[i] << ' ';
        cerr << endl;
#endif
    }
    inline unsigned long long getHash() { return hash[root]; }
    inline unsigned long long getHash(int u) { return hash[u]; }
} T[N];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> T[i].n;
        for (int u = 1, fa; u <= T[i].n; ++u) {
            cin >> fa;
            if (!fa)
                T[i].root = u;
            else
                T[i].g[fa].emplace_back(u), T[i].g[u].emplace_back(fa);
        }
        for (int i = 1; i <= T[i].n; ++i)
            std::sort(T[i].g[i].begin(), T[i].g[i].end());
        T[i].init();
        cout << T[i].getHash() << endl;
    }
    return 0;
}