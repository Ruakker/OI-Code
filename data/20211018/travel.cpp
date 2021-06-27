#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
using std::cerr;
using std::cout;

#define inf 0x3f3f3f3f

const int N = 2e5 + 5;
int n;
std::vector<std::pair<int, std::pair<int, int>>> g[N];
struct info { int size, depth, top, son, fa, dfn, val; } p[N];

int dfnCounter;
int bel[N], a[N];  // bel[i] means the edge i is connected with node bel[i], so the dfn is p[bel[i]].dfn;
void dfs1(int u, int pre = 0) {
    p[u].size = 1, p[u].fa = pre, p[u].depth = p[pre].depth + 1;
    for (auto e : g[u]) {
        auto v = e.first, w = e.second.first, id = e.second.second;
        if (v == pre) continue;
        p[v].val = w, bel[id] = v;
        dfs1(v, u);
        p[u].size += p[v].size;
        if (!p[u].son || p[v].size > p[p[u].son].size) p[u].son = v;
    }
}
void dfs2(int u, int top) {
    p[u].top = top, p[u].dfn = ++dfnCounter;
    a[dfnCounter] = p[u].val;
    if (p[u].son) dfs2(p[u].son, top);
    for (auto e : g[u]) {
        auto v = e.first;
        if (v == p[u].fa || v == p[u].son) continue;
        dfs2(v, v);
    }
}

class SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define mid ((l + r) >> 1)
   private:
    struct node {
        int posiVal, negaVal, max, min;  // sum = posiVal - negaVal;
        node operator+(const node &Other) {
            return {
                this->posiVal + Other.posiVal,
                this->negaVal + Other.negaVal,
                std::max(this->max, Other.max),
                std::min(this->min, Other.min)
            };
        }
    } val[N << 2];

    bool tag[N << 2];
    int n;

    inline void pushDown(int l, int r, int k) {
        // cerr << k << '\n';
        if (!tag[k]) return;
        std::swap(val[lson].posiVal, val[lson].negaVal);
        val[lson].min = -val[lson].min, val[lson].max = -val[lson].max;
        std::swap(val[lson].min, val[lson].max);

        std::swap(val[rson].posiVal, val[rson].negaVal);
        val[rson].min = -val[rson].min, val[rson].max = -val[rson].max;
        std::swap(val[rson].min, val[rson].max);
        tag[k] = false;
        tag[lson] ^= true, tag[rson] ^= true;
    }
    inline void pushUp(int k) { val[k] = val[lson] + val[rson]; }

    void build(int l, int r, int k) {
        if (l >= r) {
            if (a[l] >= 0)
                val[k] = {a[l], 0, a[l], a[l]};
            else
                val[k] = {0, -a[l], a[l], a[l]};
            return;
        }
        build(l, mid, lson), build(mid + 1, r, rson);
        pushUp(k);
    }

    void modify(int pos, int w, int l, int r, int k) {
        if (l == pos && r == pos) {
            if (w >= 0)
                val[k] = {w, 0, w, w};
            else
                val[k] = {0, -w, w, w};
            return;
        }
        // cerr << "modify\n";
        pushDown(l, r, k);
        if (pos <= mid) modify(pos, w, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, w, mid + 1, r, rson);
        pushUp(k);
    }

    void reverse(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) {
            std::swap(val[k].posiVal, val[k].negaVal);
            val[k].min = -val[k].min, val[k].max = -val[k].max;
            std::swap(val[k].min, val[k].max);
            tag[k] ^= true;
            return;
        }
        // cerr << "reverse\n" << L << ' ' << R << ' ' << l << ' ' << r << '\n';
        pushDown(l, r, k);
        if (L <= mid) reverse(L, R, l, mid, lson);
        if (mid + 1 <= R) reverse(L, R, mid + 1, r, rson);
        pushUp(k);
    }

    long long querySum(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return val[k].posiVal - val[k].negaVal;
        pushDown(l, r, k);
        long long res = 0;
        if (L <= mid) res += querySum(L, R, l, mid, lson);
        if (mid + 1 <= R) res += querySum(L, R, mid + 1, r, rson);
        return res;
    }

    long long queryMax(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return val[k].max;
        pushDown(l, r, k);
        long long res = -inf;
        if (L <= mid)
            res = std::max(res, queryMax(L, R, l, mid, lson));
        if (mid + 1 <= R)
            res = std::max(res, queryMax(L, R, mid + 1, r, rson));
        return res;
    }

    long long queryMin(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return val[k].min;
        pushDown(l, r, k);
        long long res = inf;
        if (L <= mid)
            res = std::min(res, queryMin(L, R, l, mid, lson));
        if (mid + 1 <= R)
            res = std::min(res, queryMin(L, R, mid + 1, r, rson));
        return res;
    }
    
   public:
    inline void build(int _n) {
        n = _n;
        build(1, n, 1);
    }

    inline void modify(int pos, int val) { modify(pos, val, 1, n, 1); }

    inline void reverse(int l, int r) { reverse(l, r, 1, n, 1); }

    inline long long query(int l, int r, int tp) {
        if (tp == 0) return querySum(l, r, 1, n, 1);
        if (tp == 1) return queryMax(l, r, 1, n, 1);
        if (tp == -1) return queryMin(l, r, 1, n, 1);
        return 0;
    }
