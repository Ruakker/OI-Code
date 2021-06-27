#include <bits/stdc++.h>
#define N 1000006
using namespace std;
int g[N],n,pri[N],num,p[N],sum=1,maxx,now,ans=1e9,res;
bool tag[N];
void init(){
	n=1e6;
	int a;
	cout<<"1 ";
	for(int i=2;i<=n;i++){
		if(!tag[i]) pri[++num]=i,g[i]=1,p[i]=(num&1&&num>7)?1:-1;
		for(int j=1;j<=num&&(a=pri[j]*i)<=n;j++){
			tag[a]=1,p[a]=p[pri[j]]*p[i];
			if(i%pri[j]==0) break;
		}
		cout<<p[i]<<' ';
	}
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	init();
}
