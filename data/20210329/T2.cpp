/*
	Author: Chocola4ever
	Date: 2021-03-29 19:44:37
	LastEditTime: 2021-03-29 20:13:30
	FilePath: \Programs\20210329\T2.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=2005,Mod=1e9+7;
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
int n,m,ans=0;
int f[N][N];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		f[1][i]=1;
	for (int i=2;i<=m;++i)
		for (int j=1;j<=n;++j)
			for (int k=j;k<=n;k+=j)
				f[i][k]=(f[i][k]+f[i-1][j])%Mod;
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j)
			ans=(ans+f[i][j])%Mod;
	printf("%d",ans);
	return 0;
}