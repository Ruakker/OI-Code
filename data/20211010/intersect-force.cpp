#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

bool st;
const int N = 500, M = 1e5 + 5;
std::bitset<M> vis[N];
std::set<std::map<int, int>> rec;  // map[0] means the answer
bool ed;

inline void init() {
    const int n = 50, m = 1e5;
    for (int i = 1; i <= n; ++i)
        vis[n].reset();
    std::map<int, int> tmp;
    tmp[1] = 1, tmp[0] = 0;
    rec.insert(tmp);
    for (int i = 2; i <= n; ++i) {
        cerr << i << endl;
        std::set<std::map<int, int>> cache;
        for (auto cur:rec) {
            for (auto e:cur)
                if (e.first > 0 && e.second > 0) {
                    int bkup = cur[0];
                    cur[0] += i - e.first - 1;
                    cur[e.first]--, cur[e.first + 1]++;
                    vis[i][cur[0]] = true;
#ifdef DEBUG
                    if (i == 3 && cur[0] == 4) {
                        cerr << "--------------+" << endl;
                        for (auto p:cur)
                            cerr << p.first << ' ' << p.second << endl;
                        cerr << e.first << endl;
                        cerr << "---------------" << endl;
                    }
                    //
                    int sum = 0;
                    for (auto e:cur)
                        if (e.first > 0 && e.second > 0)
                            sum += e.first * e.second;
                    if (sum != i) {
                        cerr << "--------------?" << endl;
                        cerr << i << endl;
                        for (auto p:cur)
                            cerr << p.first << ' ' << p.second << endl;
                        cerr << "---------------" << endl;
                    }
#endif
                    cache.insert(cur);
                    cur[0] = bkup;
                    cur[e.first]++, cur[e.first + 1]--;
                    if (!cur[e.first + 1]) cur.erase(e.first + 1);
                }
            int bkup = cur[0];
            cur[0] += i - 1;
            cur[1]++;
            vis[i][cur[0]] = true;
#ifdef DEBUG
            if (i == 2 && cur[0] == 2) {
                cerr << "--------------+" << endl;
                for (auto p:cur)
                    cerr << p.first << ' ' << p.second << endl;
                cerr << "---------------" << endl;
            }
            //
            int sum = 0;
            for (auto e:cur)
                if (e.first > 0 && e.second > 0)
                    sum += e.first * e.second;
            if (sum != i) {
                cerr << "--------------?" << endl;
                cerr << i << endl;
                for (auto p:cur)
                    cerr << p.first << ' ' << p.second << endl;
                cerr << "---------------" << endl;
            }
#endif
            cache.insert(cur);
            cur[0] = bkup;
            cur[1]--;
        }
        rec.clear();
        rec = cache;
    }
}

signed main() {
#ifndef DEBUG
    freopen("intersect.in", "r", stdin), freopen("intersect.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
#ifdef DEBUG
    cerr << std::fixed << abs(&st - &ed) / 1024. / 1024. <<endl;
#endif

    init();
#ifdef DEBUG
    freopen("data.txt", "w", stderr);
    for (int i = 1; i <= 50; ++i) {
        cerr << "{";
        for (int j = 1; j <= 1e5; ++j) {
            if (vis[i][j]) cerr << j << ',';
        }
        cerr << "},";
    }
    fclose(stderr);
    cerr << "Done" << endl;
#endif
    int T;
    cin >> T;
    for (int n, m; T--; ) {
        cin >> n >> m;
        if (vis[n][m] || !m) 
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}

