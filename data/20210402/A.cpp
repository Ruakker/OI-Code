/*
	Author: Chocola4ever
	Date: 2021-04-02 08:01:14
	LastEditTime: 2021-04-02 10:11:04
	FilePath: \Programs\20210402\A.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
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
	int nxt,to,val;
}e[N];
int head[N],totedge,n,k;
int depth[N],waterspeed[N];
int minid,mindepth=inf,speed[N];
void addedge(int x,int y){
	e[++totedge].to=y;
	e[totedge].nxt=head[x];
	head[x]=totedge;
}
struct edepth{
	int id,val;
}temp;
bool cmp(edepth a,edepth b){
	return a.val<b.val;
}
inline void dfs1(int u,int dpth){//find depth&update waterspeed
	depth[u]=dpth;
	int s=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs1(v,dpth+1);
		s+=waterspeed[v];
	}
	waterspeed[u]=min(s==0?inf:s,waterspeed[u]);
}
/*inline void dfs2(int u){
	if (head[u]==0)
		return;
	vector<edepth> edges;
	int s=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs2(v);
		temp=(edepth){v,depth[v]};
		edges.push_back(temp);
		s+=waterspeed[v];
	}
	waterspeed[u]=min(s,waterspeed[u]);
	sort(edges.begin(),edges.end(),cmp);
	for (int i=1)
}*/
inline void dfs2(int u){
	if (head[u]==0){
		speed[depth[u]-1]+=waterspeed[u];
		return;
	}
	if (waterspeed[u]==0){
		for (int i=head[u];i;i=e[i].nxt){
			waterspeed[e[i].to]=0;
			dfs2(e[i].to);
		}
		return;
	}
	vector<edepth> edges;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		temp=(edepth){v,depth[v]};
		edges.push_back(temp);
	}
	sort(edges.begin(),edges.end(),cmp);
	int s=0;
	for (int i=0;i<=edges.size()-1;++i){
		int v=edges[i].id;
		if (waterspeed[u]-s<waterspeed[v]){
			waterspeed[v]=waterspeed[u]-s;
			for (int j=i+1;j<=edges.size()-1;++j)
				waterspeed[v]=0;
			break;
		}
		s+=waterspeed[v];
	}
	for (int i=head[u];i;i=e[i].nxt)
		dfs2(e[i].to);
}
void init(){
	memset(e,0,sizeof(Chocola)*N);
	memset(head,0,sizeof(head));
	memset(depth,0,sizeof(depth));
	memset(waterspeed,0,sizeof(waterspeed));
	memset(speed,0,sizeof(speed));
	totedge=n=k=minid=0;
	mindepth=inf;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T=read();
	while (T--){
		init();
		n=read(),k=read();
		for (int i=1;i<=n-1;++i){
			int fa=read();
			addedge(fa,i+1);
		}
		for (int i=1;i<=n-1;++i)
			waterspeed[i+1]=e[i].val=read();
		waterspeed[1]=inf;
		dfs1(1,1);
	//	for (int i=1;i<=n;++i)
	//		printf("%d %d\n",depth[i],waterspeed[i]);
		dfs2(1);
	/*	puts("speed:");
		for (int i=1;i<=n;++i)
			printf("%d\n",speed[i]);*/
		int sumwater=speed[1],ans=1;
		for (;sumwater<k;speed[++ans]+=speed[ans-1],sumwater+=speed[ans]);
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4 50
1 1 1
5 6 7
*/