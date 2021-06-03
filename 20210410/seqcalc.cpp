/*
	Author: Chocola4ever
	Date: 2021-04-10 08:35:28
	LastEditTime: 2021-04-10 13:43:46
	FilePath: \Programs\20210410\seqcalc.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=5e4+5,MOD=1e9+7;
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
ll ans,temp;
int n,k,a[N],sum[N];
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seqcalc.in","r",stdin);
	freopen("seqcalc.out","w",stdout);
	int T=read();
	while (T--){
		memset(sum,0,sizeof sum);
		ans=0,temp=0;
		n=read(),k=read();
		for (int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+1+n);
		if (k==1){
			for (int i=1;i<=n;++i)
				sum[i]=(sum[i-1]+a[i])%MOD;
			for (int i=1;i<=n;++i)
				(ans+=a[i]*(i-1)%MOD-sum[i-1]+MOD)%=MOD;
			printf("%lld\n",ans);
			continue;
		}else{
			sort(a+1,a+1+n);
			for (int i=1;i<=n;++i)
				sum[i]=sum[i-1]+a[i];
			for (int i=1;i<=n;++i)
				(ans+=(a[i]*(n-1)%MOD-sum[i-1]*2%MOD+MOD)%MOD*a[i]%MOD)%=MOD;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
