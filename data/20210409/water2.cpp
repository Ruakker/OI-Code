/*
	Author: Chocola4ever
	Date: 2021-04-09 09:44:05
	LastEditTime: 2021-04-09 10:28:44
	FilePath: \Programs\20210409\water2.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1;
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
	printf("1 x:%d y:%d k:%d\n",x,y,k);
	if (a[x-1][y]>=k) temp=min(a[x-1][y],temp);
	if (a[x+1][y]>=k) temp=min(a[x+1][y],temp);
	if (a[x][y-1]>=k) temp=min(a[x][y-1],temp);
	if (a[x][y+1]>=k) temp=min(a[x][y+1],temp);
	if (a[x-1][y]<=k&&x-1>=1&&!vis[x-1][y]) dfs(x-1,y,k);
	if (a[x+1][y]<=k&&x+1<=n&&!vis[x+1][y]) dfs(x+1,y,k);
	if (a[x][y-1]<=k&&y-1>=1&&!vis[x][y-1]) dfs(x,y-1,k);
	if (a[x][y+1]<=k&&y+1<=n&&!vis[x][y+1]) dfs(x,y+1,k);
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			cin>>a[i][j];/*
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			memset(vis,0,sizeof(vis));
			temp=1e9+5;
			dfs(i,j,a[i][j]);
			if (temp<a[i][j]) temp=a[i][j];
			if (temp>1e9) temp=a[i][j];
			ans[i][j]=temp;
			printf("\ntemp=%d\n\n",temp);
		}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			printf("%d ",ans[i][j]-a[i][j]);
		putchar('\n');
	}*/
	return 0;
}
