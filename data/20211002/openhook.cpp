/**
 * File              : openhook.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/02/2021
 */
#include <bits/stdc++.h>
#include <windows.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
bool ST;
const int N = 2e6 + 5, M = 1e9 + 5;
int n, len;
int a[N], b[N], disc[N], cnt[N], step[N], height[N],rec[N];
unsigned long long ans;
std::bitset<M> unvis;
inline void Disc() {
    for (register int i = 1; i <= n; ++i)
        disc[i] = height[i];  // already sorted
    len = std::unique(disc + 1, disc + 1 + n) - disc - 1;
    for (register int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(disc + 1, disc + 1 + len, height[i]) - disc;
}
inline int goUp(int u) {
    assert(cnt[a[u]] >= 1);
    if (cnt[a[u]] == 1) return 0;
    cnt[a[u]]--;
    // int pos = unvis._Find_next(height[u]);
    rec[a[u]]=unvis._Find_next(rec[a[u]]);
    unvis[rec[a[u]]] = false;
    // for (int i = height[u] + 1; i < M; ++i) {
    //     res++;
    //     if (unvis[i]) {
    //         unvis[i] = false;
    //         break;
    //     }
    // }
    return rec[a[u]] - height[u];
}
bool ED;
signed main() {
#ifdef DEBUG
    cerr << abs(&ST - &ED) / 1048576. << endl;
#endif
    freopen("openhook.in", "r", stdin);
    freopen("openhook.out", "w", stdout);
    unvis.set();
    io >> n;
    for (register int i = 1; i <= n; ++i)
        io >> height[i];
    for (register int i = 1; i <= n; ++i)
        io >> b[i];
    std::sort(height + 1, height + 1 + n);
    std::sort(b + 1, b + 1 + n);
    Disc();
    for (register int i = 1; i <= n; ++i)
        cnt[a[i]]++, unvis[height[i]] = false,rec[a[i]]=height[i];
    for (register int i = n; i; --i)
        step[i] = goUp(i);
    std::sort(step + 1, step + 1 + n, std::greater<int>());
    ans = 0;
    for (register int i = 1; i <= n; ++i)
        ans += 1ull * step[i] * b[i];
    io << ans << '\n';
    return 0;
}