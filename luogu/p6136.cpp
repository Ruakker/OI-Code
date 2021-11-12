#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 2e6 + 5;
int n, m, ans, last;

std::random_device seed;
std::mt19937 rnd(seed());

template <typename T>
class FhqTreap {
    struct Node {
        Node(T w = 0) {
            size = 1, weight = rnd(), val = w;
            l = r = nullptr;
        }
        int size, weight;
        T val;
        Node *l, *r;
    };
    int n;
    Node *root;

    inline void calc(Node *u) {
        u->size = (u->l != nullptr ? u->l->size : 0) + (u->r != nullptr ? u->r->size + 1 : 0);
    }

    Node *merge(Node *u, Node *v) {
        if (u == nullptr) return v;
        if (v == nullptr) return u;

        if (u->weight < v->weight) {
            u->r = merge(u->r, v);
            calc(u);
            return u;
        } else {
            v->l = merge(u, v->l);
            calc(v);
            return v;
        }
    }
    std::pair<Node *, Node *> split(Node *u, T w) {
        if (u == nullptr) return {nullptr, nullptr};

        if (w < u->val) {
            auto o = split(u->l, w);
            u->l = o.second;
            calc(u);
            return {o.first, u};
        } else {
            auto o = split(u->r, w);
            u->r = o.first;
            calc(u);
            return {u, o.second};
        }
    }
    Node *kth(Node *u, int k) {
        assert(root != nullptr);
        assert(root->size < k);
        while (k != u->l->size + 1) {
            if (k <= u->l->size)
                u = u->l;
            else {
                k -= u->l->size + 1;
                u = u->r;
            }
        }
        return u;
    }

   public:
    inline void insert(T w) {
        auto o = split(root, w);
        root = merge(merge(o.first, new Node(w)), o.second);
    }

    inline void erase(T w) {
        auto o1 = split(root, w - 1);
        auto o2 = split(o1.second, w);
        delete o2.first;
        root = merge(o1.first, o2.second);
    }

    inline int rank(T w) {
        auto o = split(root, w - 1);
        int res = o.first->size + 1;
        root = merge(o.first, o.second);
        return res;
    }

    inline T at(int pos) { return kth(root, pos)->val; }
    inline T operator[](int pos) { return at(pos); }

    inline T getpre(T w) {
        auto o = split(root, w - 1);
        T res = kth(o.first, o.first->size)->val;
        root = merge(o.first, o.second);
        return res;
    }
    inline T getsuc(T w) {
        auto o = split(root, w);
        T res = kth(o.second, 1)->val;
        root = merge(o.first, o.second);
        return res;
    }
};

FhqTreap<int> T;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1, w; i <= n; ++i) {
        cin >> w;
        T.insert(w);
    }

    for (int i = 1, opt, u; i <= m; ++i) {
        cin >> opt >> u;
        u ^= last;

        if (opt == 1) T.insert(u);
        if (opt == 2) T.erase(u);
        if (opt == 3) ans ^= (last = T.rank(u));
        if (opt == 4) ans ^= (last = T[u]);
        if (opt == 5) ans ^= (last = T.getpre(u));
        if (opt == 6) ans ^= (last = T.getsuc(u));
    }

    cout << ans << '\n';
    return 0;
}
