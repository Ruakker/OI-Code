#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1;c=getchar(); }
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x*f;
}
const int N=1e6+5;
int p[N],chk[N],tot;
int n,f[N],s[N];
inline void init(){
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(!chk[i]){
			p[++tot]=i;
			if(i==2) f[i]=-1;
			else if(i==3) f[i]=-1;
			else{
				if(i%6==1) f[i]=1;
				else f[i]=-1;
			}
		}
		for(int j=1;j<=tot&&p[j]*i<=n;j++){
			chk[i*p[j]]=1;
			f[i*p[j]]=f[i]*f[p[j]];
			if(!(i%p[j])) break;
		}
	}
}
inline int abs(const int x) { return x<0?-x:x; }
int main(){
	fre(function);
	n=read();
	init();
	for(int i=1;i<=n;i++) printf("%d ",f[i]);
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		s[i]=s[i-1]+f[i];
//		ans=max(ans,abs(s[i]));
//	}
//	printf("%d\n",ans);
//	for(int i=1;i<=n;i++) printf("%d ",f[i]);puts("");
	return 0;
}
