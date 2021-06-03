/*
	Author: Ruakker
	Date: 2021-05-03 20:56:42
	LastEditTime: 2021-05-04 14:37:29
	FilePath: \HydroOJd:\Programs\P1637.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
#define lson segt[k].left
#define rson segt[k].right
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
bool startmem;
const ll N=5e5+5,M=9223372036854775807;//M=2^63 -1
int n,a[N],tot=1,rt=1,L[N],R[N];
ll ans;
struct Ruakker{
	int left,right;
	ll sum;
}segt[N<<3];
bool endmem;
inline void Insert(int l,int r,int num,int &k){
	if (!k) k=++tot,lson=rson=segt[k].sum=0;
	if (l>=r) return segt[k].sum++,void();
	int mid=l+r>>1;
	if (num<=mid) Insert(l,mid,num,lson);
	else Insert(mid+1,r,num,rson);
	segt[k].sum=segt[lson].sum+segt[rson].sum;
}
inline ll getsum(int L,int R,int l,int r,int k){
	if (!k) return 0;
	if (L<=l&&r<=R) return segt[k].sum;
	ll mid=l+r>>1,sum=0;
	if(L<=mid) sum+=getsum(L,R,l,mid,lson);
	if(mid+1<=R) sum+=getsum(L,R,mid+1,r,rson);
	return sum;
}
signed main(){
	// printf("%d\n",abs(&startmem-&endmem)/1024);
	n=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<=n;++i)
		Insert(1,M,a[i],rt),L[i]=getsum(1,a[i]-1,1,M,rt);
	memset(segt,0,sizeof(segt));
	tot=1,rt=1;
	for (int i=n;i>=1;--i)
		Insert(1,M,a[i],rt),R[i]=getsum(a[i]+1,M,1,M,rt);
	for (int i=1;i<=n;++i)
		ans+=L[i]*R[i];
	printf("%lld\n",ans);
	return 0;
}
