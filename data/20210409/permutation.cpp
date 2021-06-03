/*
	Author: Chocola4ever
	Date: 2021-04-09 14:12:55
	LastEditTime: 2021-04-09 15:01:36
	FilePath: \Programs\20210409\permutation.cpp
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
bool b[N];
int a[N][N],f[N];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int T=read();
	while (T--){
		int n=read();
		int temp=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j){
				a[i][j]=read();
				if (a[i][j]==n-1) temp=i;
			}
		if (temp==0){
			puts("-1");
			continue;
		}
		for (int i=1;i<=n;++i)
			f[i]=a[temp][i];
		f[temp]=n;
		bool t=1;
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;++i){
			if (b[f[i]])
				t=0;
			b[f[i]]=1;
		}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				if (i!=j&&a[i][j]!=min(f[i],f[j]))
					t=0;
		if (t){
			puts("2");
			for (int i=1;i<=n;++i)
				printf("%d ",f[i]);
			putchar('\n');
		}else puts("-1");
	}
	return 0;
}