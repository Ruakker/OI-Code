/*
	Author: Chocola4ever
	Date: 2021-04-23 13:37:51
	LastEditTime: 2021-04-23 15:38:14
	FilePath: \Programs\20210423\maze.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=10005,M=50005;
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
int p[N],head[N],tote=1;
int n,m,k,s;
void addedge(int x,int y,int z){
	e[++tote].nxt=head[x];
	e[tote].to=y;
	e[tote].val=z;
	head[x]=tote;
}
int main(){
	n=read(),m=read(),k=read(),s=read();
	for (int i=1;i<=n;++i)
		p[i]=read();
	for (int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	return 0;
}
