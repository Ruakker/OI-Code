#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif

#define int long long
int a[1000000];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;) {
        int n, ans;
        cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
        std::sort(a + 1, a + n + 1);
		for (int i = n; i; --i)
			a[i] -= a[1];
		ans = a[n];
		if (!ans) {
            cout << -1 << endl;
			continue;
		}
		for (int i = n; i; --i)
			if (a[i])
                ans = std::__gcd(ans, a[i]);
			else
                break;
        cout << ans << endl;
	}
	return 0;
}

