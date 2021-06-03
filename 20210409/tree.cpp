/*
	Author: Chocola4ever
	Date: 2021-04-09 08:02:33
	LastEditTime: 2021-04-09 15:31:31
	FilePath: \Programs\20210409\tree.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1e17
using namespace std;
const int N=1e5+5;
inline ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-')
			w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
struct Chocola{
	int to,nxt,val;
}e[N<<1];
int head[N<<1],tote,n,id[N];
ll dp[N][2];
bool vis[N];
void addedge(int x,int y,int z){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	e[tote].val=z;
	head[x]=tote;
}
inline void dfs(int u){
	if (id[u]==1) dp[u][1]=inf;
	if (id[u]==2) dp[u][0]=inf;
	vis[u]=1;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (!vis[v]){
			dfs(v);
			dp[u][1]+=min(dp[v][1],e[i].val+dp[v][0]);
			dp[u][0]+=min(dp[v][0],e[i].val+dp[v][1]);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for (int i=1;i<=n-1;++i){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int m=read();
	for (int i=1;i<=m;++i)
		id[read()]=1;
	m=read();
	for (int i=1;i<=m;++i)
		id[read()]=2;
	dfs(1);
	printf("%lld\n",min(dp[1][0],dp[1][1]));
	return 0;
}
