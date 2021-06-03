/*
	Author: Ruakker
	Date: 2021-05-16 20:32:00
	LastEditTime: 2021-05-16 21:41:32
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
const int BUFSIZE=(1<<21)+1;static char ibuf[BUFSIZE],*i1=ibuf,*i2=ibuf,obuf[BUFSIZE],*o1=obuf,*o2=o1+BUFSIZE-1;inline void flush(){fwrite(obuf,1,o1-obuf,stdout),o1=obuf;}
#define getchar()i1==i2&&(i2=(i1=ibuf)+fread(ibuf,1,BUFSIZE,stdin),i1==i2)?EOF:*i1++
#define putchar(x)*o1++=x,(o1==o2)?flush():void()
struct flusher{~flusher(){flush();}}io;template<typename Val>inline Val read(){Val res=0,w=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')w=-1;for(;isdigit(ch);ch=getchar())res=(res<<3)+(res<<1)+(ch^48);return res*w;}template<typename Val>void write(Val num){if(num<0)num=-num,putchar('-');if(num>9)write(num/10);putchar(num%10+'0');}template<typename Val>inline void writeln(Val num){write<Val>(num),putchar('\n');}inline void readstr(char*s){char ch=getchar();int cnt=0;for(;!isgraph(ch);ch=getchar());for(;isgraph(ch);ch=getchar())s[cnt++]=ch;s[cnt]=0;}inline void writestr(char*s){int len=strlen(s);for(int i=0;i<len;++i)putchar(s[i]);}
const int N=1e5+5,P=1e9+7;
struct Ruakker{
	int nxt,to;
}e[N<<1];
int n,head[N],tote=1,indgr[N],dp[N][2]; //dp_{i,0/1} means now at node_i, the color of it is 0(white)/1(black).
inline void adde(int x,int y){e[++tote].to=y,e[tote].nxt=head[x],head[x]=tote;}
void dfs(int u,int pre){
	dp[u][0]=dp[u][1]=1;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (v==pre) continue;
		dfs(v,u);
		(dp[u][0]*=dp[v][0]+dp[v][1])%=P;
		(dp[u][1]*=dp[v][0])%=P;
	}
}
signed main(){
	n=read<int>();
	for (int i=1;i<n;++i){
		int u=read<int>(),v=read<int>();
		adde(u,v),adde(v,u);
	}
	dfs(1,-1);
	writeln<int>((dp[1][0]+dp[1][1])%P);
	// for (int i=1;i<=n;++i)
	// 	write<int>(dp[i][0]),putchar(' '),writeln<int>(dp[i][1]);
	return 0;
}