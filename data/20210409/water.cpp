/*
	Author: Chocola4ever
	Date: 2021-04-09 08:16:02
	LastEditTime: 2021-04-09 10:45:26
	FilePath: \Programs\20210409\water.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=500;
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
bool vis[N][N];
int a[N][N],n,m,ans[N][N],temp;
inline void dfs(int x,int y,int k){
	vis[x][y]=1;
	if (a[x-1][y]>k) temp=min(a[x-1][y],temp);
	if (a[x+1][y]>k) temp=min(a[x+1][y],temp);
	if (a[x][y-1]>k) temp=min(a[x][y-1],temp);
	if (a[x][y+1]>k) temp=min(a[x][y+1],temp);
	if (a[x-1][y]<=k&&x-1>=1&&!vis[x-1][y]) dfs(x-1,y,k);
	if (a[x+1][y]<=k&&x+1<=n&&!vis[x+1][y]) dfs(x+1,y,k);
	if (a[x][y-1]<=k&&y-1>=1&&!vis[x][y-1]) dfs(x,y-1,k);
	if (a[x][y+1]<=k&&y+1<=n&&!vis[x][y+1]) dfs(x,y+1,k);
}
inline void dfs2(int x,int y,int k){
	vis[x][y]=1;
	ans[x][y]=k;
	if (ans[x-1][y]<k&&x-1>=1&&!vis[x-1][y]) dfs2(x-1,y,k);
	if (ans[x+1][y]<k&&x+1<=n&&!vis[x+1][y]) dfs2(x+1,y,k);
	if (ans[x][y-1]<k&&y-1>=1&&!vis[x][y-1]) dfs2(x,y-1,k);
	if (ans[x][y+1]<k&&y+1<=n&&!vis[x][y+1]) dfs2(x,y+1,k);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			a[i][j]=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j){
			memset(vis,0,sizeof(vis));
			temp=inf;
			dfs(i,j,a[i][j]);
			if (temp<a[i][j]) temp=inf;
			if (temp>1e9) temp=inf;
			ans[i][j]=temp;
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (ans[i][j]!=inf){
				memset(vis,0,sizeof(vis));
				dfs2(i,j,ans[i][j]);
			}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (ans[i][j]==inf) printf("0 ");
			else printf("%d ",ans[i][j]-a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}