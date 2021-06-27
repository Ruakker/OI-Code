/*
	Author: Ruakker
	Date: 2021-06-25 23:44:43
	LastEditTime: 2021-06-26 00:28:10
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
const int N=2000005;
int n,a[N],b[N],flag[N],ans;
signed main() {
	int T;
	scanf("%lld",&T);
	for (;T--;){
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) 
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			flag[a[i]]++,b[a[i]]=i;
		for(int i=1;i*1ll*i<=2*n;i++) {
			if(!flag[i]) continue;
			for(int j=i+1;j*i*1ll<=2*n;j++) {
				if(!flag[j]) continue;
				if(a[b[i]]*1ll*a[b[j]]==b[i]+b[j]) ans++;
			}
		}
		for(int i=1;i<=n;i++) flag[a[i]]--;
		printf("%lld\n",ans);
	}
	return 0;
}
