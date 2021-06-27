/**
 * File              : CF628D.cpp
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
#define int long long
const int N = 2005, P = 1e9 + 7;
int m, d;
char l[N], r[N];
std::vector<int> bit;
int len, dp[N][N];
void split(char *s, std::vector<int> &con, int &len) {
    con.clear();
    con.emplace_back(0);
    len = strlen(s + 1);
    for (int i = 1; i <= len; ++i)
        con.emplace_back(s[i] - '0');
    std::reverse(++con.begin(), con.end());
#ifdef DEBUG
    cerr << ">>> ";
    for (int i = 1; i <= len; ++i)
        cerr << con[i] << ' ';
    cerr << endl;
#endif
}
long long dfs(int pos, int sum, bool limit) {
    if (pos <= 0) return sum == 0;
    if (dp[pos][sum] != -1 && !limit) return dp[pos][sum];
    long long res = 0;
    int up = limit ? bit[pos] : 9;
    for (int i = 0; i <= up; ++i) {
        if ((len - pos + 1) & 1) {  // the bit is odd
            if (i == d) continue;
        } else if (i != d)
            continue;
        (res += dfs(pos - 1, (sum * 10 + i) % m, limit && i == up)) %= P;
    }
    if (!limit) dp[pos][sum] = res;
    return res;
}
long long solve(char *s) {
    split(s, bit, len);
    return dfs(len, 0, 1);
}
void dec(char *s) {
    int n = strlen(s + 1);
    for (int i = n; i; --i) {
        if (s[i] != '0') {
            s[i] -= 1;
            break;
        } else
            s[i] = '9';
    }
    if (s[1] == '0') {
        for (int i = 1; i < n; ++i)
            std::swap(s[i], s[i + 1]);
        s[n] = 0;
    }
}
signed main() {
    memset(dp, -1, sizeof dp);
    io >> m >> d >> (l + 1) >> (r + 1);
    dec(l);
    io << (solve(r) - solve(l)) % P << '\n';
    return 0;
}