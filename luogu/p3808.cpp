#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 1e6 + 5;
int n;
std::string s;

/* ACAM - AC Automaton */
class AhoCorasickAutomaton {
    int c[N][26], w[N], fail[N], cnt;
    std::queue<int> Q;

   public:
    void insert(std::string s) {
        int len = s.length() - 1, cur = 0;
        for (int i = 1; i <= len; ++i) {
            int u = s[i] - 'a';
            if (c[cur][u] == 0) c[cur][u] = ++cnt;
            cur = c[cur][u];
        }
        w[cur]++;
    }

    void build() {
        for (; !Q.empty(); Q.pop());
        for (int i = 0; i < 26; ++i)
            if (c[0][i] != 0) fail[c[0][i]] = 0, Q.push(c[0][i]);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < 26; ++i)
                if (c[u][i])
                    fail[c[u][i]] = c[fail[u]][i], Q.push(c[u][i]);
                else
                    c[u][i] = c[fail[u]][i];
        }
    }

    int query(std::string s) {
        int len = s.length() - 1, cur = 0, res = 0;
        for (int i = 1; i <= len; ++i) {
            int u = s[i] - 'a';
            cur = c[cur][u];
            for (int v = cur; v && ~w[v]; v = fail[v]) {
                res += w[v];
                w[v]--;
            }
        }
        return res;
    }
} acam;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        acam.insert('~' + s);
    }

    acam.build();

    cin >> s;
    cout << acam.query('~' + s) << '\n';

    return 0;
}
