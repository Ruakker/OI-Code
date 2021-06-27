#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {1, 2, 3};
    int b = &a[2];
    cout << *b << '\n';
    return 0;
}
