/**
 * File              : CF1594B.cpp
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
const int P = 1e9 + 7;
int qpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1)            //如果n的当前末位为1
            (ans *= a) %= P;  // ans乘上当前的a
        (a *= a) %= P;        // a自乘
        n >>= 1;              // n往右移一位
    }
    return ans;
}
signed main() {
    int T;
    cin >> T;
    for (; T--;) {
        int n, k;
        int ans = 0;
        cin >> n >> k;
        std::stack<int> st;
        for (int i = 0, kk = k; kk; kk >>= 1, ++i) st.push(kk & 1);
        for (int i = 0; !st.empty(); ++i) {
            int cur = st.top();
            st.pop();
            if (cur & 1)
                ans = (ans * n % P + 1 % P) % P, cerr << 1 << ' ';
            else
                ans = ans * n % P, cerr << 0 << ' ';
        }
        cout << ans << endl;
    }
    return 0;
}