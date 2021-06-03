/*
	Author: Chocola4ever
	Date: 2021-03-31 08:01:33
	LastEditTime: 2021-03-31 20:03:33
	FilePath: \Programs\20210331\nnntxdy.cpp
	Description: RP++
	nnntxdy是怎么回事呢？就让小编来给大家解释一下吧！
	其实nnntxdy，就是nnn AK IOI了。小编也感到奇怪，可事实就是如此。
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=20,Mod=998244353;
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
inline ll qpow(ll a,ll b){
    ll ans=1;
    while (b){
		if (b&1) ans=a*ans%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return ans;
}
int n,m,a[N];
ll ans=0;
inline void dfs(int cnt,ll sum,int m){
	if (m<0){
		ans=(ans+cnt*qpow(sum,Mod-2)%Mod)%Mod;
		return;
	}
	for (int i=1;i<=n;++i)
		if (a[i]) --a[i],dfs(cnt+(a[i]==0),sum*(n-cnt),m-1),++a[i];
}
int main(){
//	freopen("nnntxdy.in","r",stdin);
//	freopen("nnntxdy.out","w",stdout);
	n=read(),m=read();
	if (m>8) {puts("1");return 0;}
	for (int i=1;i<=n;++i)
		a[i]=read();
	dfs(0,1,m-1);
	printf("%lld",ans);
	return 0;
}
