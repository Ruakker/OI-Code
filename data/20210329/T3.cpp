/*
	Author: Chocola4ever
	Date: 2021-03-29 19:46:10
	LastEditTime: 2021-03-29 21:12:39
	FilePath: \Programs\20210329\T3.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1005;
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
int n,Mod,ans=0,dp[N][130][10];
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	n=read(),Mod=read();
	dp[0][0][0]=1;
	for (int i=0;i<=n-1;++i)
		for (int j=0;j<=127;++j)
			for (int k=0;k<=9;++k)
				if (dp[i][j][k]>0)
					for (int p=0;p<=9;p++){
						int q=((k<<3)+(k<<1)+p)%7;
						dp[i+1][j|1<<q][q]=(dp[i+1][j|1<<q][q]+dp[i][j][k])%Mod;
					}
	for (int i=0;i<=9;i++)
		ans=(ans+dp[n][127][i])%Mod;
	printf("%lld",ans);
	return 0;
}