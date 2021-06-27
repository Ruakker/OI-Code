/*
	Author: Ruakker
	Date: 2021-05-17 15:22:42
	LastEditTime: 2021-05-17 16:21:45
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
namespace FastIO{static const int BUFSIZE=(1<<20)+1;static char Ibuf[BUFSIZE],*I1=Ibuf,*I2=Ibuf,Obuf[BUFSIZE],*O1=Obuf,*O2=O1+BUFSIZE-1;static int Top=0,ST[55];inline void flush(){fwrite(Obuf,1,O1-Obuf,stdout),O1=Obuf;}struct flusher{~flusher(){flush();}}IO;inline char getch(){return I1==I2&&(I2=(I1=Ibuf)+fread(Ibuf,1,BUFSIZE,stdin),I1==I2)?EOF:*I1++;}inline void putch(char __Ch){*O1++=__Ch,(O1==O2)?flush():void();}template<typename __Var>inline __Var read(){__Var res=0,w=1;char __Ch=getch();for(;!isdigit(__Ch);__Ch=getch())if(__Ch=='-')w=-1;for(;isdigit(__Ch);__Ch=getch())res=(res<<3)+(res<<1)+(__Ch^48);return res*w;}template<class __Var>inline void write(__Var __Num){if(!__Num)putch('0');if(__Num<0)putch('-'),__Num=-__Num;for(;__Num;ST[++Top]=__Num%10+'0',__Num/=10);for(;Top;putch(ST[Top--]));}template<class __Var>inline void writeln(const __Var __Num){write<__Var>(__Num),putch('\n');}inline void getstr(char*__S){char __Ch=getch();int __Cnt=0;for(;!isgraph(__Ch);__Ch=getch());for(;isgraph(__Ch);__Ch=getch())__S[__Cnt++]=__Ch;__S[__Cnt]=0;}inline void putstr(const char*__S){int __Len=strlen(__S);for(int i=0;i<__Len;++i)putch(__S[i]);}}using namespace FastIO;
const int N=15,P=1e8;
int n,m,a[N][N],f[1<<N],dp[N][1<<N],res;
ll ans;
signed main(){
	n=read<int>(),m=read<int>();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			f[i]=(f[i]<<1)+(a[i][j]=read<int>());
	dp[0][0]=1;
	for (int i=1;i<=n;++i){
		for (int S1=1<<m;~S1;S1=(S1-1)&f[i]){
		// for (int S1=0;S1<1<<n;++S1) if ((S1&f[i])==S1){
			if (!(S1&S1<<1)&&!(S1&S1>>1))
				for (int S2=0;S2<1<<m;++S2)
					if (!(S1&S2)) (dp[i][S1]+=dp[i-1][S2])%=P;
			if (!S1) break;
		}
	}
	for (int i=0;i<1<<m;++i)
		(ans+=dp[n][i])%=P;
	writeln(ans);
	return 0;
}