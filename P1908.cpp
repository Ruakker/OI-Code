/*
	Author: Ruakker
	Date: 2021-05-03 20:56:42
	LastEditTime: 2021-05-03 21:14:43
	FilePath: \HydroOJd:\Programs\P1908.cpp
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
const int N=5e5+5;
int n,len,a[N],disc[N];
ll segt[N<<2],ans;
inline ll getsum(int L,int R,int l,int r,int k){
	if (L<=l&&r<=R) return segt[k];
	int mid=(l+r)>>1;
	ll sum=0;
	if (L<=mid) sum+=getsum(L,R,l,mid,k<<1);
	if (mid+1<=R) sum+=getsum(L,R,mid+1,r,k<<1|1);
	return sum;
}
inline void Insert(int l,int r,int num,int k){
	++segt[k];
	if (l>=r) return ans+=getsum(r+1,n,1,n,1),void();
	int mid=(l+r)>>1;
	if (num<=mid) Insert(l,mid,num,k<<1);
	else Insert(mid+1,r,num,k<<1|1);
}
int main(){
	n=read();
	for (int i=1;i<=n;++i)
		disc[i]=a[i]=read();
	sort(disc+1,disc+1+n);
	len=unique(disc+1,disc+1+n)-disc-1;
	for (int i=1;i<=n;++i)
		a[i]=lower_bound(disc+1,disc+1+len,a[i])-disc;
	for (int i=1;i<=n;++i)
		Insert(1,n,a[i],1);
	printf("%lld\n",ans);
	return 0;
}
