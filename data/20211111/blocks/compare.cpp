#include <bits/stdc++.h>
using std::cerr;

signed main() {
    for (int i = 1;; ++i) {
        system("./generator.py");
        system("./blocks < blocks.in > blocks.out");
        system("./blocks-force < blocks.in > blocks-force.out");
        if (system("diff -BZ blocks.out blocks-force.out")) {
            cerr << "error" << '\n';
            return 1;
        }
        cerr << i << " done\n";
    }
    return 0;
}
