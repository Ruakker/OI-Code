#include <bits/stdc++.h>
using namespace std;
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
    };

    std::vector<node> val;
    std::vector<bool> tag;
    int n;

    inline void pushDown(int l, int r, int k) {
        if (!tag[k]) return;
        std::swap(val[k].posiVal, val[k].negaVal);
        std::swap(val[k].min, val[k].max);
        tag[k] = false;
        tag.flip(lson), tag.flip(rson);
    }
    inline void pushUp(int k) { val[k] = val[lson] + val[rson]; }

    void build(int l, int r, int k) {
        if (l >= r) {
            if (a[l] >= 0)
                val[k] = {a[l], 0, a[l], a[l]};
            else
                val[k] = {0, a[l], a[l], a[l]};
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
                val[k] = {0, w, w, w};
            return;
        }
        pushDown(l, r, k);
        if (pos <= mid) modify(pos, w, l, mid, lson);
        if (mid + 1 <= pos) modify(pos, w, mid + 1, r, rson);
        pushUp(k);
    }

    void reverse(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) {
            std::swap(val[k].posiVal, val[k].negaVal);
            std::swap(val[k].min, val[k].max);
            tag.flip(k);
        }
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
        _n += 5;
        val.resize(_n << 2), tag.resize(_n << 2);
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
