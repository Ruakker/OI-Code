/*
	Author: Ruakker
	Date: 2021-05-14 08:43:17
	LastEditTime: 2021-05-14 08:58:41
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
inline ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
void write(ll x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writeln(ll x){write(x),putchar('\n');}
const int N=6e3+5;
struct Ruakker{
	int nxt,to;
}e[N<<1];
int tote=1,head[N],n,rt,indgr[N],val[N],dp[N][2];
inline void addedge(int x,int y){e[++tote].to=y,e[tote].nxt=head[x],head[x]=tote;}
void dfs(int u){
	dp[u][0]=0,dp[u][1]=val[u];
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v);
		dp[u][0]+=std::max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}
signed main(){
	n=read();
	for (int i=1;i<=n;++i)
		val[i]=read();
	for (int i=1;i<=n-1;++i){
		int u=read(),v=read();
		addedge(v,u),++indgr[u];
	}
	for (int i=1;i<=n;++i)
		if (!(indgr[i])) rt=i;
	dfs(rt);
	writeln(std::max(dp[rt][0],dp[rt][1]));
	// for (int i=1;i<=n;++i)
	// 	write(dp[i][0]),putchar(' '),writeln(dp[i][1]);
	return 0;
}
