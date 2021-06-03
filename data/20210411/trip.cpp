/*
	Author: Chocola4ever
	Date: 2021-04-11 08:08:11
	LastEditTime: 2021-04-11 09:55:10
	FilePath: \Programs\20210411\trip.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
//#define Debug
using namespace std;
const int N=5e4+5,M=2e5+5;
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
vector<int> way;
vector<int> e[N];
int n,m,k;
bool b[N];
int dp[N];	//when arrive point N,it at least costs dp[N]
void init(){
	memset(b,0,sizeof b);
	memset(dp,127,sizeof dp);
	way.clear();
	for (int i=1;i<=n;++i)
		e[i].clear();
}
int main(){
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	int T=read();
	while (T--){
		n=read(),m=read(),k=read();
		init();
		int temp=read();
		way.push_back(temp);
		b[temp]=1;
		for (int i=1;i<=k;++i){
			temp=read();
			b[temp]=1;
			e[way[i-1]].push_back(temp);
			e[temp].push_back(way[i-1]);
			way.push_back(temp);
		}
		for (int i=k+1;i<=m;++i){
			int u=read(),v=read();
			if (b[u]&&b[v]){
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}
		dp[1]=1;
		for (int i=2;i<=n;++i) if (b[i])
			for (int j=0;j<e[i].size();++j)
				if (b[e[i][j]]) dp[i]=min(dp[i],dp[e[i][j]]+1);
		#ifdef Debug
			for (int i=1;i<=n;++i)
				printf("%d ",dp[i]);
			putchar('\n');
		#endif
		printf("%d\n",dp[n]);
	}
	return 0;
}
/*
3
7 8 5
1 2 3 4 5 7
1 3
3 6
6 7

10 8 5
1 3 5 7 9 10
1 5
3 10
7 10

10 8 5
1 2 3 4 5 10
1 4
3 10
2 3
*/