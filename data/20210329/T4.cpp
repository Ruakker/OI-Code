/*
	Author: Chocola4ever
	Date: 2021-03-29 19:57:13
	LastEditTime: 2021-03-29 21:17:09
	FilePath: \Programs\20210329\T4.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1005,Mod=1e9+7;
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
int n,k,l,r,ans=0;
ll cnt=0,a[N],dp[N][N],g[N][N];
bool b[N];
inline bool doit(ll x){
	ll res=0;
	while (x){
		if (x&1) res++;
		x>>=1;
	}
	return l<=res&&res<=r;
}
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	memset(b,0,sizeof(b));
	n=read(),k=read(),l=read(),r=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<1<<k;++i)
		if (doit(i)){
			b[i]=1,g[k][i]=1;
			for (int j=0;j<k;++j)
				if (i&(1<<j)) dp[k][i]+=a[j+1];
		}
	for (int j=k;j<=n-1;++j)
		for (int i=1;i<1<<k;++i)
			if (b[i]){
				l=i>>1;
				if (b[l]){
					dp[j+1][l]=(dp[j+1][l]+dp[j][i])%Mod;
					g[j+1][l]=(g[j+1][l]+g[j][i])%Mod;
				}
				l|=1<<(k-1);
				if (b[l]){
					dp[j+1][l]=(dp[j+1][l]+dp[j][i]+g[j][i]*a[j+1]%Mod)%Mod;
					g[j+1][l]=(g[j+1][l]+g[j][i])%Mod;
				}
			}
	for (int i=1;i<1<<k;++i)
		if (b[i]) ans=(ans+dp[n][i])%Mod;
	printf("%d",ans);
	return 0;
}