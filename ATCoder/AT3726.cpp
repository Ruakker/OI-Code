/*
	Author: Ruakker
	Date: 2021-05-17 19:04:28
	LastEditTime: 2021-05-17 20:19:37
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO{static const int BUFSIZE__=(1<<20)+1;static char Ibuf__[BUFSIZE__],*I1__=Ibuf__,*I2__=Ibuf__,Obuf__[BUFSIZE__],*O1__=Obuf__,*O2__=O1__+BUFSIZE__-1;static int Top__=0,ST__[55];inline void flush(){fwrite(Obuf__,1,O1__-Obuf__,stdout),O1__=Obuf__;}struct flusher__{~flusher__(){flush();}}IO__;inline char getch(){return I1__==I2__&&(I2__=(I1__=Ibuf__)+fread(Ibuf__,1,BUFSIZE__,stdin),I1__==I2__)?EOF:*I1__++;}inline void putch(char Ch__){*O1__++=Ch__,(O1__==O2__)?flush():void();}inline void getstr(char*S__){char Ch__=getch();int cnt__=0;for(;!isgraph(Ch__);Ch__=getch());for(;isgraph(Ch__);Ch__=getch())S__[cnt__++]=Ch__;S__[cnt__]=0;}inline void putstr(const char*S__){int Len__=strlen(S__);for(int i__=0;i__<Len__;++i__)putch(S__[i__]);}template<typename Var>inline Var read(){Var Res__=0,W__=1;char Ch__=getch();for(;!isdigit(Ch__);Ch__=getch())if(Ch__=='-')W__=-1;for(;isdigit(Ch__);Ch__=getch())Res__=(Res__<<3)+(Res__<<1)+(Ch__^48);return Res__*W__;}template<class Var>inline void write(Var Num__,const char*S__=""){if(!Num__)putch('0');if(Num__<0)putch('-'),Num__=-Num__;for(;Num__;ST__[++Top__]=Num__%10+'0',Num__/=10);for(;Top__;putch(ST__[Top__--]));if(strlen(S__))putstr(S__);}}using namespace FastIO;
using std::vector;
using std::cerr;
using std::endl;
const int N=1e5;
char s[N];
int X,Y,n;
vector<int> pathx,pathy;
signed main(){
	getstr(s+1),X=read<int>(),Y=read<int>();
	n=strlen(s+1);
	for (int i=1,cnt=0;i<=n;++i){
		if (s[i]=='F'){
			if (cnt&1) ++pathy[cnt>>1];
			else ++pathx[cnt>>1];
		}else{
			if (cnt&1) pathy.push_back(1),++cnt;
			else pathx.push_back(1),++cnt;
		}
	}
	return 0;
}
