/*
	Author: Chocola4ever
	Date: 2021-04-17 09:09:19
	LastEditTime: 2021-04-17 10:36:25
	FilePath: \Programs\20210417\hide.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// #define Debug
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
int head[N<<1],tote=1,n,ans=0;
bool vis[N],a[N];
void addedge(int x,int y){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	head[x]=tote;
}
inline void dfs(int u,int cnt){
	vis[u]=1;
	if (!a[u]) ++cnt;
	if (cnt&1==0||!cnt) ++ans;
	#ifdef Debug
		printf("cnt:%d,ans:%d\n",cnt,ans);
	#endif
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (vis[v]) continue;
		dfs(v,cnt);
	}
}
int main(){
	freopen("hide.in","r",stdin);
	freopen("hide.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<=n-1;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	for (int i=1;i<=n;++i){
		ans=0;
		memset(vis,0,sizeof(vis));
		dfs(i,0);
		printf("%d\n",ans);
	}
	return 0;
}
