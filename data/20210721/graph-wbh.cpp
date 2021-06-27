#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,y,z,v,num,ans,cnt,head[300010];
struct wang
{
	ll v,to,next;
}e[600010];
struct king
{
	ll v,id,num;
	inline bool operator < (const king& x) const {
		return num<x.num;
	}
};
priority_queue<king>q; 
inline ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^'0');c=getchar();}
	return x*f;
}
inline void add(ll x,ll y,ll z)
{
	e[++cnt].next=head[x];
	e[cnt].to=y;
	e[cnt].v=z;
	head[x]=cnt;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=m;i++) {
		x=read();
		y=read();
		z=read();
		add(x,y,z);
	}
	for (int i=1;i<=n;i++)
		q.push(king{0,i,0});
	while (!q.empty()) {
		king now=q.top();
		q.pop();
		v=now.v;
		x=now.id;
		num=now.num;
		ans=max(ans,num);
		for (int i=head[x];i;i=e[i].next)
			if (v<e[i].v) q.push(king{e[i].v,e[i].to,num+1});
	}
	printf("%lld",ans);
	return 0;
}
