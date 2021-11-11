#include <bits/stdc++.h>
using std::cerr;

signed main() {
    for (int i = 1;; ++i) {
        system("./generator");
        system("./reverse < data.in > data.out");
        if (system("diff -BZ data.out data.ans")) {
            cerr << "error" << '\n';
            return 1;
        }
        cerr << i << " done\n";
    }
    return 0;
}
