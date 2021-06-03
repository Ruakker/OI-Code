/*
	Author: Chocola4ever
	Date: 2021-04-26 08:08:16
	LastEditTime: 2021-04-26 18:25:34
	FilePath: \Programs\序列操作.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f
#define int long long
// #define Debug
using namespace std;
const int N=5e6+5;
int a[N];
struct Chocola{
	int sum,lsum1,rsum1,conti1;
	int lsum0,rsum0,conti0;
}segt[N<<2];
struct Forever{
	int modi,rev;
}lztag[N<<2];
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
void pushdown(int l,int r,int k){
	int mid=l+r>>1;
	if(lztag[k].modi!=-1){
		lztag[k].rev=0;
		int val=lztag[k].modi;
		segt[k<<1].sum=(mid-l+1)*val;
		segt[k<<1|1].sum=(r-mid)*val;

		lztag[k<<1].modi=lztag[k<<1|1].modi=val;
		lztag[k<<1].rev=lztag[k<<1|1].rev=0;

		if (val==1){
			segt[k<<1].conti1=segt[k<<1].lsum1=segt[k<<1].rsum1=mid-l+1;
			segt[k<<1].conti0=segt[k<<1].lsum0=segt[k<<1].rsum0=0;
			segt[k<<1|1].conti1=segt[k<<1|1].lsum1=segt[k<<1|1].rsum1=r-mid;
			segt[k<<1|1].conti0=segt[k<<1|1].lsum0=segt[k<<1|1].rsum0=0;
		}else{
			segt[k<<1].conti0=segt[k<<1].lsum0=segt[k<<1].rsum0=mid-l+1;
			segt[k<<1].conti1=segt[k<<1].lsum1=segt[k<<1].rsum1=0;
			segt[k<<1|1].conti0=segt[k<<1|1].lsum0=segt[k<<1|1].rsum0=r-mid;
			segt[k<<1|1].conti1=segt[k<<1|1].lsum1=segt[k<<1|1].rsum1=0;
		}
		lztag[k].modi=-1;
	}
	if(lztag[k].rev){
		segt[k<<1].sum=(mid-l+1)-segt[k<<1].sum;
		segt[k<<1|1].sum=(r-mid)-segt[k<<1|1].sum;

		if (lztag[k<<1].modi!=-1)
			lztag[k<<1].modi^=1;
		else lztag[k<<1].rev^=1;
		if (lztag[k<<1|1].modi!=-1)
			lztag[k<<1|1].modi^=1;
		else lztag[k<<1|1].rev^=1;

		swap(segt[k<<1].lsum1,segt[k<<1].lsum0);
		swap(segt[k<<1].rsum1,segt[k<<1].rsum0);
		swap(segt[k<<1].conti1,segt[k<<1].conti0);

		swap(segt[k<<1|1].lsum1,segt[k<<1|1].lsum0);
		swap(segt[k<<1|1].rsum1,segt[k<<1|1].rsum0);
		swap(segt[k<<1|1].conti1,segt[k<<1|1].conti0);

		lztag[k].rev=0;
	}

	lztag[k].rev=0;
	lztag[k].modi=-1;
}
void pushup(int l,int r,int k){
	int mid=l+r>>1;
	segt[k].sum=segt[k<<1].sum+segt[k<<1|1].sum;

	segt[k].lsum1 = segt[k<<1].lsum1;
	if (segt[k<<1].sum==mid-l+1)
		segt[k].lsum1+=segt[k<<1|1].lsum1;
	segt[k].rsum1=segt[k<<1|1].rsum1;
	if (segt[k<<1|1].sum==r-mid)
		segt[k].rsum1+=segt[k<<1].rsum1;

	segt[k].conti1=segt[k<<1].rsum1+segt[k<<1|1].lsum1;
	segt[k].conti1=max(segt[k].conti1,segt[k<<1].conti1);
	segt[k].conti1=max(segt[k].conti1,segt[k<<1|1].conti1);

		segt[k].lsum0=segt[k<<1].lsum0;
		if (segt[k<<1].sum==0)
			segt[k].lsum0+=segt[k<<1|1].lsum0;

		segt[k].rsum0=segt[k<<1|1].rsum0;
		if (segt[k<<1|1].sum==0)
			segt[k].rsum0+=segt[k<<1].rsum0;

		segt[k].conti0=segt[k<<1].rsum0+segt[k<<1|1].lsum0;
		segt[k].conti0=max(segt[k].conti0,segt[k<<1].conti0);
		segt[k].conti0=max(segt[k].conti0,segt[k<<1|1].conti0);

}
inline void build(int l,int r,int k){
	lztag[k].modi=-1,lztag[k].rev=0;
	if (l>=r){
		segt[k].sum=segt[k].lsum1=segt[k].rsum1=segt[k].conti1=a[l];
		segt[k].lsum0=segt[k].rsum0=segt[k].conti0=!a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	pushup(l,r,k);
}
inline void modify1(int L,int R,int l,int r,int k){
	pushdown(l,r,k);
	if (L<=l&&r<=R){
		segt[k].sum=segt[k].lsum1=segt[k].rsum1=segt[k].conti1=r-l+1;
		segt[k].lsum0=segt[k].rsum0=segt[k].conti0=0;
		lztag[k].modi=1;
		lztag[k].rev=0;
		return;
	}
	int mid=l+r>>1;
	if (L<=mid) modify1(L,R,l,mid,k<<1);
	if (mid+1<=R) modify1(L,R,mid+1,r,k<<1|1);
	pushup(l,r,k);
}
inline void modify0(int L,int R,int l,int r,int k){
	pushdown(l,r,k);
	if (L<=l&&r<=R){
		segt[k].sum=segt[k].lsum1=segt[k].rsum1=segt[k].conti1=0;
		segt[k].lsum0=segt[k].rsum0=segt[k].conti0=r-l+1;
		lztag[k].modi=0;
		lztag[k].rev=0;
		return;
	}
	int mid=l+r>>1;
	if (L<=mid) modify0(L,R,l,mid,k<<1);
	if (mid+1<=R) modify0(L,R,mid+1,r,k<<1|1);
	pushup(l,r,k);
}
inline void Reverse(int L,int R,int l,int r,int k){
	pushdown(l,r,k);
	if (L<=l&&r<=R){
		segt[k].sum=r-l+1-segt[k].sum;
		swap(segt[k].lsum1,segt[k].lsum0);
		swap(segt[k].rsum1,segt[k].rsum0);
		swap(segt[k].conti1,segt[k].conti0);
		lztag[k].rev^=1;
		return;
	}
	int mid=l+r>>1;
	if (L<=mid) Reverse(L,R,l,mid,k<<1);
	if (mid+1<=R) Reverse(L,R,mid+1,r,k<<1|1);
	pushup(l,r,k);
}
inline int getsum(int L,int R,int l,int r,int k){
	pushdown(l,r,k);
	if (L<=l&&r<=R)
		return segt[k].sum;
	int mid=l+r>>1;
	int sum=0;
	if (L<=mid) sum+=getsum(L,R,l,mid,k<<1);
	if (mid+1<=R) sum+=getsum(L,R,mid+1,r,k<<1|1);
	return sum;
}
inline Chocola getconti(int L,int R,int l,int r,int k){
	pushdown(l,r,k);
	if (L==l&&R==r)
		return segt[k];
	int mid=l+r>>1;
	if (R<=mid)
		return getconti(L,R,l,mid,k<<1); else
	if (mid+1<=L)
		return getconti(L,R,mid+1,r,k<<1|1);
	else{
		Chocola ret,Left=getconti(L,mid,l,mid,k<<1),Right=getconti(mid+1,R,mid+1,r,k<<1|1);
		ret.sum=Left.sum+Right.sum;
		ret.lsum1=Left.lsum1;
		if (Left.sum==mid-l+1)
			ret.lsum1+=Right.lsum1;
		ret.rsum1=Right.rsum1;
		if (Right.sum==r-mid)
			ret.rsum1+=Left.rsum1;
		ret.conti1=Left.rsum1+Right.lsum1;
		ret.conti1=max(ret.conti1,Left.conti1);
		ret.conti1=max(ret.conti1,Right.conti1);

		ret.lsum0=Left.lsum0;
		if (Left.sum==0)
			ret.lsum0+=Right.lsum0;
		ret.rsum0=Right.rsum0;
		if (Right.sum==0)
			ret.rsum0+=Left.rsum0;
		ret.conti0=Left.rsum0+Right.lsum0;
		ret.conti0=max(ret.conti0,Left.conti0);
		ret.conti0=max(ret.conti0,Right.conti0);
		return ret;
	}
}
signed main(){
	// freopen("operation.in","r",stdin);
	// freopen("operation.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	build(1,n,1);
	for (int i=1;i<=m;++i){
		int opt=read(),l=read()+1,r=read()+1;
		if (opt==0)
			modify0(l,r,1,n,1);
		if (opt==1)
			modify1(l,r,1,n,1);
		if (opt==2)
			Reverse(l,r,1,n,1);
		if (opt==3)
			printf("%lld\n",getsum(l,r,1,n,1));
		if (opt==4)
			printf("%lld\n",getconti(l,r,1,n,1).conti1);
		#ifdef Debug
			for (int i=1;i<=n;++i)
				printf("%lld ",getsum(i,i,1,n,1));
			puts("");
		#endif
	}
	return 0;
}
/*
Input:
10 10
0 0 0 1 1 0 1 0 1 1
1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9

Output:
5
2
6
5
*/