/*
	Author: Ruakker
	Date: 2021-05-05 18:24:34
	LastEditTime: 2021-05-05 21:46:26
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define pb push_back
// #define int long long
using namespace std;
bool startmem;
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
const int N=5005,M=2e5+5;
int n,m,q,sum[N][N],a[N][N];
struct Ruakker{
	int x,y;
}p[M];
// struct Rekkaur{
// 	int b[N];
// 	vector<int> t;
// }inx[N],iny[N];
vector<int> inx[N],iny[N];
void work(){
	for (int line=1;line<=n;++line){//every line
		int sz=inx[line].size();
		for (int i=0;i<sz-1;++i)
			for (int j=i+1;j<sz;++j){
				int u1=inx[line][i],u2=inx[line][j];//y 坐标
				if (iny[u1].empty()||iny[u2].empty()) continue;
				for (int k=0;k<iny[u1].size();++k){
					int v=iny[u1][k];//x 坐标
					if (!a[v][u2])
						a[v][u2]=1,inx[v].pb(u2),iny[u2].pb(v);
				}
				for (int k=0;k<iny[u2].size();++k){
					int v=iny[u2][k];
					if (!a[v][u1])
						a[v][u1]=1,inx[v].pb(u1),iny[u1].pb(v);
				}
			}
	}
	for (int line=n;line>=1;--line){//every line
		int sz=inx[line].size();
		for (int i=0;i<sz-1;++i)
			for (int j=i+1;j<sz;++j){
				int u1=inx[line][i],u2=inx[line][j];//y 坐标
				if (iny[u1].empty()||iny[u2].empty()) continue;
				for (int k=0;k<iny[u1].size();++k){
					int v=iny[u1][k];//x 坐标
					if (!a[v][u2])
						a[v][u2]=1,inx[v].pb(u2),iny[u2].pb(v);
				}
				for (int k=0;k<iny[u2].size();++k){
					int v=iny[u2][k];
					if (!a[v][u1])
						a[v][u1]=1,inx[v].pb(u1),iny[u1].pb(v);
				}
			}
	}
}
bool endmem;
signed main(){
	printf("%0.3lfMiB",fabs(&startmem-&endmem)/1024.0/1024.0);
	// freopen("grid.in","r",stdin);
	// freopen("grid.out","w",stdout);
	n=read(),m=read(),q=read();
	for (int i=1;i<=m;++i)
		p[i].x=read(),p[i].y=read(),
		a[p[i].x][p[i].y]=1,
		inx[p[i].x].pb(p[i].y),iny[p[i].y].pb(p[i].x);
		// ++inx[p[i].x].b[p[i].y],++iny[p[i].y].b[p[i].x];

	work();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

	for (int i=1;i<=q;++i){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x2<x1) swap(x1,x2);
		if (y2<y1) swap(y1,y2);
		printf("%lld\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
	}
	return 0;
}