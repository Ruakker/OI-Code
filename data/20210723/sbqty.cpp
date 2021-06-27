/*
	Author: Ruakker
	Date: 2021-07-23 08:25:19
	LastEditTime: 2021-07-24 10:44:01
*/
#include <bits/stdc++.h>
#define FastIO std::ios::sync_with_stdio(false), std::cin.tie(nullptr)
using std::cerr;
using std::cin;
using std::cout;
constexpr int N = 14;
std::string name[N + 5] = {"", "预言家", "盗贼", "女巫", "猎人", "守卫", "骑士", "狼", "白狼王", "民", "民", "民", "民", "民", "民"};
signed main() {
	FastIO;
	std::mt19937 rnd(time(nullptr));
	std::shuffle(name + 1, name + 1 + N, rnd);
	for (int i = 1; i <= N; i += 2)
		cout << (i + 1) / 2 << ": " << name[i] << ' ' << name[i + 1] << '\n';

	cout.flush();
	return 0;
}

/*

*/