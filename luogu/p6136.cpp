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
        inline void calc() {
            size = 1 + (l != nullptr ? l->size : 0) + (r != nullptr ? r->size : 0);
        }
    };
    int n;
    Node *root;


    Node *merge(Node *u, Node *v) {
        if (u == nullptr) return v;
        if (v == nullptr) return u;

        if (u->weight < v->weight) {
            u->r = merge(u->r, v);
            u->calc();
            return u;
        } else {
            v->l = merge(u, v->l);
            v->calc();
            return v;
        }
    }
    std::pair<Node *, Node *> split(Node *p, T w) {
        if (p == nullptr) return {nullptr, nullptr};

        if (w < p->val) {
            auto o = split(p->l, w);
            p->l = o.second;
            p->calc();
            return {o.first, p};
        } else {
            auto o = split(p->r, w);
            p->r = o.first;
            p->calc();
            return {p, o.second};
        }
    }
    Node *kth(Node *p, int k) {
        assert(p != nullptr);
        if (p->size < k)
            cerr << p->size << ' ' << k << '\n';
        assert(p->size >= k);
        while (k != (p->l == nullptr ? 0 : p->l->size) + 1)
            if (p->l != nullptr && k <= p->l->size)
                p = p->l;
            else {
                k -= (p->l == nullptr ? 0 : p->l->size) + 1;
                assert(p->r != nullptr);
                p = p->r;
            }
        return p;
    }

    void destruct(Node *p) {
        if (p == nullptr) return;
        destruct(p->l), destruct(p->r);
        delete p;
    }

   public:
    FhqTreap() { root = nullptr; }
    ~FhqTreap() { destruct(root); }
    inline void insert(T w) {
        auto o = split(root, w);
        root = merge(merge(o.first, new Node(w)), o.second);
    }

    inline void erase(T w) {
        auto o1 = split(root, w - 1);
        auto o2 = split(o1.second, w);
        delete o2.first;
        o2.first = nullptr;
        root = merge(o1.first, o2.second);
    }

    inline int find(T w) {
        auto o = split(root, w - 1);
        if (o.first == nullptr) return 1;
        int res = o.first->size + 1;
        root = merge(o.first, o.second);
        return res;
    }

    inline const T at(int pos) { return kth(root, pos)->val; }
    inline const T operator[](int pos) { return at(pos); }

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
    freopen(".in", "r", stdin);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;// >> m;

    // for (int i = 1, w; i <= n; ++i) {
    //     cin >> w;
    //     T.insert(w);
    // }

    for (int i = 1, opt, u; i <= n; ++i) {
        cin >> opt >> u;
        // u ^= last;

        if (opt == 1) T.insert(u);
        if (opt == 2) T.erase(u);
        if (opt == 3) ans ^= (last = T.find(u));
        if (opt == 4) ans ^= (last = T[u]);
        if (opt == 5) ans ^= (last = T.getpre(u));
        if (opt == 6) ans ^= (last = T.getsuc(u));
        if (opt >= 3) cout << last << '\n';
        cout.flush();
    }

    // cout << ans << '\n';
    return 0;
}
