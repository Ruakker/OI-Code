/**
 * File              : LOJ103.cpp
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
std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
const unsigned int N = 1e6 + 5;
const unsigned int hashCount = 2;
const unsigned int hashBase[] = {rnd() % 123, rnd() % 321};
const unsigned int hashMod[] = {1'000'000'009, 998'244'353};
struct StringHash {
   private:
    long long hash[hashCount][N], base[hashCount][N];
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
        for (unsigned i = 0; i < hashCount; ++i)
            hash[i][0] = 0, base[i][0] = 1;
        for (int i = 0; i < lens; ++i)
            append(s[i]);
    }
    inline void append(char ch) {
        str[++len] = ch;
        for (int i = 0; i < hashCount; ++i) {
            base[i][len] = base[i][len - 1] * hashBase[i] % hashMod[i];
            hash[i][len] = (hash[i][len - 1] * hashBase[i] + ch) % hashMod[i];
        }
    }
    inline std::vector<int> getHash(int l, int r) {
        std::vector<int> res;
        res.resize(hashCount);
        for (unsigned i = 0, t; i < hashCount; ++i) {
            t = (hash[i][r] - hash[i][l - 1] * base[i][r - l + 1]) % hashMod[i];
            (t += hashMod[i]) %= hashMod[i];
            res[i] = t;
        }
        return res;
    }
    inline int length() { return len; }
    inline char* val() { return str + 1; }
};
StringHash s, t;
int ans;
char ss[N];
inline bool equal(std::vector<int> a, std::vector<int> b) {
    assert(a.size() == b.size());
    for (int i = 0; i < (int)a.size(); ++i)
        if (a.at(i) != b.at(i)) return false;
    return true;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> ss;
    s.init(ss);
    cin >> ss;
    t.init(ss);
    for (int i = 1; i <= (int)(s.length() - t.length() + 1); ++i)
        if (equal(s.getHash(i, i + t.length() - 1), t.getHash(1, t.length())))
            ++ans;
    cout << ans << endl;
    return 0;
}