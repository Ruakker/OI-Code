/**
 * File              : tree.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/25/2021
 */
#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
#define endl '\n'
#define int long long
const int N = 4e5 + 5;
int n, ans;
int a[N], fa[N], pre[N], p[N][3];
std::vector<int> g[N];
inline int getfa(int u) { return (fa[u] == u) ? u : fa[u] = getfa(fa[u]); }
struct Node {
    Node() {}
    Node(int k) {
        this->id = k;
        for (int i = 0; i < 3; ++i)
            this->p[i] = ::p[k][i];
    }
    int id, p[3];
    bool operator<(const Node &Other) const {
        int sum1 = 0, sum2 = 0, ans1 = 0, ans2 = 0;
        for (int i = 0; i < 2; i++) {
            sum1 += this->p[i];
            ans1 += sum1 * Other.p[i + 1];
            sum2 += Other.p[i];
            ans2 += sum2 * this->p[i + 1];
        }
        if (ans1 == ans2) return this->id < Other.id;
        return ans2 < ans1;
    }
};
std::set<Node> Q;  // Replace priority_queue?
signed mainC() {
    cerr << "C" << endl;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 2; i <= n; ++i)
        Q.insert(i);
    for (; !Q.empty();) {
        Node u = *Q.begin();  // min
        Q.erase(Q.begin());
        int father = getfa(pre[u.id]), sum = 0;
        for (int i = 0; i < 2; ++i) {
            sum += u.p[i];
            ans += p[father][i + 1] * sum;
        }
        Node v = Node(father);
        for (int i = 0; i < 3; ++i)
            p[father][i] += p[u.id][i];
        fa[u.id] = father;
        if (father != 1) {
            Q.erase(v);
            Q.insert(father);
        }
    }
    cout << ans << endl;
    return 0;
}

struct Fenwick {
   protected:
    int val[N];
    inline int lowbit(int x) { return x & -x; }

   public:
    Fenwick() { clear(); }
    inline void add(int k) {
        for (; k <= n; k += lowbit(k))
            ++val[k];
    }
    inline int query(int k) {
        int res = 0;
        for (; k >= 1; k -= lowbit(k))
            res += val[k];
        return res;
    }
    inline void clear() { memset(val, 0, sizeof val); }
} T;
int rnk[N];
inline int solve() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        T.add(rnk[i]);
        res += T.query(n) - T.query(rnk[i]);
    }
    return res;
}
signed mainA() {
    cerr << "A" << endl;
    cout << solve() << endl;
    return 0;
}
signed mainB() {
    cerr << "B" << endl;
    std::sort(rnk + 2, rnk + n + 1);
    cout << solve() << endl;
    return 0;
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(0);
    bool flag1 = true, flag2 = true;
    cin >> n;
    for (int v = 2, u; v <= n; ++v) {
        cin >> u;
        if (u != v - 1) flag1 = false;
        if (u != 1) flag2 = false;
        g[u].emplace_back(v);
        pre[v] = u;
    }
    int tmp[N];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++p[i][a[i]];
        ++a[i];
        tmp[i] = a[i];
    }
    std::sort(tmp + 1, tmp + 1 + n);
    int len = std::unique(tmp + 1, tmp + 1 + n) - tmp;
    for (int i = 1; i <= n; ++i)
        rnk[i] = std::lower_bound(tmp + 1, tmp + 1 + len, a[i]) - tmp;
    if (flag1) return mainA();  // flower
    if (flag2) return mainB();  // chain
    return mainC();
}