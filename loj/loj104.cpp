/**
 * File              : LOJ104.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/28/2021
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
const int N = 1e5 + 5;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
struct Treap {
    struct Node {
        Node() { son[0] = son[1] = nullptr; }
        Node *son[2];               // 0: left, 1: right
        int val, key, equal, size;  // val: the value, key: the random value
    };
} T;
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << endl;
    return 0;
}