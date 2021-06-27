#include <bits/stdc++.h>
class _getStdin{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}public:_getStdin(){std::ios::sync_with_stdio(false),std::cin.tie(nullptr);}inline _getStdin&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}inline _getStdin&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>inline _getStdin&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}}cin;
using std::cout;
using std::cerr;

const int N = 305;
int n, m;
char s[N];

namespace sol1 {
int p;
int len[N], f[N][2];
size_t a[N];
signed main() {
    p = (n - 1) / m + 1;
    for (int i = n; i; --i)
        a[i / m + 1] = a[i / m + 1] << 1 | (s[i] == '1');
#ifdef DEBUG
    for (int i = 1; i <= n / m + 1; ++i)
        cerr << std::bitset<sizeof (size_t) << 3>(a[i]) << '\n';
#endif
    std::bitset<20> temp;
    for (int i = 0; i < 1 << m; ++i) 
        f[i][0] = __builtin_popcount(a[i] ^ i);
    
    return 0;
}
} // namespace sol1

namespace sol2 {
signed main() {
    return 0;
}
} // namespace sol2

signed main() {
    cin >> n >> m >> (s + 1);
    if (m <= 18) return sol1::main();
    return sol2::main();
}
