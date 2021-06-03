/*
	Author: Chocola4ever
	Date: 2021-04-01 09:14:52
	LastEditTime: 2021-04-01 10:37:11
	FilePath: \Programs\20210401\C.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define N 50005
using namespace std;
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
}e[N];
stack<int> st;
int head[N],dfn[N],low[N],id[N],u1[N],v1[N],sz[N],ans[N];
bool inst[N],b[N];
int newcnt,cnt,totedge,n,m,totm,g;
inline void addedge(int x,int y){
	e[++totedge].to=y;
	e[totedge].nxt=head[x];
	head[x]=totedge;
}
inline void tarjan(int u){
	dfn[u]=++cnt;
	low[u]=cnt;
	inst[u]=1;
	st.push(u);
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if (inst[v])
			low[u]=min(low[u],dfn[v]);
	}
	int v;
	if (dfn[u]==low[u]){
		newcnt++;
		do{
			v=st.top();
			st.pop();
			inst[v]=0;
			id[v]=newcnt;
			sz[newcnt]++;
		}while (v!=u);
	}
}
void init(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(id,0,sizeof(id));
	memset(u1,0,sizeof(u1));
	memset(v1,0,sizeof(v1));
	memset(sz,0,sizeof(sz));
	memset(ans,0,sizeof(ans));
	memset(inst,0,sizeof(inst));
	memset(b,0,sizeof(b));
	newcnt=cnt=totedge=n=m=totm=g=0;
}
int main(){
	int t=read();
	for (int _=1;_<=t;++_){
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(struct Chocola)*N);
		init();
		n=read(),m=read(),g=read();
		for (int i=1;i<=m;i++){
			int a=read()+1,b=read()+1;
			addedge(a,b+n);
			addedge(b,a+n);
		}
		for (int i=1;i<=n*2;i++)
			if (!dfn[i]) tarjan(i);
		bool cntinue=0;
		for (int i=1;i<=n;i++)
			if (id[i]==id[i+n]){
				puts("Impossible");
				cntinue=1;
			}
		if (cntinue) continue;
		int anscnt=0;
	/*	for (int i=1;i<=n;++i)
			if(id[i]<id[i+n])
				printf("1 ");
			else
				printf("0 "); puts("");*/
		for (int i=1;i<=n;++i)
			if(id[i]<id[i+n])
				++anscnt;
		if (anscnt>=g) puts("Possible");
		else {
			puts("Impossible");/*
			init();
			for (int i=n*2;i>=1;--i)
				if (!dfn[i]) tarjan(i);
			for (int i=1;i<=n;++i)
				if(id[i]<id[i+n])
					++anscnt;
			if (anscnt>=g) puts("POSSIBLE");
			else puts("IMPOSSIBLE");
	for (int i=1;i<=n;++i)
			if(id[i]<id[i+n])
				printf("1 ");
			else
				printf("0 "); puts("");*/
		}
	/*	for (int i=1;i<=n*2;++i)
			printf("%d ",id[i]);
		puts("");*/
	}
	return 0;
}