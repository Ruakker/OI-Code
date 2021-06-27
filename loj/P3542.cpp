#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 2e5 + 5;
int n, m1, m2, ans;
std::pair<int, int> a[N], b[N];
std::vector<int> disc1, disc2;
int ans1[N], ans2[N];

signed main() {
    freopen("airport.in", "r", stdin);
    freopen("airport.out", "w", stdout);
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; ++i) {
        cin >> a[i].first >> a[i].second;
        disc1.push_back(a[i].first), disc1.push_back(a[i].second);
    }
    for (int i = 1; i <= m2; ++i) {
        cin >> b[i].first >> b[i].second;
        disc2.push_back(b[i].first), disc2.push_back(b[i].second);
    }

    std::sort(disc1.begin(), disc1.end()), std::sort(disc2.begin(), disc2.end());
    auto disc1End = std::unique(disc1.begin(), disc1.end());
    auto disc2End = std::unique(disc2.begin(), disc2.end());
    for (int i = 1; i <= m1; ++i) {
        a[i].first = std::lower_bound(disc1.begin(), disc1End, a[i].first) - disc1.begin() + 1;
        a[i].second = std::lower_bound(disc1.begin(), disc1End, a[i].second) - disc1.begin() + 1;
    }
    for (int i = 1; i <= m2; ++i) {
        b[i].first = std::lower_bound(disc2.begin(), disc2End, b[i].first) - disc2.begin() + 1;
        b[i].second = std::lower_bound(disc2.begin(), disc2End, b[i].second) - disc2.begin() + 1;
    }

    std::sort(a + 1, a + 1 + m1);
    std::sort(b + 1, b + 1 + m2);

    static std::priority_queue<int, std::vector<int>, std::less<int>> ava;
    static std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> timer;

    for (int i = 1; i <= n; ++i)
        ava.push(i);
    for (int i = 1; i <= m1; ++i) {
        for (; !timer.empty() && timer.top().first < a[i].second; timer.pop())
            ;
        int cur = ava.top();
        ava.pop();

    }



    for (int i = 0; i <= n; ++i)
        ans = std::max(ans, ans1[i] + ans2[n - i]);
    cout << ans << '\n';
    return 0;
}

