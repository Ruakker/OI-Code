/*
	Author: Ruakker
	Date: 2021-05-14 10:22:29
	LastEditTime: 2021-05-14 13:50:17
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
const int N=305;
struct Ruakker{
	int nxt,to;
}e[N];
int n,m,tote=1,head[N],dp[N][N];	//dp_{u,j} means the max value when select j nodes in the u and u's son-tree.
inline void adde(int x,int y){e[++tote].to=y,e[tote].nxt=head[x],head[x]=tote;}
inline ll max(ll a,ll b){return a>b?a:b;}
void dfs(int u){
	for (int i=head[u];i;i=e[i].nxt) dfs(e[i].to);	//first we go to the leaf-node
	for (int i=head[u];i;i=e[i].nxt)	//0/1 BACKPACK
		for (int j=m;j>=1;--j){	//because of 0/1 BACKPACK,so let's do it in reverse order
			int v=e[i].to;
			for (int k=1;k<=j-1;++k)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
		}
}
signed main(){
	n=read(),m=read()+1;
	for (int i=1;i<=n;++i){
		adde(read(),i);
		dp[i][1]=read();
	}
	dfs(0);
	writeln(dp[0][m]);
	return 0;
}
