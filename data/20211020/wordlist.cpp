#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 5e4 + 5;

#define int long long

std::string s[N];
int n, len, l, r;
std::map<std::string, int> mp;
std::pair<std::string, int> ans1, ans2;

std::pair<bool, std::pair<std::string, int>> check1(int k) {
    mp.clear();
    for (int i = 1; i <= n; ++i)
        if (k <= (int)s[i].size())
            mp[s[i].substr(0, k)]++;

    for (auto v : mp)
         if (v.second > 1)
             return std::make_pair(true, v);
    return std::make_pair(false, std::make_pair("", 0));
}

std::pair<bool, std::pair<std::string, int>> check2(int k) {
    mp.clear();
    for (int i = 1; i <= n; ++i)
        if (k <= (int)s[i].size())
            mp[s[i].substr(s[i].size() - k, k)]++;

    for (auto v : mp)
         if (v.second > 1)
             return std::make_pair(true, v);
    return std::make_pair(false, std::make_pair("", 0));
}

signed main() {
    //freopen("stdin", "r", stdin);
#ifndef DEBUG
    freopen("wordlist.in", "r", stdin), freopen("wordlist.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        len = std::max(len, (int)s[i].size());
    }

    l = 0, r = len + 1;
    for (; l + 1 < r;) {
        int mid = (l + r) >> 1;
        auto status = check1(mid);
        if (status.first)
            l = mid, ans1 = status.second;
        else
            r = mid;
    }

    l = 0, r = len + 1;
    for (; l + 1 < r;) {
        int mid = (l + r) >> 1;
        auto status = check2(mid);
        if (status.first)
            l = mid, ans2 = status.second;
        else
            r = mid;
    }

    cout << ans1.first << ' ' << 1ll * ans1.second * (ans1.second - 1) / 2 << '\n';
    cout << ans2.first << ' ' << 1ll * ans2.second * (ans2.second - 1) / 2 << '\n';

    return 0;
}
