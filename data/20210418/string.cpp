/*
	Author: Chocola4ever
	Date: 2021-04-18 13:58:53
	LastEditTime: 2021-04-18 15:53:47
	FilePath: \Programs\20210418\string.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// #define Debug
using namespace std;
const int N=1e6,Mod=1e9+7;
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
int n,m,s[N];
ll ans=0;
bool check(int n){
	for (int i=1;i<=(n>>1);++i)
		if (s[i]!=s[n-i+1])
			return 1;
	return 0;
}
inline void dfs(int a){
	if (a>=(n+1)>>1){
		for (int i=((n+1)>>1)+1;i<=n;++i)
			s[i]=s[n-i+1];
		bool temp=1;
		for (int i=2;i<=n-1;++i)
			if (!check(i)){
				temp=0;
				break;
			}
		if (temp){ ans=(ans+1)%Mod;
		#ifdef Debug
			for (int i=1;i<=n;++i)
				printf("%d ",s[i]);
			puts("");
		#endif
		}
		return;
	}
	for (int i=1;i<=m;++i){
		s[a+1]=i;
		dfs(a+1);
		s[a+1]=0;
	}
}
int main(){
	#ifndef Debug
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	#endif
	n=read(),m=read();
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
