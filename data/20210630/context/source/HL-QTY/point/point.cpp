#include<bits/stdc++.h>
using namespace std;
const int N=205;

int n,d,A,B,a[N];

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	n=read(),d=read(),A=read(),B=read();
	for (int i=1;i<=n;++i) a[i]=read();
	printf("%d\n",A+B*2);
	return 0;
}