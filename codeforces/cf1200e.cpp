/**
 * File              : CF1200E.cpp
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

int n;
const int N = 1e6 + 5;
std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
const int hashCount = 2;
const unsigned int hashBase[] = {rnd() % 123, rnd() % 321};
const unsigned int hashMod[] = {1'000'000'009, 998'244'353};
struct StringHash {
    StringHash() { init(); }
    long long hash[hashCount][N], base[hashCount][N];
    char s[N];
    int len;
    inline void init() {
        len = 0;
        for (int i = 0; i < hashCount; ++i)
            hash[i][0] = 0, base[i][0] = 1;
    }
    inline void append(char ch) {
        s[++len] = ch;
        for (int i = 0; i < hashCount; ++i) {
            base[i][len] = base[i][len - 1] * hashBase[i] % hashMod[i];
            hash[i][len] = (hash[i][len - 1] * hashBase[i] + ch) % hashMod[i];
        }
    }
    inline int length() { return len; }
    inline std::vector<int> getHash(int l, int r) {
        std::vector<int> res;
        res.resize(hashCount);
        for (int i = 0, t; i < hashCount; ++i) {
            t = (hash[i][r] - hash[i][l - 1] * base[i][r - l + 1]) % hashMod[i];
            (t += hashMod[i]) %= hashMod[i];
            res[i] = t;
        }
        return res;
    }
};
StringHash s, t;
char S[N];
inline bool check(std::vector<int> a, std::vector<int> b) {
    for (unsigned i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (; n--;) {
        t.init();
        cin >> (S + 1);
        int lenS = strlen(S + 1);
        for (int i = 1; i <= lenS; ++i)
            t.append(S[i]);
        int pos = std::min(s.length(), t.length());
        for (; pos >= 0; --pos)
            if (check(s.getHash(s.length() - pos + 1, s.length()),
                      t.getHash(1, pos)))
                break;
        pos = std::max(0, pos);
        for (int i = pos + 1; i <= lenS; ++i)
            s.append(S[i]);
    }
    cout << (s.s + 1) << endl;
    return 0;
}