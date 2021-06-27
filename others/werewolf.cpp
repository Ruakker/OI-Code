#include <bits/stdc++.h>
std::string p6[] = {
    "狼",     "隐狼", "守卫", "骑士", "女巫", "猎人",
    "预言家", "盗贼", "民",   "民",   "民",   "民",
};
std::string p7[] = {
    "狼",   "隐狼", "守卫", "骑士", "女巫", "猎人", "预言家",
    "盗贼", "民",   "民",   "民",   "民",   "民",   "民",
};
std::string p8[] = {
    "狼", "狼", "狼", "预言家", "猎人", "女巫", "民", "民",
};
std::string p9[] = {
    "狼", "狼", "狼", "预言家", "猎人", "女巫", "民", "民", "民",
};
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    int n;
    std::cin >> n;
    if (n == 6) {
        std::shuffle(p6, p6 + 12, rnd);
        for (int i = 0; i < 6; ++i)
            std::cout << i + 1 << ": " << p6[i * 2] << ' ' << p6[i * 2 + 1]
                      << '\n';
    }
    if (n == 7) {
        std::shuffle(p7, p7 + 14, rnd);
        for (int i = 0; i < 7; ++i)
            std::cout << i + 1 << ": " << p7[i * 2] << ' ' << p7[i * 2 + 1]
                      << '\n';
    }
    if (n == 8) {
        std::shuffle(p8, p8 + 8, rnd);
        for (int i = 0; i < 8; ++i)
            std::cout << i + 1 << ": " << p8[i] << '\n';
    }
    if (n == 9) {
        std::shuffle(p9, p9 + 9, rnd);
        for (int i = 0; i < 9; ++i)
            std::cout << i + 1 << ": " << p9[i] << '\n';
    }
    return 0;
}
/*
1.fjz 盗贼 守卫
2.wbh 女巫 猎人
3.xyt 骑士 隐狼
4.dzk 民 民
5.xdx 狼 民
6.jsq 预言家 民
*/