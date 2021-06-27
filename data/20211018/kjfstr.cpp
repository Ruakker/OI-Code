#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
using std::cerr;
using std::cout;

const int N = 2e5 + 5, hashBase = 233, P1 = 625850059, P2 = 998244353;

long long base[2][N];

class SegmentTree {
#define lson (k -> l)
#define rson (k -> r)
#define mid ((l + r) >> 1)
   private:
    struct Node {
        Node *l, *r;
        long long hash[2];
        Node(void) { l = r = nullptr; }
        bool operator==(const Node& oth) const {
            return this->hash[0] == oth.hash[0] && this->hash[1] == oth.hash[1];
        }
    };

    std::vector<Node*> roots;
    int n;

    void newRoot() { roots.push_back(nullptr); }
    void pushUp(int l, int r, Node* k) {
        k->hash[0] = (lson->hash[0] * base[0][r - mid] + rson->hash[0]) % P1;
        k->hash[1] = (lson->hash[1] * base[1][r - mid] + rson->hash[1]) % P2;
    }
    void build(char s[], int l, int r, Node*& k) {
        k = new Node();
        if (l == r) return k->hash[0] = k->hash[1] = s[l] - 'a' + 1, void();
        build(s, l, mid, lson), build(s, mid + 1, r, rson);
        pushUp(l, r, k);
    }
    void update(int pos, char w, int l, int r, Node*& k, Node*& old) {
        k = new Node(), *k = *old;
        if (l == r) return k->hash[0] = k->hash[1] = w - 'a' + 1, void();
        if (pos <= mid) update(pos, w, l, mid, lson, old->l);
        if (mid + 1 <= pos) update(pos, w, mid + 1, r, rson, old->r);
        pushUp(l, r, k);
    }
    bool compare(Node* root1, Node* root2, int l, int r) {
        if (*root1 == *root2) return false;
        if (l == r) return root1->hash[0] < root2->hash[0];
        if (*root1->l == *root2->l)
            return compare(root1->r, root2->r, mid + 1, r);
        return compare(root1->l, root2->l, l, mid);
    }

   public:
    SegmentTree() { roots.push_back(nullptr); }
    void build(int _n, char s[]) {
        n = _n;
        newRoot();
        build(s, 1, n, roots.back());
    }
    void update(int oldVer, int p, char v) {
        newRoot();
        update(p, v, 1, n, roots.back(), roots[oldVer]);
    }
    bool compare(int ver1, int ver2) {
        return compare(roots[ver1], roots[ver2], 1, n);
    }
    bool equal(int ver1, int ver2) { return *roots[ver1] == *roots[ver2]; }

#undef lson
#undef rson
#undef mid
} T;

char s[N];
int n, m;
int a[N];

bool cmp(int x, int y) { return T.compare(x, y) || (x < y && T.equal(x, y)); }

void init() {
    base[0][0] = base[1][0] = 1;
    for (int i = 1; i <= n; i++)
        base[0][i] = base[0][i - 1] * hashBase % P1,
        base[1][i] = base[1][i - 1] * hashBase % P2;
}

signed main() {
#ifndef DEBUG
    freopen("kjfstr.in", "r", stdin), freopen("kjfstr.out", "w", stdout);
#endif

    cin >> (s + 1);
    n = strlen(s + 1);
    init();
    cin >> m;
    T.build(n, s);
    for (int i = 2; i <= m; i++) {
        int last, p;
        char c;
        cin >> last >> p >> c;
        T.update(last, p, c);
    }
    for (int i = 1; i <= m; i++) a[i] = i;
    std::sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
