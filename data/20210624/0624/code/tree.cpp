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
const int N=8e5+5,mod=1e9+7;
struct edge{
	int y,next;
}e[N<<1];
int cnt,first[N];
inline void add(int x,int y) { e[++cnt]={y,first[x]};first[x]=cnt; }
struct node{
	ll dat,sa,sb,cnt;
}f[N];
inline node operator*(const node a,const node b){
	node c;
	c.dat=(a.dat*(b.cnt+1)%mod+b.dat*a.cnt%mod+a.sa*b.sb%mod+a.sb*b.sa%mod)%mod;
	c.sa=(a.sa*(b.cnt+1)%mod+b.sa*a.cnt%mod)%mod;
	c.sb=(a.sb*(b.cnt+1)%mod+b.sb*a.cnt%mod)%mod;
	c.cnt=a.cnt*(b.cnt+1)%mod;
	return c;
}
int n,a[N],b[N];
void dfs(int x,int fa){
	f[x].dat=1ll*a[x]*b[x]%mod;
	f[x].sa=a[x];
	f[x].sb=b[x];
	f[x].cnt=1;
	for(int i=first[x];i;i=e[i].next){
		int y=e[i].y;
		if(y==fa) continue;
		dfs(y,x);
		f[x]=f[x]*f[y];
	}
}
int main(){
	fre(tree);
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	dfs(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+f[i].dat)%mod;
	printf("%lld\n",ans);
	return 0;
}
