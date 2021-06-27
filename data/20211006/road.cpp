/**
 * File              : road.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 10/06/2021
 */
// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
// clang-format off
struct FastIO{protected:const static int SIZE=(1<<20)+1;char Ib[SIZE],*I1=Ib,*I2=Ib;char Ob[SIZE],*O1=Ob,*O2=O1+SIZE-1;int st[55],top=0;inline char getch(){if(I1==I2&&(I2=(I1=Ib)+fread(Ib,1,SIZE,stdin),I1==I2))return EOF;else return*I1++;}inline void putch(char ch){*O1++=ch,(O1==O2)?flush():void();}public:~FastIO(){flush();}inline void flush(){fwrite(Ob,1,O1-Ob,stdout),O1=Ob;}FastIO&operator>>(char&res){for(res=getch();!isgraph(res);res=getch());return*this;}FastIO&operator>>(char*res){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())res[cnt++]=ch;res[cnt]=0;return*this;}template<typename Var>FastIO&operator>>(Var&res){Var f=1;res=0;char ch=getch();for(;ch<'0'||'9'<ch;ch=getch())if(ch=='-')f=-1;for(;'0'<=ch&&ch<='9';ch=getch())res=(res<<3)+(res<<1)+(ch^48);res*=f;return*this;}FastIO&operator<<(char ch){putch(ch);return*this;}template<typename Var>FastIO&operator<<(Var*s){int p=0;for(;s[p]!=0;++p)putch(s[p]);return*this;}template<typename Var>FastIO&operator<<(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;st[++top]=num%10+'0',num/=10);for(;top;putch(st[top--]));return*this;}}io;
// clang-format on
#define inf 0x3f3f3f3f
#define int long long
using std::cerr;
using std::endl;
const int N = 20;
int n, x, y;
int pow4[N];
std::pair<int, int> getPos(int k, int n, int dire) {  // dire: 1^ 2> 3v 4<
    if (!n) return std::make_pair(1, 1);
    int p = k / pow4[n - 1], q = k % pow4[n - 1];
    if (!q) --p, q = pow4[n - 1];
    std::pair<int, int> res;
    if (dire == 1) {
        if (p == 0) {
            res = getPos(q, n - 1, 4);
            res = std::make_pair(res.first + (1 << (n - 1)),
                                 res.second + (1 << (n - 1)));
        }
        if (p == 1) {
            res = getPos(q, n - 1, 1);
            res = std::make_pair(res.first, res.second + (1 << (n - 1)));
        }
        if (p == 2) {
            res = getPos(q, n - 1, 1);
        }
        if (p == 3) {
            res = getPos(q, n - 1, 2);
            res = std::make_pair(res.first + (1 << (n - 1)), res.second);
        }
    }
    if (dire == 2) {
        if (p == 0) res = getPos(q, n - 1, 3);
        if (p == 1) {
            res = getPos(q, n - 1, 2);
            res = std::make_pair(res.first, res.second + (1 << (n - 1)));
        }
        if (p == 2) {
            res = getPos(q, n - 1, 2);
            res = std::make_pair(res.first + (1 << (n - 1)),
                                 res.second + (1 << (n - 1)));
        }
        if (p == 3) {
            res = getPos(q, n - 1, 1);
            res = std::make_pair(res.first + (1 << (n - 1)), res.second);
        }
    }
    if (dire == 3) {
        if (p == 0) {
            res = getPos(q, n - 1, 2);
        }
        if (p == 1) {
            res = getPos(q, n - 1, 3);
            res = std::make_pair(res.first + (1 << (n - 1)), res.second);
        }
        if (p == 2) {
            res = getPos(q, n - 1, 3);
            res = std::make_pair(res.first + (1 << (n - 1)),
                                 res.second + (1 << (n - 1)));
        }
        if (p == 3) {
            res = getPos(q, n - 1, 4);
            res = std::make_pair(res.first, res.second + (1 << (n - 1)));
        }
    }
    if (dire == 4) {
        if (p == 0) {
            res = getPos(q, n - 1, 1);
            res = std::make_pair(res.first + (1 << (n - 1)),
                                 res.second + (1 << (n - 1)));
        }
        if (p == 1) {
            res = getPos(q, n - 1, 4);
            res = std::make_pair(res.first + (1 << (n - 1)), res.second);
        }
        if (p == 2) {
            res = getPos(q, n - 1, 4);
        }
        if (p == 3) {
            res = getPos(q, n - 1, 3);
            res = std::make_pair(res.first, res.second + (1 << (n - 1)));
        }
    }
    return res;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    pow4[0] = 1;
    for (int i = 1; i <= 15; ++i) pow4[i] = pow4[i - 1] * 4;
    int T;
    io >> T;
    for (; T--;) {
        io >> n >> x >> y;
        auto posX = getPos(x, n, 2), posY = getPos(y, n, 2);
        int diffX = abs(posX.first - posY.first),
            diffY = abs(posX.second - posY.second);
        io << (int)(sqrt(100ll * diffX * diffX + 100ll * diffY * diffY) + 0.5)
           << '\n';
#ifdef DEBUG
        io.flush();
        cerr << posX.first << ' ' << posX.second << endl;
        cerr << posY.first << ' ' << posY.second << endl;
#endif
    }
    return 0;
}