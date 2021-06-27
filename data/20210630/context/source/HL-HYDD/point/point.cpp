#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,d,a,b,m,x[210000],y[210000],f[210000],g[210000],dp[2100000]; bool vis[210000];
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d%d%d",&n,&d,&a,&b); b=min(a,b);
	d<<=1;
	for (int i=1;i<=n;i++) scanf("%d",&x[i]),x[i]+=d,vis[x[i]]=true;
	sort(x+1,x+n+1); n=unique(x+1,x+n+1)-x-1; m=x[n];
	if (d<=16){
		for (int s=0;s<(1<<d);s++) f[s]=INF;
		f[0]=0;
		for (int i=1;i<=m;i++){
			for (int s=0;s<(1<<d);s++) g[s]=INF;
			for (int s=0;s<(1<<d);s++){
				g[(s>>1)|(1<<(d-1))]=min(g[(s>>1)|(1<<(d-1))],f[s]+((s>>(d-1)&1)?b:a));
				if (!vis[i]||(s&1)) g[s>>1]=min(g[s>>1],f[s]);
			}
			for (int s=0;s<(1<<d);s++) f[s]=g[s];	
		}
		int ans=INF;
		for (int s=0;s<(1<<d);s++) ans=min(ans,f[s]);
		printf("%d\n",ans);
		return 0;
	}
	if (n<=20){
		int ans=INF;
		for (int s=0;s<(1<<n);s++){
			for (int i=1;i<=n;i++)
				if (s>>(i-1)&1) y[i]=x[i]-d;
				else y[i]=x[i];
			sort(y+1,y+n+1); dp[0]=0;
			for (int i=1;i<=n;i++){
				dp[i]=INF;
				for (int j=0;j<i;j++)
					dp[i]=min(dp[i],dp[j]+a+(y[i]-y[j+1])*b);
			}
			ans=min(ans,dp[n]);
		}
		printf("%d\n",ans);
		return 0;
	}
	if (a==b){
		int ans=0;
		for (int i=1;i<=m;i++)
			if (vis[i]){
				if (i>=d&&vis[i-d]) vis[i-d]=false;
				else ans++;
				vis[i]=false;
			}
		printf("%d\n",ans*a); return 0;
	}
	return 0;
}
