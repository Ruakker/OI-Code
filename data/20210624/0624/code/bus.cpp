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
const int N=2e5+5;
multiset<int>st1,st2;
int n,m,q,a[N],b[N];
int main(){
	fre(bus);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read(),st1.insert(a[i]);
	for(int i=1;i<=m;i++) b[i]=read(),st2.insert(b[i]);
	while(q--){
		int op=read();
		int x,v;
		if(op==0){
			x=read(),v=read();
			st1.erase(st1.find(a[x]));
			a[x]=v;
			st1.insert(a[x]);
		}
		else if(op==1){
			x=read(),v=read();
			st2.erase(st2.find(b[x]));
			b[x]=v;
			st2.insert(b[x]);
		}
		else{
			int r1=read(),c1=read(),r2=read(),c2=read();
			int ans=0x3f3f3f3f;
			ans=min(a[r1]+b[c2],a[r2]+b[c1]);
			ans=min(ans,b[c1]+b[c2]+*st1.begin());
			ans=min(ans,a[r1]+a[r2]+*st2.begin());
			if(r1==r2) ans=min(ans,a[r1]);
			if(c1==c2) ans=min(ans,b[c1]);
			if(r1==r2&&c1==c2) ans=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}
