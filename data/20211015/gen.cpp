#include<bits/stdc++.h>
using namespace std;
std::random_device seed;
std::mt19937 gen(seed());
std::uniform_int_distribution<int> rnd(1, 15);
signed main() {
    std::vector<int> a = { rnd(gen), rnd(gen), rnd(gen) };
    std::sort(a.begin(), a.end());
    cout << a[0] << ' ' << a[2] << ' ' << a[1] << endl;
    return 0;
}
