/*---Author:HenryHuang---*/
/*---Never Settle---*/
/*---Never Enough---*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=155;
int x[maxn],y[maxn];
double pos[maxn*3];
int cnt;
ll f[maxn][maxn];
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,d,a,b;cin>>n>>d>>a>>b;
	for(int i=1;i<=n;++i) cin>>x[i];
	sort(x+1,x+n+1);
	ll ans=(1ll<<60);
	if(n<=20){
		for(int s=0;s<(1<<n);++s){
			for(int i=1;i<=n;++i)
				if((1<<(i-1))&s) y[i]=x[i]-d;
				else y[i]=x[i]+d;
			memset(f,63,sizeof f);
			f[0][0]=0;
			for(int i=1;i<=n;++i)l
				for(int j=i;j<=n;++j)
					for(int k=0;k<j;++k)
						f[i][j]=min(f[i-1][k]+1ll*(y[j]-y[k+1])*b+a,f[i][j]);
			for(int i=1;i<=n;++i) ans=min(ans,f[i][n]);
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;++i) pos[++cnt]=x[i]-0.5;
	pos[++cnt]=x[n]+0.5;
	sort(pos+1,pos+cnt+1);
	cnt=unique(pos+1,pos+cnt+1)-pos-1;
	for(int o=1;o<=cnt;++o){
		for(int i=1;i<=n;++i) 
			if(x[i]>pos[o]) y[i]=x[i]-d;
			else y[i]=x[i]+d;
		sort(y+1,y+n+1);
		memset(f,63,sizeof f);
		f[0][0]=0;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				for(int k=0;k<j;++k)
					f[i][j]=min(f[i-1][k]+1ll*(y[j]-y[k+1])*b+a,f[i][j]);
		for(int i=1;i<=n;++i) ans=min(ans,f[i][n]);
	}
	cout<<ans<<'\n';
	return 0;
}