#undef mid
#undef lson
#undef rson
} T;

signed main() {
#ifndef DEBUG
    // freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        ++u, ++v;
        g[u].push_back(std::make_pair(v, std::make_pair(w, i))), g[v].push_back(std::make_pair(u, std::make_pair(w, i)));
    }

    dfs1(1);
    dfs2(1, 1);
#ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cerr << p[i].top << ' ';
    cerr << '\n';
    for (int i = 1; i <= n; ++i)
        cerr << p[i].depth << ' ';
    cerr << '\n';
    for (int i = 1; i <= n; ++i)
        cerr << p[i].dfn << ' ';
    cerr << '\n';
    for (int i = 1; i <= n; ++i)
        cerr << a[i] << ' ';
    cerr << '\n';
#endif
    T.build(n);

    int q;
    for (cin >> q; q--;) {
        char opt[5];
        int u, v;
        cin >> opt >> u >> v;
        if (opt[0] == 'C') T.modify(p[bel[u]].dfn, v);
        if (opt[0] == 'N') {
            ++u, ++v;
            for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
                if (p[p[u].top].depth < p[p[v].top].depth) std::swap(u, v);
                T.reverse(p[p[u].top].dfn, p[u].dfn);
            }
            if (p[u].depth < p[v].depth) std::swap(u, v);
            if (u != v)
                T.reverse(p[v].dfn + 1, p[u].dfn);
        }
        if (opt[0] == 'S') {
            long long res = 0;
            ++u, ++v;
            for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
                if (p[p[u].top].depth < p[p[v].top].depth) std::swap(u, v);
                res += T.query(p[p[u].top].dfn, p[u].dfn, 0);
            }
            if (p[u].depth < p[v].depth) std::swap(u, v);
            if (u != v)
                res += T.query(p[v].dfn + 1, p[u].dfn, 0);
            cout << res << '\n';
        }
        if (opt[0] == 'M' && opt[1] == 'A') {
            long long res = -inf;
            ++u, ++v;
            for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
                if (p[p[u].top].depth < p[p[v].top].depth) std::swap(u, v);
                res = std::max(res, T.query(p[p[u].top].dfn, p[u].dfn, 1));
            }
            if (p[u].depth < p[v].depth) std::swap(u, v);
            if (u != v)
                res = std::max(res, T.query(p[v].dfn + 1, p[u].dfn, 1));
            cout << res << '\n';
        }
        if (opt[0] == 'M' && opt[1] == 'I') {
            long long res = inf;
            ++u, ++v;
            for (; p[u].top != p[v].top; u = p[p[u].top].fa) {
                if (p[p[u].top].depth < p[p[v].top].depth) std::swap(u, v);
                res = std::min(res, T.query(p[p[u].top].dfn, p[u].dfn, -1));
            }
            if (p[u].depth < p[v].depth) std::swap(u, v);
            if (u != v)
                res = std::min(res, T.query(p[v].dfn + 1, p[u].dfn, -1));
            cout << res << '\n';
        }
    }

    return 0;
}
