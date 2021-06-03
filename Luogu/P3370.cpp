/*
	Author: Ruakker
	Date: 2021-05-12 15:49:18
	LastEditTime: 2021-05-12 16:27:12
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
#define ull unsigned long long
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
void write(ll x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=10005,base=62;
int n,a[N];
ull hash(char *s){
	ull len=strlen(s+1),res=0;
	for (int i=1;i<=len;++i)
		res=res*base+(ull)s[i];
	return res;
}
signed main(){
	n=read();
	for (int i=1;i<=n;++i){
		char s[N];
		scanf("%s",s+1);
		a[i]=hash(s);
	}
	std::sort(a+1,a+1+n);
	write(std::unique(a+1,a+1+n)-a-1),putchar('\n');
	return 0;
}
