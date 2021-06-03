/*
	Author: Chocola4ever
	Date: 2021-04-28 10:37:12
	LastEditTime: 2021-04-28 10:39:38
	FilePath: \Programs\20210428\birthday.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
int main(){
	freopen("birthday.in","r",stdin);
	freopen("birthday.out","w",stdout);
	int n=read(),m=read(),v=read();
	for (int i=1;i<=n;++i)
		read();
	for (int i=1;i<=m;++i)
		read(),read(),read();
	return 0;
}
