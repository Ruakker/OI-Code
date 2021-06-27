/**
 * File              : test.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/02/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
const int N = 3.7e7 + 5, M = 3e5 + 5, P = 1e9 + 7;
int n;
int mex, cnt, a[N], f[N], S[M];
int sum[N];
#define int long long
std::bitset<M> vis;

inline void Add(int x) {
    if (x > mex) return;
    if (S[x] == 0) ++cnt;
    ++S[x];
}

signed main() {
    freopen("clods.in", "r", stdin);
    freopen("clods.out", "w", stdout);
    int T;
    for (io >> T; T--;) {
        vis.reset();
        memset(sum, 0, sizeof sum);
        memset(f, 0, sizeof f);
        memset(S, 0, sizeof S);
        mex = cnt = 0;
        io >> n;
        if (n == 37000000) {
            int x, y;
            io >> x >> y;
            a[1] = 0;
            for (int i = 2; i <= n; ++i)
                a[i] = (a[i - 1] * x + y + i) & 262143;
        } else
            for (int i = 1; i <= n; ++i)
                io >> a[i];
        for (int i = 1; i <= n; ++i)
            vis[a[i]] = 1;
        for (; vis[mex]; ++mex)
            ;
        --mex;
        int l = 1;
        f[0] = 1, sum[0] = 1;
        for (int r = 1; r <= n; ++r) {
            Add(a[r]);
            while ((l < r) && (a[l] > mex || S[a[l]] > 1))
                --S[a[l++]];
            if (cnt == mex + 1) f[r] = sum[l - 1];
            sum[r] = (sum[r - 1] + f[r]) % P;
        }
        io << f[n] << '\n';
    }
    return 0;
}