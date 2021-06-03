/*
	Author: Ruakker
	Date: 2021-05-06 08:04:39
	LastEditTime: 2021-05-06 08:35:33
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
// #define int long long
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
const int N=5005;
int n,m,q,fa[N<<1],a[N][N],sum[N][N];
inline int getfa(int x){return (fa[x]==x)?x:fa[x]=getfa(fa[x]);}
void Union(int x,int y){return fa[getfa(x)]=getfa(y),void();}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	n=read(),m=read(),q=read();
	for (int i=1;i<=n<<1;++i)
		fa[i]=i;
	for (int i=1;i<=m;++i){
		int x=read(),y=read();
		Union(x,y+n),a[x][y]=1;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (getfa(i)==getfa(j+n))
				a[i][j]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for (int i=1;i<=q;++i){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x2<x1) swap(x1,x2);
		if (y2<y1) swap(y1,y2);
		printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
	}
	return 0;
}