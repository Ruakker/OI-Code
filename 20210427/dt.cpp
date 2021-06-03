/*
	Author: Chocola4ever
	Date: 2021-04-27 08:08:49
	LastEditTime: 2021-04-27 08:51:38
	FilePath: \Programs\20210427\dt.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f
#define int long long
// #define Debug
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
const int N=1e5+5,M=2e5+5;
struct Chocola{
	int to,nxt;
}e[M];
struct Forever{
	int id,val,self;
}p[N];
int head[M],tote=1;
int n,m,ans=0,t[N];
void addedge(int x,int y){
	e[++tote].to=y;
	e[tote].nxt=head[x];
	head[x]=tote;
}
bool cmp(Forever a,Forever b){
	return a.self>b.self;
}
signed main(){
	freopen("dt.in","r",stdin);
	freopen("dt.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		p[i].self=read(),p[i].id=i;
	for (int i=1;i<=m;++i){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
		p[u].val+=p[v].self;
		p[v].val+=p[u].self;
	}
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;++i)
		t[p[i].id]=i;
	for (int i=1;i<=n;++i){
		ans+=p[i].val;
		for (int j=head[p[i].id];j;j=e[j].nxt)
				p[t[e[j].to]].val-=p[i].self;
		#ifdef Debug
			for (int i=1;i<=n;++i)
				cout<<p[i].val<<' ';
			puts("");
			cout<<p[i].id<<endl;
		#endif
	}
	printf("%lld",ans);
	return 0;
}
