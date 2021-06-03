/*
	Author: Ruakker
	Date: 2021-05-03 20:56:42
	LastEditTime: 2021-05-12 08:51:00
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
int lowbit(int x){return x&-x;}
const int N=5e6+5;
int len,n,m,p[3][N],t[3][N],ans,a[N];
char s[N];
void ins(int pos,int num,int tp){for (;pos<=n;pos+=lowbit(pos),t[tp][pos]+=num);}
int getsum(int pos,int tp){
	int sum=0;
	for (;pos<=n;pos-=lowbit(pos),sum+=t[tp][pos]);
	return sum;
}
signed main(){
	freopen("snow.in","r",stdin),freopen("snow.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n>>s+1;
	for (int i=1;i<=n;++i){
		a[i]=s[i]-'0';
		p[0][i]=p[0][i-1];
		p[1][i]=p[1][i-1];
		p[2][i]=p[2][i-1];
		++p[a[i]][i];
	}
	ll ans=n*(n+1)>>1;
	for (int tp=0;tp<=2;++tp)
		for (int i=n;i>=1;--i) {
            int val=i-2*p[tp][i]+N;
            ans-=getsum(val-1,tp);
            ins(val,1,tp);
        }
	std::cout<<ans<<std::endl;
	return 0;
}