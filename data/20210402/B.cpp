/*
	Author: Chocola4ever
	Date: 2021-04-02 10:52:40
	LastEditTime: 2021-04-02 11:55:12
	FilePath: \Programs\20210402\B.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+5,M=1e4+5,Mod=1e9+7;
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
bool isdead[N];
int c[M],id[N],val[N],m;
ll n;
int main(){
	memset(isdead,0,sizeof(isdead));
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	n=read(),m=read();
	int cnt=0;
	for (int i=1;i<=m;++i){
		c[i]=read();
		for (int j=1;j<=c[i];++j)
			id[++cnt]=i;
		//isdead[cnt]=1;
	}
	for (int i=1;i<=n;++i)
		val[i]=i;
	for (int i=1;i<=c[m];++i){
		for (int i=1;i<=n;++i){
			if (id[i+1]!=id[i]||isdead[i+1])
				isdead[i]=1;
		}
		int sum=0;
		for (int i=1;i<=n;++i)
			if (!isdead[i])
				sum=(val[i]+sum)%Mod,val[i]=sum;
/*		for (int i=1;i<=n;++i)
			printf("%d ",val[i]);
		puts("");
		for (int i=1;i<=n;++i)
			printf("%d ",isdead[i]);
		puts("");*/
	}
	ll ans=0;
	for (int i=1;i<=n;++i)
		ans=(ans+val[i])%Mod;
	printf("%d\n",ans);
	return 0;
}
