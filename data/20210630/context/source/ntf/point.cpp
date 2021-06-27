#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,d,a,b,x[maxn],y[maxn];
namespace brute{
	void solve(){
		int ans=1e9;
		FOR(i,0,(1<<n)-1){
			FOR(j,1,n) if((i>>(j-1))&1) y[j]=x[j]-2*d;
			else y[j]=x[j];
			sort(y+1,y+n+1);
			int s=a;
			FOR(j,2,n) s+=min(a,b*(y[j]-y[j-1]));
			ans=min(ans,s);
		}
		printf("%d\n",ans);
	}
}
namespace wtf{
	void solve(){
		// plz exchange 7 points and 11 points !!1
		// this part is much more disgusting
	}
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	n=read();d=read();a=read();b=read();
	FOR(i,1,n) x[i]=read();
	if(n<=20) brute::solve();
	else wtf::solve();
}
