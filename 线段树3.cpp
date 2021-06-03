/*
	Author: Chocola4ever
	Date: 2021-04-26 08:08:16
	LastEditTime: 2021-04-26 10:26:13
	FilePath: \Programs\线段树3.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
struct Chocola{
	int val,mxa,mxb;
}segt[N<<2];
int n,m;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
inline void build(int l,int r,int k){
	if (l>=r){
		segt[k].val=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	segt[k].val=segt[k<<1].val+segt[k<<1|1].val;
}
signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	build(1,n,1);
	return 0;
}
