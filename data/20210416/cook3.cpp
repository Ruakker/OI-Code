/*
	Author: Chocola4ever
	Date: 2021-04-16 09:40:56
	LastEditTime: 2021-04-16 10:05:57
	FilePath: \Programs\20210416\cook3.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=2005;
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
int n,a[N],b[N],l,r,mid,ans;
bool check(int mid){
	int s=0;
	for (int i=1;i<=n;++i)
		if (b[i]>mid){
			s+=a[i];
			if (a[i]>mid)
				return 0;
		}
	return (s<=2*mid);
}
int main(){
	int T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;++i)
			b[i]=read(),a[i]=read();
		l=0,r=1e6;
		while (l<=r){
			mid=(l+r)>>1;
			if (check(mid)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
