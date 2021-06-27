#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,tot,vis[N],prime[N],mu[N],ans;
void init() {
	mu[1]=1;
	int now=-1;
	for(int i=2;i<=n;i++) {
		if(!vis[i]) {
			tot++;
			prime[tot]=i;
			mu[i]=now;
			now=-now;
		}
		for(int j=1;j<=tot;j++) {
			if(prime[j]*i>n) break;
			vis[i*prime[j]]=1;
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
			if(i%prime[j]==0) break;
		}
	}
	return;
}
int main() {
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++) printf("%d ",mu[i]);
	puts("");
	return 0;
} 
