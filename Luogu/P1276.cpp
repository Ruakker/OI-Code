/*
	Author: Chocola4ever
	Date: 2021-04-28 18:53:24
	LastEditTime: 2021-04-28 19:09:12
	FilePath: \HydroOJd:\Programs\P1276.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
bitset<114514> a,b;//(1,1)为树，(1,0)为树苗，(0,0)为空气
int l,n,ans1,ans2;
int main(){
	int l,n;
	scanf("%d%d",&l,&n);
	a.set(),b.set();
	int x,y,z;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x==0){
			for(int i=y;i<=z;i++){
				ans2+=a[i]^b[i];
				a.reset(i);
				b.reset(i);
			}
		}
		if(x==1)
			for(int i=y;i<=z;i++)
				a.set(i);
	}
	for(int i=0;i<=l;i++)
		ans1+=a[i]^b[i];
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}