/**
 * File              : CF1594C.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/08/2021
 */
#include <bits/stdc++.h>
// clang-format off
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define int long long
const int N = 1e6 + 5;
std::vector<int> cache;
char s[N];
int n, ans;
char ch;
signed main() {
    int T;
    cin >> T;
    for (; T--;) {
        cache.clear(), ans = 0;
        bool flag0 = false, flag2 = false;
        cin >> n >> ch >> (s + 1);
        for (int i = 1; i <= n; ++i)
            if (s[i] != ch) {
                flag0 = true;
                break;
            }
        if (!flag0) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            bool flag1 = true;
            for (int j = i; j <= n; j += i)
                if (s[j] != ch) {
                    flag1 = false;
                    break;
                }
            if (flag1) {
                flag2 = true;
                ans = i;
                break;
            }
        }
        if (flag2) {
            cout << 1 << endl << ans << endl;
            continue;
        } else
            cout << 2 << endl << n - 1 << ' ' << n << endl;
    }
    return 0;
}
