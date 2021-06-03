/*
	Author: Chocola4ever
	Date: 2021-04-11 09:05:11
	LastEditTime: 2021-04-11 10:09:48
	FilePath: \Programs\20210411\group.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define Debug
using namespace std;
const int N=1005;
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
int a[N],n,cnt=0;//if a[i]<0 then it means the number of 0,if a[i]=0 then it means that it has been done,else it mean the people
int main(){
	int T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;++i){
			int temp=read();
			if (temp==0){
				if (a[cnt]>=0)
					--a[++cnt];
				else --a[cnt];
			}
			else a[++cnt]=temp;
		}
		if (a[1]>0){
			a[1]=0,a[2]=
		}
		if (a[n]!=0){
			int m=a[n];
			for (int i=n;i>=n-m+1;--i)
				a[i]=-1;
		}
		#ifdef Debug
			for (int i=1;i<=n;++i)
				printf("%d ",a[i]);
			puts("");
		#endif
	}
	return 0;
}
