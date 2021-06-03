/*
	Author: Chocola4ever
	Date: 2021-04-25 09:37:27
	LastEditTime: 2021-04-29 22:32:02
	FilePath: \HydroOJd:\Programs\sword.cpp
	Description: RP++
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=5e5+5,S=1<<20,Mod=1e9+7;
int c[S],n,k,q,cnt[S];
char s[20];
ll fac[N],inv[N],ans[S];
ll qpow(ll a,ll b){
	ll ans=1;
	while (b){
		if (b&1) ans=a*ans%Mod;
		a=a*a%Mod,b>>=1;
	}
	return ans;
}
signed main(){
	// freopen("swords.in","r",stdin);
	// freopen("swords.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>k>>q;

	/*	转换二进制为十进制并取补集	*/
	for (int i=1;i<=n;++i){
		cin>>s;
		int x=0;
		for (int j=0;j<20;++j)
			x=(x<<1)+'1'-s[j];
		++cnt[x];
		// cout<<x<<endl;
	}

	/*	初始化 阶乘 与 阶乘的逆元	*/
	c[0]=1,fac[0]=1;
	for (int i=1;i<S;++i)
		c[i]=c[i>>1]*(i&1?-1:1);
	for (int i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%Mod;
	inv[n]=qpow(fac[n],Mod-2);
	for (int i=n-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%Mod;

	/* sos-dp:cnt 高维后缀和	*/
	for (int i=0;i<20;++i)
		for (int j=0;j<S;++j)
			if (j&(1<<i))
				cnt[j^(1<<i)]+=cnt[j];

	/*	求组合数部分	*/
	for (int i=0;i<S;++i)
		if (cnt[i]>=k)
			ans[i]=(c[i]*fac[cnt[i]]*inv[k]%Mod*inv[cnt[i]-k]%Mod+Mod)%Mod;

	/* sos-dp:ans	*/
	for (int i=0;i<20;++i)
		for (int j=0;j<S;++j)
			if (j&(1<<i))
				ans[j]=(ans[j]+ans[j^(1<<i)])%Mod;

	for (int i=1;i<=q;++i){
		cin>>s;
		int x=0;
		for (int j=0;j<20;++j)
			x=(x<<1)+s[j]-'0';	//将二进制转换为十进制（不取补集！）
		// cout<<x<<endl;
		cout<<ans[x]<<endl;
	}
	return 0;
}
/*
Input:
3 2 4
10000000000000000000
01000000000000000000
00100000000000000000
00000000000000000000
10000000000000000000
11000000000000000000
11100000000000000000

Output:
3
2
1
0
*/