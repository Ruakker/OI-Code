#include<bits/stdc++.h>
using namespace std;
const int N=1000005;

int n,cnt=0;
int factor[N],prime[N];
int f[N];
bool isprime[N];

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

inline int Abs(int x){ return (x<0) ? (-x) : (x); }

inline void write(int x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

inline void Sieve(){
	memset(isprime,1,sizeof(isprime));
	f[1]=1;
	for (int i=2;i<=N-5;++i){
		if (isprime[i]){
			prime[++cnt]=i;
			factor[i]=i;
			if (i>17) f[i]=(cnt%2) ? (1) : (-1);
			else if (i==2) f[i]=1;
			else if (i==3) f[i]=-1;
			else if (i==5) f[i]=-1;
			else if (i==7) f[i]=-1;
			else if (i==11) f[i]=-1;
			else if (i==13) f[i]=-1;
			else if (i==17) f[i]=-1;
		}
		for (int j=1;j<=cnt && i*prime[j]<=N-5;++j){
			isprime[i*prime[j]]=0;
			factor[i*prime[j]]=prime[j];
			f[i*prime[j]]=f[i]*f[prime[j]];
			if (factor[i]==prime[j]) break;
		}
	}
}

int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	srand(time(NULL));
	n=read();
	Sieve();
	int ans=0,sum=0;
	for (int i=1;i<=n;++i){
		sum=sum+f[i];
		ans=max(ans,Abs(sum));
	}
	for (int i=1;i<=n;++i) write(f[i]),putchar(' ');
	putchar('\n');
	// printf("ans=%d\n",ans);
	return 0;
}