/*
	Author: Chocola4ever
	Date: 2021-04-18 13:30:38
	LastEditTime: 2021-04-18 16:36:11
	FilePath: \Programs\20210418\trip.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define Debug
using namespace std;
const int N=1e6+5;
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
	int nxt,to;
}e[N<<1];
int head[N<<1],tote=1;
void addedge(int x,int y){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	head[x]=tote;
}
bool a[N];
int dp1[N][2],dp2[N][2],ans,n;//u,wb
inline void dfs(int u,int pre){
	if (head[u]==0){
		if (a[u]){
			dp1[u][1]=1;
			dp2[u][1]=1;
			dp1[u][0]=0;
			dp2[u][0]=0;
		}else{
			dp1[u][0]=1;
			dp2[u][0]=1;
			dp1[u][1]=0;
			dp2[u][1]=0;
		}
		return;
	}
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (v==pre) continue;
		dfs(v,u);
		dp1[u][1]=max(dp1[v][1],dp1[u][1]);
		dp1[u][0]=max(dp1[v][0],dp1[u][0]);
		dp2[u][1]=min(dp2[v][1],dp2[u][1]);
		dp2[u][0]=min(dp2[v][0],dp2[u][0]);
	}
	++dp1[u][a[u]];
	++dp2[u][a[u]];
}
int main(){
	memset(dp2,127,sizeof(dp2));
	#ifndef Debug
		freopen("trip.in","r",stdin);
		freopen("trip.out","w",stdout);
	#endif
	n=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<=n-1;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,-1);
	ans=-inf;
	for (int i=1;i<=n;++i){
		ans=max(abs(dp1[i][1]-dp2[i][0]),ans);
		ans=max(abs(dp1[i][0]-dp2[i][1]),ans);
	}
	#ifdef Debug
		for (int i=1;i<=n;++i)
			printf("%d ",dp1[i][0]);
		puts("");
		for (int i=1;i<=n;++i)
			printf("%d ",dp1[i][1]);
		puts("");
		for (int i=1;i<=n;++i)
			printf("%d ",dp2[i][0]);
		puts("");
		for (int i=1;i<=n;++i)
			printf("%d ",dp2[i][1]);
		puts("");
	#endif
	printf("%d",ans);
	return 0;
}
