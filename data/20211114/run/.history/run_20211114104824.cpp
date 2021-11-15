#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;

#define inf 0x3f3f3f3f

const int N = 1e5 + 5, L = 0, R = 1e9 + 5;
int m, q, max;

struct Node {
    int val, dis;  // value: 疲惫值, distant: 最大能跑的距离
    inline bool operator==(const Node &Other) const {
        return this->val == Other.val;
    }
    inline bool operator<(const Node &Other) const {
        // return this->val == Other.val ? this->dis < Other.dis : this->val <
        // Other.val;
        return this->val < Other.val;
    }
} a[N];

inline int get(int u) {
    auto p = std::upper_bound(a + 1, a + 1 + m, Node{u, 0}) - 1;
    return p->dis + (u - p->val);
}

inline bool check(int n, int k, int ans) {
    for (int i = k; i >= 1; --i) {  // 枚举分段数
        int len = ans / i, lenx = ans / i + 1;
        int o = get(len), ox = get(lenx);
        if (o * (i - ans % i) + ox * (ans % i) >= n) return true;
    }
    return false;
}

int BinarySearch(int n, int k) {
    int res = inf, l = L, r = R;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(n, k, mid))
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}

signed main() {
#ifndef DEBUG
    freopen("run.in", "r", stdin), freopen("run.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i].dis;

    std::sort(a + 1, a + 1 + m, [](const Node &a, const Node &b) {
        return a.dis < b.dis;
    });

    for (int i = 1; i <= m; ++i)
        a[i].val = a[i].dis - a[i - 1].dis + a[i - 1].val - 1;

    std::sort(a + 1, a + 1 + m, [](const Node &a, const Node &b) {
        return a.val == b.val ? a.dis > b.dis : a.val < b.val;
    });
    m = std::unique(a + 1, a + 1 + m) - a - 1;
    max = a[m].val;

#ifndef DEBUG
    for (int i = 1; i <= m; ++i)
        cerr << "(" << a[i].val << ", " << a[i].dis << ")\n";
    for (int i = 1; i <= 40; ++i) cerr << get(i) << ' ';
    cerr << '\n';
#endif

    cin >> q;
    for (int i = 1, n, k; i <= q; ++i) {
        cin >> n >> k;
        cout << BinarySearch(n, k) << '\n';
    }

    return 0;
}
