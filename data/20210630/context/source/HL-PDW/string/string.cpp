#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005],T,tot;
vector<int> v;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;;i++) {
		a[i]=(i)*1ll*(i-1)/2;
		tot=i;
		if(a[i]>1500000000) break;
	}
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		if(n==1) {
			puts("01");
			continue;
		}
		int k;
		for(int i=1;i<=tot;i++) {
			if(a[i]>=n) {
				k=i;
				break;
			}
		}
		if(a[k]==n) {
			for(int i=1;i<=k;i++) {
				if(i&1) putchar('0');
				else putchar('1');
			}
			puts("");
			continue;
		}
		int t=a[k]-n;
		v.clear();
		for(int i=tot;i>=1;i--) {
			while(t>=a[i]) {
				t-=a[i];
				v.push_back(i);
			}
			if(!t) break;
		}
		int sz=v.size(),now=0,sum=0;
		for(int i=0;i<sz;i++) {
			now^=1;
			for(int j=1;j<=v[i];j++) putchar('0'+now);
			sum+=v[i];
		}
		for(int i=sum+1;i<=k;i++) {
			now^=1;
			putchar('0'+now);
		}
		puts("");
	}
	return 0;
}
