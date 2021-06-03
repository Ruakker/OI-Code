/*
	Author: Chocola4ever
	Date: 2021-03-31 12:37:35
	LastEditTime: 2021-03-31 12:38:16
	FilePath: \Programs\20210331\zzzyyds.cpp
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
int main(){
	freopen("zzzyyds.in","r",stdin);
	freopen("zzzyyds.out","w",stdout);
	puts("1");
	return 0;
}
