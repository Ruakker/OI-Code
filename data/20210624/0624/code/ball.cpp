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
const int N=1e3+5;
int n,m,a[N],b[N],p[N],vis[N];
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),vis[i]=0;
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n;j++)
			if(a[i]==b[j]&&!vis[j]){
				vis[j]=1;
				p[i]=j;
				flag=1;
				break;
			}
		if(!flag) return puts("NIE"),void();
	}
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		sort(p+l,p+r+1);
	}
	for(int i=1;i<=n;i++) if(p[i]!=i) return puts("NIE"),void();
	puts("TAK");
}
int main(){
	fre(ball);
	int T=read();
	while(T--) solve();
	return 0;
}
