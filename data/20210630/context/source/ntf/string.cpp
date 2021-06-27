#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
int n,tmp[maxn],tl;
void solve(){
	n=read();
	int l=1;
	while(1ll*l*(l-1)/2<n) l++;
	int d=1ll*l*(l-1)/2-n,s=0;
	tl=0;
	ROF(i,l,1) while(1ll*i*(i-1)/2<=d && s+i<=l) tmp[++tl]=i,s+=i,d-=1ll*i*(i-1)/2;
	int cur=0;
	FOR(i,1,tl){
		FOR(j,1,tmp[i]) putchar(cur+'0');
		cur^=1;
	}
	FOR(i,1,l-s){
		putchar(cur+'0');
		cur^=1;
	}
	puts("");
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read();
	while(T--) solve();
}
