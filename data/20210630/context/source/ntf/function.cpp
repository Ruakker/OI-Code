#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,pr[maxn],pl,mn[maxn],f[maxn],s,a1,a2;
bool vis[maxn];
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	n=read();
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>n) break;
			vis[k]=true;
			mn[k]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	a2=0;
	a1=s=f[1]=1;
	FOR(i,2,n){
		if(vis[i]) f[i]=f[i/mn[i]]*f[mn[i]];
		else{
			if(s>0) f[i]=-1;
			else if(s<0) f[i]=1; 
			else{
				if(a1>-a2) f[i]=-1;
				else f[i]=1;
			}
//			else f[i]=int(rng()%2)*2-1;
		}
//		printf("s=%d\n",s);
		a1=max(a1,s+=f[i]);
		a2=min(a2,s);
	}
	FOR(i,1,n) printf("%d ",f[i]);
//	printf("%d\n",max(a1,-a2));
}
