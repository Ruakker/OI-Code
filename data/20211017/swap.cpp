#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
using std::cerr;
using std::cout;

#define inf 0x3f3f3f3f

const int N = 1e6 + 5;

int a[N], pos[N];
int n, m;

struct node {
    node() {}
    node(int x) { min = max = l = r = x, val = len = 1; }
    int min, max, val, len, l, r;
    inline node operator+(const node &Other) {
        node res, a = *this, b = Other;
        // assert(this->l <= Other.r);
        if (a.l > b.r) std::swap(a, b);
        res.l = a.l, res.r = b.r, res.len = a.len + b.len;
        res.min = std::min(a.min, b.min);
        res.max = std::max(a.max, b.max);
        if (a.val == b.len && b.l > a.r)
            res.val = a.val + b.val;
        else
            res.val = a.val;
        return res;
    }
} t[N << 2];
class SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define mid ((l + r) >> 1)
   private:
    inline void pushUp(int k) { t[k] = t[lson] + t[rson]; }
    inline void pushDown(int l, int r, int k) {}  // empty
    void build(int l, int r, int k) {
        if (l >= r) {
            t[k] = node(a[l]);
            return;
        }
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(k);
    }

    void modify(int pos, int val, int l, int r, int k) {
        cerr << pos << ' ' << l << ' ' << r << ' ' << k << '\n';
        if (pos == l && pos == r) {
            t[k] = node(val);
            return;
        }
        pushDown(l, r, k);
        if (pos <= mid) modify(pos, val, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, val, mid + 1, r, rson);
        pushUp(k);
    }

    node query(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return t[k];
        pushDown(l, r, k);
        if (L <= mid && mid + 1 <= R)
            return query(L, R, l, mid, lson) + query(L, R, mid + 1, r, rson);
        else if (L <= mid)
            return query(L, R, l, mid, lson);
        else
            return query(L, R, mid + 1, r, rson);
    }
    struct info {
        int l, r, k;
    };
    std::queue<info> st;
    void find(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return st.push({l, r, k}), void();
        if (L <= mid) find(L, R, l, mid, lson);
        if (mid + 1 <= R) find(L, R, mid + 1, r, rson);
    }
    int dfs(int u, int l, int r, int k) {
        if (l == r) return t[k].max;
        if (t[lson].max > u)
            return dfs(u, l, mid, lson);
        else
            return dfs(u, mid + 1, r, rson);
    }

   public:
    inline void build(int n) { build(1, n, 1); }
    inline void modify(int pos, int val) { modify(pos, val, 1, n, 1); }
    inline node query(int l, int r) { return query(l, r, 1, n, 1); }
    int Get(int u, int l, int r) {
        for (; !st.empty(); st.pop())
            ;
        find(l, r, 1, n, 1);
        for (; !st.empty(); st.pop())
            if (t[st.front().k].max > u)
                return dfs(u, st.front().l, st.front().r, st.front().k);
        return 0;
    }
#undef lson
#undef rson
#undef mid
} T;
// using SegmentTree::node;

signed main() {
#ifndef DEBUG
    freopen("swap.in", "r", stdin), freopen("swap.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    T.build(n);

    for (int l, r; m--;) {
        cin >> l >> r;
        node res = T.query(l, r);
        if (res.val == r - l + 1) {
            cout << "-1\n";
            continue;
        }
        res = T.query(l + res.val, r);
        int x = res.min, y = T.Get(x, l, r);
        std::swap(a[pos[x]], a[pos[y]]), std::swap(pos[x], pos[y]);
        cerr << "x: " << x << '\n' << "y: " << y << '\n';
        assert(pos[x]), assert(pos[y]);
        T.modify(pos[x], x), T.modify(pos[y], y);
        cout << pos[x] << ' ' << pos[y] << '\n';
    }
    return 0;
}
