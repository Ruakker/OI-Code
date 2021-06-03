/*
	Author: Chocola4ever
	Date: 2021-04-02 18:13:10
	LastEditTime: 2021-04-02 18:58:32
	FilePath: \Programs\20210402-2\B.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1;
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
int num[20];/*
int main(){
	int T=read();
	for (;T;T--){
		int minnum=inf,minid;
		bool goout=0;
		for (int i=0;i<=9;++i){
			num[i]=read();
			if (i==0) ++num[i];
			if (minnum>num[i]){
				minnum=num[i];
				minid=i;
			}
		}
		if (minid==1&&minnum==1){
			puts("10");
			continue;
		}
		if (minid==0) putchar('1'),minnum--;
		for (int i=1;i<=minnum+1;++i)
			printf("%d",minid);
		putchar('\n');
	}
	return 0;
}
*/

ll T,x,id,minn,flag;
int main(){
	T=read();
	while (T--) {
		minn=1e18;
		for (int i=0;i<=9;i++) {
			x=read();
			if (i==0) x++;
			if (x<minn) {
				minn=x;
				id=i;
			}
		}
		if (id==0) {
			printf("%d",1);
			minn--;
		}
		for (int i=0;i<=minn;i++)
			printf("%d",id);
		puts("");
	}
	return 0;
}
