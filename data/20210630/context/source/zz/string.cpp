#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int T,n,m,p,k;
void work(int n,int m,int fi){
	if(!m) return;
	ll tp;
	int p=m;
	for(int i=1;i<=m;i++){
		tp=1ll*i*(m-i)+1ll*(m-i-1)*(m-i)/2;
		if(tp<n){
			p=i-1;
			break;
		}
	}
	for(int i=1;i<=p;i++) putchar(fi+'0');
	work(n-p*(m-p),m-p,fi^1);
}
void solve(int T){
	scanf("%d",&n),m=1;
	while(1ll*(m-1)*m/2<n) m++;
	work(n,m,0);
	puts("");
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve(T);
}

