#include <bits/stdc++.h>
using namespace std;
int T,n,f[1000010],pr[1000010],p=0;
bool isnt[1000010];
void write(int x){
	if(x<0) return putchar('-'),write(-x);
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void init(int N){
	f[1]=1;
	for(int i=2;i<=N;i++){
		if(!isnt[i]){
			pr[++p]=i;
			f[i]=-1;
		}
		for(int j=1;j<=p&&pr[j]*i<=N;j++){
			isnt[pr[j]*i]=1;
			f[pr[j]*i]=f[pr[j]]*f[i];
			if(i%pr[j]==0) break;
		}
	}
	int res=0;
	for(int i=1,s=0;i<=N;i++) s+=f[i],res=max(res,abs(s));
	cerr<<res<<"\n";
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout); 
	scanf("%d",&n),init(n);
	for(int i=1;i<=n;i++) write(f[i]),putchar(' ');putchar('\n');
}

