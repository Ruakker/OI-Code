#include <bits/stdc++.h>
using namespace std;

signed main() {
    system("./gen > .in");
    system("./city-force < .in > .stdout");
    system("./city < .in > .myout");
    for (; !system("diff .stdout .myout"); ) {
        system("./gen > .in");
        system("./city-force < .in > .stdout");
        system("./city < .in > .myout");
        cout << "done" << endl;
    }
    return 0;
}
