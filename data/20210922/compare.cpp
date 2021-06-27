#include <bits/stdc++.h>
#include <windows.h>

signed main() {
    for (;;) {
        system(".\\generator > data.in");
        system(".\\a < data.in > a.out");
        system(".\\b < data.in > b.out");
        if (system("fc a.out b.out")) {
            system("pause");
            break;
        }
    }
    return 0;
}