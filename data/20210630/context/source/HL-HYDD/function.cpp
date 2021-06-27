#include<bits/stdc++.h>
using namespace std;
int n,cnt,f[1100000];
int lst[1100000],prime[1100000];
char pbuf[1<<20],*pp=pbuf;
void pc(char c){
    if (pp-pbuf==(1<<20)) fwrite(pbuf,1,1<<20,stdout),pp=pbuf;
    *pp++=c;
}
void myfflush(){
    fwrite(pbuf,1,pp-pbuf,stdout);
}
int main(){
//	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	n=1000000; f[1]=1;
	for (int i=2;i<=n;i++){
		if (!lst[i]){
			lst[i]=i;
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt&&i*prime[j]<=n;j++){
			lst[i*prime[j]]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
	int s=1,ans=1;
	for (int i=2;i<=n;i++){
		if (lst[i]==i) f[i]=i%3==1?1:-1;
		else f[i]=f[i/lst[i]]*f[lst[i]];
		s+=f[i]; ans=max(ans,abs(s));
	}
	for (int i=1;i<=n;i++){
		if (f[i]<0) pc('-');
		pc('1'); pc(' ');
	}
//	printf("%d\n",ans);
	myfflush();
	return 0;
}
