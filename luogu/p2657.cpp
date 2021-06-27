/**
 * File              : P2657.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/01/2021
 */
#include <bits/stdc++.h>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
using std::cerr;
using std::endl;
const int N = 2e9 + 5, M = 12;
int l, r;
std::vector<int> bit;
int len, dp[M][M][M];
void split(int k, std::vector<int>& con, int& len) {
    con.clear();
    con.emplace_back(0);
    for (; k; k /= 10)
        con.emplace_back(k % 10);
    len = con.size() - 1;
}
long long dfs(int pos, int pre, int sum, bool lead, bool limit) {
    if (pos <= 0) return sum;
    if (dp[pos][pre][sum] != -1 && !lead && !limit) return dp[pos][pre][sum];
    long long res = 0;
    int up = limit ? bit[pos] : 9;
    for (int i = 0; i <= up; ++i) {
        if (lead && !i)
            res += dfs(pos - 1, i, 0, lead, i == bit[pos] && limit);
        else if (lead && i)
            res += dfs(pos - 1, i, 1, 0, i == bit[pos] && limit);
        else
            res += dfs(pos - 1, i, abs(pre - i) >= 2 && sum, lead,
                       i == bit[pos] && limit);
    }
    if (!lead && !limit) dp[pos][pre][sum] = res;
    return res;
}
long long query(int k) {
    split(k, bit, len);
    memset(dp, -1, sizeof dp);
    return dfs(len, 0, 0, 1, 1);
}
signed main() {
    io >> l >> r;
    io << query(r) - query(l - 1) << '\n';
    return 0;
}