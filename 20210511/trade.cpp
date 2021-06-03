/*
	Author: Ruakker
	Date: 2021-05-11 18:08:16
	LastEditTime: 2021-05-11 20:28:41
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// #define int long long
// #define min(a,b) (a)<(b)?(a):(b)
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
const int N=20,Num=16;
int n,m,ans,a[N],t,dp[(1<<Num)+5][N];
bool cmp(int a,int b){return a>b;}
signed main(){
	// freopen("trade.in","r",stdin),freopen("trade.out","w",stdout);
	memset(dp,inf,sizeof dp);
	n=read(),m=read();
	for (int i=1;i<=m;++i){
		int x=read(),y=read(),v=read();
		a[x]+=v,a[y]-=v;
	}
	for (int i=1;i<=n;++i)
		dp[0][i]=!a[i]?1:0;
	for (int i=0;i<1<<n;++i)
		for (int j=1;j<=n;++j)
			if (i&1<<j)
				for (int k=1;k<=n;++k)
					dp[i][j]=std::min(dp[i][j],dp[i^1<<j][k]+1);
	for (int i=1;i<=n;++i)
		ans=std::min(ans,dp[(1<<n)-1][i]);
	for (int i=0;i<1<<n;++i){
		for (int j=1;j<=n;++j)
			printf("%d ",dp[i][j]);
		puts("");
	}
	printf("%d\n",ans);
	return 0;
}
