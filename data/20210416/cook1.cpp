/*
	Author: Chocola4ever
	Date: 2021-04-16 08:03:39
	LastEditTime: 2021-04-17 10:04:54
	FilePath: \Programs\20210416\cook1.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
//#define Debug
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
int x,f;
int l[N];
bool a[N][1005];
int main(){
	int T=read();

	while (T--){
		memset(l,0,sizeof(l));
		memset(a,0,sizeof(a));
		int n=read();
		for (int i=1;i<=n;++i){
			x=read(),l[i]=read(),f=read();
			for (int j=x;j<=N;j+=f)
				a[j][i]=1;
		}
		int cnt=1,k=0;
		for (;k<=N;){
			if (a[k][cnt])
				k+=l[cnt++];
			else ++k;
			if (cnt>n) break;
		}
		printf("%d\n",k);
	}

	return 0;
}
