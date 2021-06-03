/*
	Author: Ruakker
	Date: 2021-05-18 15:14:42
	LastEditTime: 2021-05-18 15:25:33
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO{static const int BUFSIZE__=(1<<20)+1;static char Ibuf__[BUFSIZE__],*I1__=Ibuf__,*I2__=Ibuf__,Obuf__[BUFSIZE__],*O1__=Obuf__,*O2__=O1__+BUFSIZE__-1;static int ST__[55],Top__;inline void flush(){fwrite(Obuf__,1,O1__-Obuf__,stdout),O1__=Obuf__;}struct flusher__{~flusher__(){flush();}}IO__;inline char getch(){return I1__==I2__&&(I2__=(I1__=Ibuf__)+fread(Ibuf__,1,BUFSIZE__,stdin),I1__==I2__)?EOF:*I1__++;}inline void putch(char Ch__){*O1__++=Ch__,(O1__==O2__)?flush():void();}inline void getstr(char*S__){char Ch__=getch();int cnt__=0;for(;!isgraph(Ch__);Ch__=getch());for(;isgraph(Ch__);Ch__=getch())S__[cnt__++]=Ch__;S__[cnt__]=0;}inline void putstr(const char*S__){int Len__=strlen(S__);for(int i__=0;i__<Len__;++i__)putch(S__[i__]);}template<typename Var>inline Var read(){register Var Res__=0,W__=1;register char Ch__=getch();for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())Res__=(Res__<<3)+(Res__<<1)+(Ch__^48);return Res__*W__;}template<typename Var>inline void write(register Var Num__,const char Ch__='\0'){if(!Num__)putch('0');if(Num__<0)putch('-'),Num__=-Num__;for(;Num__;ST__[++Top__]=Num__%10+'0',Num__/=10);for(;Top__;putch(ST__[Top__--]));if(Ch__!='\0')putch(Ch__);}}using namespace FastIO;
const int N=1005;
double dp[N];
signed main(){
	for (int T=read<int>();T--;){
		int n=read<int>();
		dp[n]=1;
		for (int i=n-1;~i;--i)
			dp[i]=dp[i+1]+(double)n/(n-i);
		printf("%0.2lf\n",dp[1]);
	}
	return 0;
}
