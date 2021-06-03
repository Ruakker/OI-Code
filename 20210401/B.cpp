/*
	Author: Chocola4ever
	Date: 2021-04-01 10:42:52
	LastEditTime: 2021-04-01 16:00:51
	FilePath: \Programs\20210401\B.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int __int128
using namespace std;
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
inline void print(int x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
signed main(){
	int t=read();
	for (int _=1;_<=t;++_){
		int n=read(),m=read();
		if (n>m) swap(n,m);
		int ans=n*m*(n*m-1);
		if (n>=2) ans=ans-(n-2)*(m-1)*4;
		if (m>=2) ans=ans-(n-1)*(m-2)*4;
		print(ans);
		putchar('\n');
	}
	return 0;
}