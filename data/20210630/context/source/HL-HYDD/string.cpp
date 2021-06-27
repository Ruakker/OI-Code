#include<bits/stdc++.h>
using namespace std;
int T,n;
char pbuf[1<<20],*pp=pbuf;
void pc(char c){
    if (pp-pbuf==(1<<20)) fwrite(pbuf,1,1<<20,stdout),pp=pbuf;
    *pp++=c;
}
void myfflush(){
    fwrite(pbuf,1,pp-pbuf,stdout);
}
void solve(int x,int n,int u){
	while (true){
		assert(x>1);
		if (n==(x-1)*(x-2)/2+1){
			if (x==2){
				pc(u+'0'); pc((u^1)+'0');
				break;
			}
			if (x==3){
				pc(u+'0');
				pc((u^1)+'0'); pc((u^1)+'0');
				break;
			}
			if (x==4){
				pc(u+'0'); pc(u+'0');
				pc((u^1)+'0'); pc((u^1)+'0');
				break;
			}
			pc(u+'0'); pc(u+'0'); pc(u+'0');
			x-=3; n-=3*x; u^=1;
			continue;
//			solve(x-3,n-3*(x-3),u^1);
//			return;
		}
		pc(u+'0');
//		solve(x-1,n-(x-1),u^1);
		x--; n-=x; u^=1;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int x=sqrt(2*n);
		while ((x*(x-1)>>1)<n) x++;
		solve(x,n,0); pc('\n');
	}
	myfflush();
	return 0;
}
