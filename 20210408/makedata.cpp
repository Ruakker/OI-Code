/*
	Author: Chocola4ever
	Date: 2021-04-08 15:16:07
	LastEditTime: 2021-04-08 15:36:47
	FilePath: \Programs\20210408\makedata.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1000;
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
	freopen("love.in","w",stdout);
	srand(time(0));
	printf("%d\n",N);
	for (int i=1;i<=N;++i)
		printf("%d ",rand()&1?1:-1);
	puts("");
	for (int i=1;i<=N;++i)
		printf("%d ",rand()*rand()*rand()%(ll)2e9-(ll)1e9);
	putchar('\n');
	return 0;
}
