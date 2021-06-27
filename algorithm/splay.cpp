/*
	Author: Ruakker
	Date: 2021-05-11 15:16:49
	LastEditTime: 2021-05-13 19:49:32
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
inline ll read(){
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
inline void writeln(ll x){write(x),putchar('\n');}
signed main(){

	return 0;
}
