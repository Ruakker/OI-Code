#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1;c=getchar(); }
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
const int N=1e5+5;
struct edge{
	int y,next;
}e[N<<1];
int cnt,first[N];
inline void add(int x,int y) { e[++cnt]={y,first[x]};first[x]=cnt; }
int n,u,f[N];
int F[N];
inline int get(int x) { return x==f[x]?x:f[x]=get(f[x]); }
double a[N];
void dfs(int x,int fa){
	F[x]=fa;
	for(int i=first[x];i;i=e[i].next){
		int y=e[i].y;
		if(y==fa) continue;
		dfs(y,x);
	}
}
struct node{
	double v;
	int x;
};
const double eps=1e-7;
inline int operator<(const node x,const node y){
	if(fabs(x.v-y.v)<=eps) return x.x<y.x;
	return y.v+eps<x.v;
}
set<node>st;
int pre[N],suf[N],bot[N];
double sum[N];
int siz[N];
inline void merge(int x,int y){
	f[get(x)]=get(y);
	suf[bot[y]]=x;
	bot[y]=bot[x];
	sum[y]+=sum[x];
	siz[y]+=siz[x];
	a[y]=1.0*sum[y]/siz[y];
}
int b[N];
int vis[N];
int main(){
	fre(visit);
	n=read(),u=read();
	for(int i=1;i<=n;i++){
		b[i]=a[i]=read();
		st.insert({a[i],i});
	}
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs(u,0);
	for(int i=1;i<=n;i++) bot[i]=i,sum[i]=a[i],siz[i]=1,f[i]=i;
	vis[u]=1;
	while(st.size()){
		set<node>::iterator it=st.begin();
		st.erase(st.begin());
		int x=it->x;
		if(vis[x]) continue;
		vis[x]=1;
		int y=F[x];
		y=get(y);
		merge(x,y);
		st.insert({a[y],y});
	}
	ll t=0;
	int i=u;
	ll ans=0;
	while(i) t++,ans+=t*b[i],i=suf[i];
	t++,ans+=t*b[i];
	printf("%lld\n",ans);
	return 0;
}
