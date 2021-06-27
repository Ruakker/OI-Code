/**
 * File              : P7114.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/24/2021
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
#define int long long
const unsigned int N = 1e7 + 5;
const unsigned int hashCount = 1;
const unsigned int hashBase[] = {23};
struct StringHash {
   private:
    unsigned long long hash[hashCount][N], base[hashCount][N];
    char str[N];
    int len;

   public:
    StringHash() { init(); }
    inline void init() {
        len = 0;
        for (unsigned i = 0; i < hashCount; ++i)
            hash[i][0] = 0, base[i][0] = 1;
    }
    inline void init(char* s) {
        int lens = strlen(s);
        init();
        for (int i = 0; i < lens; ++i)
            append(s[i]);
    }
    inline void append(char ch) {
        str[++len] = ch;
        for (unsigned i = 0; i < hashCount; ++i) {
            base[i][len] = base[i][len - 1] * hashBase[i];
            hash[i][len] = hash[i][len - 1] * hashBase[i] + ch;
        }
    }
    inline int getHash(int l, int r) {
        return hash[0][r] - hash[0][l - 1] * base[0][r - l + 1];
    }
    inline int length() { return len; }
    inline char* val() { return str + 1; }
    char& operator[](const int& pos) { return str[pos]; }
};
inline bool equal(std::vector<int> a, std::vector<int> b) {
    assert(a.size() == b.size());
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}
char ss[N];
StringHash s;
int n, ans;
int order[N], a[N], b[N], vis[N];
std::bitset<N> odd;
signed main() {
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        odd.reset(), ans = 0;
        memset(order, 0, sizeof order);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(vis, 0, sizeof vis);
        cin >> (ss + 1);
        s.init(ss + 1);
        int n = s.length();
        for (int i = 1; i <= n; ++i) {
            order[i] = s[i] - 'a' + 1;
            odd.flip(order[i]);
            if (odd[order[i]])
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1] - 1;
        }
        odd.reset();
        for (int i = n; i >= 1; --i) {
            odd.flip(order[i]);
            if (odd[order[i]])
                b[i] = b[i + 1] + 1;
            else
                b[i] = b[i + 1] - 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = a[i - 1]; j <= 26; ++j)
                vis[j]++;
            for (int j = i; j < n && s.getHash(1, i) == s.getHash(j - i + 1, j);
                 j += i)  // v[i] == v[j] - v[j - i] * l[i]
                ans += vis[b[j + 1]];
        }
        cout << ans << endl;
    }
    return 0;
}