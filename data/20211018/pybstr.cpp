#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
using std::cerr;
using std::cout;

bool memst;
const int N = 5e5 + 5;
char s[N];
int n, m;

class SegmentTree {
#define lson (k << 1)
#define rson (k << 1 | 1)
#define mid ((l + r) >> 1)

   private:
    struct Node {
        Node() { memset(f, 0, sizeof f); }
        Node(char w, int cnt) {
            memset(f, 0, sizeof f);
            // (0w0)
            if (w == '(') f[0][0] = cnt;
            if (w == '0') f[1][1] = cnt;
            if (w == 'w') f[2][2] = cnt;
            if (w == '0') f[3][3] = cnt;
            if (w == ')') f[4][4] = cnt;
        }
        unsigned int f[5][5];
        Node operator+(const Node &Other) {
            Node res;
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 5; ++j) {
                    res.f[i][j] = this->f[i][j] + Other.f[i][j];
                    for (int k = i; k < j; ++k)
                        res.f[i][j] += this->f[i][k] * Other.f[k + 1][j];
                }
            return res;
        }
        Node& operator+=(const Node &Other) { return *this = *this + Other; }
    } val[N << 2];
    char tag[N << 2];

    inline void pushDown(int l, int r, int k) {
        if (!tag[k]) return;
        tag[lson] = tag[rson] = tag[k];
        val[lson] = Node(tag[k], mid - l + 1);
        val[rson] = Node(tag[k], r - mid);
        tag[k] = 0;
    }

    inline void pushUp(int k) { val[k] = val[lson] + val[rson]; }

    void modify(int L, int R, char w, int l, int r, int k) {
        if (L <= l && r <= R) {
            val[k] = Node(w, r - l + 1);
            tag[k] = w;
            return;
        }
        pushDown(l, r, k);
        if (L <= mid) modify(L, R, w, l, mid, lson);
        if (mid + 1 <= R) modify(L, R, w, mid + 1, r, rson);
        pushUp(k);
    }

    Node query(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) return val[k];
        pushDown(l, r, k);
        Node res;
        if (L <= mid) res += query(L, R, l, mid, lson);
        if (mid + 1 <= R) res += query(L, R, mid + 1, r, rson);
        return res;
    }

   public:
    inline void modify(int l, int r, char w) { modify(l, r, w, 1, n, 1); }
    inline void modify(int pos, char w) { modify(pos, pos, w, 1, n, 1); }
    inline unsigned int query(int l, int r) { return query(l, r, 1, n, 1).f[0][4]; }

#undef lson
#undef rson
#undef mid
} T;

long long aa[10000000];
bool memed;

signed main() {
#ifndef DEBUG
    freopen("data.in", "r", stdin), freopen("data.out", "w", stdout);
#endif
    cerr << abs(&memst - &memed) / 1024. /1024. << '\n';
    cin >> n >> m;
    cin >> (s + 1);
    
    for (int i = 1; i <= n; ++i) T.modify(i, s[i]);

    for (char opt; m--;) {
        cin >> opt;
        if (opt == 'A') {
            int u;
            char v;
            cin >> u >> v;
            T.modify(u, v);
        }
        if (opt == 'B') {
            int l, r;
            char v;
            cin >> l >> r >> v;
            T.modify(l, r, v);
        }
        if (opt == 'C') {
            int l, r;
            cin >> l >> r;
            cout << T.query(l, r) << '\n';
        }
    }

    return 0;
}
