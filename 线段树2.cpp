/*
	Author: Chocola4ever
	Date: 2021-03-20 08:23:12
	LastEditTime: 2021-04-25 18:33:43
	FilePath: \Programs\线段树2.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define inf 0x3f
using namespace std;
const int N=1e5+5;
int a[N],n,m,p,segt[N<<2];
struct Chocola{
	int add,multi;
}lztag[N<<2];
inline void build(int l,int r,int k){
	lztag[k].add=0,lztag[k].multi=1;
	if (l==r){
		segt[k]=a[l]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	segt[k]=(segt[k<<1]+segt[k<<1|1])%p;
}
inline void pushdown(int l,int r,int k){
	int mid=(l+r)>>1;
	segt[k<<1]=(segt[k<<1]*lztag[k].multi+lztag[k].add*(mid-l+1))%p;
	segt[k<<1|1]=(segt[k<<1|1]*lztag[k].multi+lztag[k].add*(r-mid))%p;
	lztag[k<<1].multi=(lztag[k<<1].multi*lztag[k].multi)%p;
	lztag[k<<1|1].multi=(lztag[k<<1|1].multi*lztag[k].multi)%p;
	lztag[k<<1].add=(lztag[k<<1].add*lztag[k].multi+lztag[k].add)%p;
	lztag[k<<1|1].add=(lztag[k<<1|1].add*lztag[k].multi+lztag[k].add)%p;
	lztag[k].add=0,lztag[k].multi=1;
}
inline ll getsum(int L,int R,int l,int r,int k){
	if (L<=l&&r<=R) return segt[k];
	int mid=(l+r)>>1;
	pushdown(l,r,k);
	ll sum=0;
	if (L<=mid) sum=(sum+getsum(L,R,l,mid,k<<1))%p;
	if (R>=mid+1) sum=(sum+getsum(L,R,mid+1,r,k<<1|1))%p;
	return sum;
}
inline void add(int L,int R,int l,int r,int num,int k){
	if (L<=l&&r<=R){
		segt[k]=(segt[k]+num*(r-l+1))%p;
		lztag[k].add=(lztag[k].add+num)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(l,r,k);
	if (L<=mid) add(L,R,l,mid,num,k<<1);
	if (R>=mid+1) add(L,R,mid+1,r,num,k<<1|1);
	segt[k]=(segt[k<<1]+segt[k<<1|1])%p;
}
inline void multi(int L,int R,int l,int r,int num,int k){
	if (L<=l&&r<=R){
		segt[k]=segt[k]*num%p;
		lztag[k].add=(lztag[k].add*num)%p;
		lztag[k].multi=(lztag[k].multi*num)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(l,r,k);
	if (L<=mid) multi(L,R,l,mid,num,k<<1);
	if (R>=mid+1) multi(L,R,mid+1,r,num,k<<1|1);
	segt[k]=(segt[k<<1]+segt[k<<1|1])%p;
}
signed main(){
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>p;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;++i){
		int opt,l,r;
		cin>>opt>>l>>r;
		if (opt==1){
			int k;
			cin>>k;
			multi(l,r,1,n,k,1);
		}
		if (opt==2){
			int k;
			cin>>k;
			add(l,r,1,n,k,1);
		}
		if (opt==3)
			cout<<getsum(l,r,1,n,1)%p<<endl;
	}
	return 0;
}

/*
Input:
5 5 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4

Output:
17
2
*/