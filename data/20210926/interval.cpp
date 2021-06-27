/**
 * File              : interval.cpp
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
const int N = 1e4 + 5;
int n, k, ans;
std::pair<int, int> a[N];
struct Node {
    Node() { val = -inf; }
    Node(int u, int v) {  // read two id
        l = std::max(a[u].first, a[v].first);
        r = std::min(a[u].second, a[v].second);
        this->u = u, this->v = v;
        val = r - l;
        if (val <= 0) val = -inf;
    }
    int l, r, u, v, val;
    bool operator<(const Node& Other) const { return this->val < Other.val; }
};
std::priority_queue<Node, std::vector<Node>, std::less<Node>> Q;  // max heap
int fa[N], size;
bool vis[N][N];
int getfather(int x) { return ((x == fa[x]) ? x : (fa[x] = getfather(fa[x]))); }
inline void merge(int u, int v) {
    int fau = getfather(u), fav = getfather(v);
    fa[fau] = fav;
    a[fav] = std::make_pair(std::max(a[fau].first, a[fav].first),
                            std::min(a[fau].second, a[fav].second));
    --size;
}
signed main() {
    // freopen("interval.in","r",stdin);
    // freopen("interval.out","w",stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    size = n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second, fa[i] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            Q.emplace(i, j);
    for (Node ele; size > k;) {
        ele = Q.top();
        if (ele.val == -inf) {
            cout << -1 << endl;
            return 0;
        }
        Q.pop();
        merge(ele.u, ele.v);
        for (int i = 1; i <= n; ++i)
            if (getfather(i) == i && getfather(i) != getfather(ele.v)) {
                assert(!(vis[getfather(i)][ele.v] || vis[ele.v][getfather(i)]));
                Q.emplace(getfather(i), ele.v);
            }
    }
    for (int i = 1; i <= n; ++i)
        if (getfather(i) == i) {
            ans += a[i].second - a[i].first;
#ifdef DEBUG
            cerr << ">>> " << a[i].first << ' ' << a[i].second << endl;
#endif
        }
#ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cerr << getfather(i) << endl;
#endif
    cout << ans << endl;
    return 0;
}