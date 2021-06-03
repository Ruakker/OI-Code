/*
	Author: Chocola4ever
	Date: 2021-04-29 18:22:07
	LastEditTime: 2021-04-29 18:28:22
	FilePath: \HydroOJd:\Programs\P2367.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
// #define int long long
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
const int N=5e6+5;
int a[N],diff[N];
int main(){
	int n=read(),p=read();
	for (int i=1;i<=n;++i)
		a[i]=read(),diff[i]=a[i]-a[i-1];
	for (int i=1;i<=p;++i){
		int x=read(),y=read(),z=read();
		diff[x]+=z,diff[y+1]-=z;
	}
	int k=0,mn=inf;
	for (int i=1;i<=n;++i){
		k+=diff[i];
		if (k<mn) mn=k;
	}
	printf("%d\n",mn);
	return 0;
}
