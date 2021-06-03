/*
	Author: Ruakker
	Date: 2021-05-08 19:07:11
	LastEditTime: 2021-05-08 20:00:29
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define lson segt[k].left
#define rson segt[k].right
#define int long long
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
const int N=1e5+5,M=1e10;
int n,L,R,rt=1,tot=1,sum[N],ans;
struct Ruakker{
	int val,left,right;
}segt[N<<5];
inline void Insert(int l,int r,int num,int &k){
	if (!k) k=++tot,segt[k].val=lson=rson=0;
	++segt[k].val;
	if (l>=r) return;
	int mid=l+r>>1;
	if (num<=mid) Insert(l,mid,num,lson);
	else Insert(mid+1,r,num,rson);
}
inline int getsum(int L,int R,int l,int r,int k){
	if (!k) return 0;
	if (L<=l&&r<=R) return segt[k].val;
	int mid=l+r>>1,s=0;
	if (L<=mid) s+=getsum(L,R,l,mid,lson);
	if (mid+1<=R) s+=getsum(L,R,mid+1,r,rson);
	return s;
}
signed main(){
	n=read(),L=read(),R=read();
	for (int i=1;i<=n;++i)
		sum[i]=read()+sum[i-1];	//get the prefix sum
	Insert(-M,M,sum[0],rt);		//remember to insert the sum[0]!
	for (int i=1;i<=n;++i)
		ans+=getsum(sum[i]-R,sum[i]-L,-M,M,rt),Insert(-M,M,sum[i],rt);
	printf("%lld\n",ans);
	return 0;
}
