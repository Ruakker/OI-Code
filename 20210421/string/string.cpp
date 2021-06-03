/*
	Author: Chocola4ever
	Date: 2021-04-21 08:10:18
	LastEditTime: 2021-04-21 08:41:13
	FilePath: \Programs\20210421\string\string.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1005,M=100005;
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
	int nxt,to,val;
}e[M];
int head[N],tote=1;
int n,dis[N],cntcir[N];
bool inq[N];
queue<int> q;
void addedge(int x,int y,int z){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	e[tote].val=z;
	head[x]=tote;
}
bool spfa(int st){
	memset(inq,0,sizeof(inq));
	memset(dis,0,sizeof(dis));
	inq[st]=1,q.push(st);
	dis[st]=1,++cntcir[st];
	while (!q.empty()){
		int u=q.front();
		inq[u]=0;
		q.pop();
		for (int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if (e[i].val+dis[u]>dis[v]){
				dis[v]=e[i].val+dis[u];
				if (!inq[v]){
					++cntcir[v];
					if (cntcir[v]>=n) return 1;
					q.push(v),inq[v]=1;
				}
			}
		}
	}
	return 0;
}
void init(){
	memset(cntcir,0,sizeof(cntcir));
	memset(e,0,sizeof(Chocola)*M);
	memset(head,0,sizeof(head));
	tote=1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read();
	while (T--){
		init();
		n=read();
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				addedge(i,j,read());
		for (int i=1;i<=n;++i)
			addedge(0,i,0);
		if (spfa(0)){
			puts("-1");
			continue;
		}
		int ans=-inf;
		for (int i=1;i<=n;++i)
			ans=max(ans,dis[i]);
		printf("%lld\n",ans-1);
	}
	return 0;
}
