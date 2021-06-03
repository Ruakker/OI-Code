/*
	Author: Chocola4ever
	Date: 2021-04-10 09:26:35
	LastEditTime: 2021-04-10 10:47:26
	FilePath: \Programs\20210410\set.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=3e4+5;
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
	int to,nxt;
}e[N];
bool b[1005][1005];
int n,m,head[N],tote=1,vis[N],ans;
vector<int> p[1005];
vector<int> kk;
void connect(int x,int y){
	b[x][y]=b[y][x]=1;
	p[x].push_back(y);
	p[y].push_back(x);
}
void addedge(int x,int y){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	head[x]=tote;
}
inline void dfs(int u){
	vis[u]=1;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (!vis[v])
			dfs(v);
		p[u].push_back(v);
		connect(u,v);
		int nn=p[v].size();
		for (int i=0;i<nn;++i)
			connect(u,p[v][i]);
	}
}
void init(){
	memset(e,0,sizeof(Chocola)*N);
	memset(b,0,sizeof(b));
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;++i)
		p[i].clear();
	tote=1;
	ans=0;
}

int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	int T=read();
	while (T--){
		n=read(),m=read();
		init();
		for (int i=1;i<=m;++i){
			int u=read(),v=read();
			addedge(u,v);
		}
		for (int i=1;i<=n;++i)
			if (!vis[i]) dfs(i);
		for (int i=1;i<=n;++i){
			kk.clear();
			kk.push_back(i);
			for (int j=1;j<=n;++j){
				bool tempp=1;
				for (int k=0;k<kk.size();++k)
					if (!b[i][j]){
						tempp=0;
						break;
					}
				if (tempp) kk.push_back(j);
			}
			int sz=kk.size();
			ans=max(ans,sz);
		}
		printf("%d\n",ans);
	}
	return 0;
}
