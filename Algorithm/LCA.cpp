/*
	Author: Chocola4ever
	Date: 2021-04-27 13:46:50
	LastEditTime: 2021-04-27 15:40:32
	FilePath: \Programs\LCA.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f
using namespace std;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
const int N=5e5+5,LogN=21;
struct Chocola{
	int to,nxt;
}e[N<<1];
int head[N<<1],tote=1;
void addedge(int x,int y){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	head[x]=tote;
}
int n,m,rt;
int depth[N],fa[N][LogN],lg[N];
void init(){
	for (int i=1;i<=N;++i)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
inline void dfs(int u,int pre){
	depth[u]=depth[pre]+1,fa[u][0]=pre;
	for (int i=1;i<=lg[depth[u]];++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int i=head[u];i;i=e[i].nxt)
		if (e[i].to!=pre) dfs(e[i].to,u);
}
int lca(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	while (depth[x]>depth[y])
		x=fa[x][lg[depth[x]-depth[y]]-1];
	if (x==y) return x;
	for (int k=lg[depth[x]]-1;k>=0;--k)
		if(fa[x][k]!=fa[y][k])
			x=fa[x][k],y=fa[y][k];
	return fa[x][0];
}
int main(){
	init();
	n=read(),m=read(),rt=read();
	for (int i=1;i<=n-1;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	depth[0]=0;
	dfs(rt,0);
	for (int i=1;i<=m;++i)
		printf("%d\n",lca(read(),read()));
	return 0;
}
