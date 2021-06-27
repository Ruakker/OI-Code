#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a = {{ 10, 20 }, { 20, 10 }, { 30, 20 }};
int main() {
    for (auto [i, j] : a)
        cout << i << ' ' << j << endl;
    return 0;
}
