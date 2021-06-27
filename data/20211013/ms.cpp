#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

const int N = 2005;
int n, m, tag[N][N], h[N], a[N], ans;

std::stack<int> st;
void add(int r, int c, int th){
    int tc = c;
    for (; h[st.top()] > th;){
        tc = st.top();
        ans = std::max(ans, (c - tc) * h[tc]);
        st.pop();
    }
    if (th > 0 && h[st.top()] < th) st.push(tc), h[tc] = th;
}

signed main() {
#ifndef DEBUG
    freopen("ms.in", "r", stdin), freopen("ms.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    st.push(0), h[0] = 0;
    int T;
    for (cin >> T; T--;){
        memset(a, 0, sizeof a), memset(tag, 0, sizeof tag);
        cin >> n >> m;
        ans = m;
        int bkup;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                bkup = a[j];
                cin >> a[j];
                tag[i][j] = a[j] >= bkup ? tag[i - 1][j] + 1 : 1;
                add(i, j, tag[i][j]);
            }
            add(i, m + 1, 0);
        }
        cout << ans << endl;
    }
    return 0;
}
