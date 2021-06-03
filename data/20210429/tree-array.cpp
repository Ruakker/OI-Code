/*
	Author: Chocola4ever
	Date: 2021-04-29 10:51:15
	LastEditTime: 2021-04-29 12:15:25
	FilePath: \HydroOJd:\Programs\20210429\tree-array.cpp
	Description: RP++
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int lowbit(int x){return x&-x;}
const int N=5e5+5;
int t[N],a[N],n,m;
void build(){
	for (int i=1;i<=n;++i){
		t[i]+=a[i];
		int k=i+lowbit(i);
		if (k<=n) t[k]+=t[i];
	}
}
void add(int k,int num){
	while (k<=n)
		t[k]+=num,k+=lowbit(k);
}
int getsum(int k){
	int sum=0;
	while (k>0)
		sum+=t[k],k-=lowbit(k);
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	build();
	for (int i=1;i<=m;++i){
		int opt;
		cin>>opt;
		if (opt==1){
			int x,k;
			cin>>x>>k,add(x,k);
		}else{
			int l,r;
			cin>>l>>r,
			cout<<getsum(r)-getsum(l-1)<<endl;
		}
	}
	return 0;
}
