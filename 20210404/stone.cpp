/*
	Author: Chocola4ever
	Date: 2021-04-04 08:37:07
	LastEditTime: 2021-04-04 09:33:57
	FilePath: \Programs\20210404\stone.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e4+5,M=505;
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
int n,a[N],dp[M][M];
void init(){
	memset(a,0,sizeof(a));
}
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int T=read();
	while (T--){
		init();
		n=read();
		for (int i=1;i<=n;++i)
			a[i]=read();
		if (n==2){
			if (a[1]==a[2]) puts("Draw");
			else puts("Alice");
			continue;
		}
		int ali=0,bob=0;
		for (int l=1,r=n,k=n;k!=0;--k){
			if (k&1){
				if (ali^a[l]>ali^a[r])
					ali=ali^a[l++];
				else
					ali=ali^a[r--];
			}else{
				if (bob^a[l]>bob^a[r])
					bob=bob^a[l++];
				else
					bob=bob^a[r--];
			}
		}
		if (bob==ali) puts("Draw");
		if (bob>ali) puts("Bob");
		if (bob<ali) puts("Alice");
		printf("%d %d\n",bob,ali);
	}
	return 0;
}