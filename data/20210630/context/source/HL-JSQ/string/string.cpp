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
int main(){
	fre(string);
	int T=read();
	while(T--){
		int n=read();
		ll len=2;
		while(len*(len-1)/2<n) len++;
		if(n==len*(len-1)/2){
			for(int i=1;i<=len;i++) putchar((i&1)?'0':'1');
			puts("");
			continue;
		}
	}
	return 0;
}
