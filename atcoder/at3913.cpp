/*
	Author: Ruakker
	Date: 2021-05-17 10:27:15
	LastEditTime: 2021-05-17 14:36:20
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO{static const int BUFSIZE=(1<<20)+1;static char Ibuf[BUFSIZE],*I1=Ibuf,*I2=Ibuf,Obuf[BUFSIZE],*O1=Obuf,*O2=O1+BUFSIZE-1;static int Top=0,ST[55];inline void flush(){fwrite(Obuf,1,O1-Obuf,stdout),O1=Obuf;}struct flusher{~flusher(){flush();}}IO;inline char getch(){return I1==I2&&(I2=(I1=Ibuf)+fread(Ibuf,1,BUFSIZE,stdin),I1==I2)?EOF:*I1++;}inline void putch(char x){*O1++=x,(O1==O2)?flush():void();}template<typename Var>inline Var read(){Var res=0,w=1;char ch=getch();for(;!isdigit(ch);ch=getch())if(ch=='-')w=-1;for(;isdigit(ch);ch=getch())res=(res<<3)+(res<<1)+(ch^48);return res*w;}template<class Var>inline void write(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;ST[++Top]=num%10+'0',num/=10);for(;Top;putch(ST[Top--]));}template<class Var>inline void writeln(Var num){write<Var>(num),putch('\n');}inline void getstr(char*s){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())s[cnt++]=ch;s[cnt]=0;}inline void putstr(const char*s){int len=strlen(s);for(int i=0;i<len;++i)putch(s[i]);}}using namespace FastIO;
const int N=1e5+5,M=1<<16;
int val[N],n,cnt[20],res,ans,dp[M],sum[M];
using std::cerr;
using std::endl;
signed main(){
	n=read<int>();
	for (int i=1;i<n;++i){
		int u=read<int>()+1,v=read<int>()+1,w=read<int>();
		val[u]^=w,val[v]^=w;
		#ifdef Debug
			write(val[u]),putch(' '),write(val[v]),putch('\n');
		#endif
	}
	for (int i=1;i<=n;++i)
		++cnt[val[i]];
	#ifdef Debug
		for (int i=0;i<n;++i)
			write(cnt[i]),putch(' ');
		putch('\n');
		for (int i=0;i<n;++i)
			write(val[i]),putch(' ');
		putch('\n');
	#endif
	for (int i=1;i<=16;++i)
		res|=(cnt[i]&1)<<(i-1),ans+=cnt[i]>>1; //去除匹配的节点
	// dp[res]=ans;
	// for (int S=res;S!=0;S=(S-1)&res){
	// 	cerr<<S<<endl;
	// 	for (int j=0;j<16;++j){
	// 		if (!(res>>j&1)) continue;
	// 		for (int k=j+1;k<16;++k){
	// 			if (!(res>>k&1)) continue;
	// 			int num=j^k;
	// 			if (S>>num&1){
	// 				int cur=S&(~1<<num);
	// 				dp[cur]=std::min(dp[cur],dp[S]+2);
	// 			}else{
	// 				int cur=S|(1<<num);
	// 				dp[cur]=std::min(dp[cur],dp[S]+1);
	// 			}
	// 		}
	// 	}
	// }
	for (int i=0;i<1<<16;i++){
		for (int j=1;j<16;j++){
			sum[i]^=j*(i>>(j-1)&1);
			dp[i]+=i>>(j-1)&1;
		}
		--dp[i];
	}
	dp[0]=0;
	for (int S=0;S<1<<16;S++){
		if (sum[S]) continue;
		for (int j=S;j;j=(j-1)&S){ //枚举子集
			if (sum[j]) continue;
			dp[S]=std::min(dp[S],dp[S^j]+dp[j]);
		}
	}
	writeln(ans+dp[res]);
	// for (int S=res;S!=0;S=(S-1)&res)
	// 	writeln(dp[S]);
	return 0;
}
