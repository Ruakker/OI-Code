#include<bits/stdc++.h>
using namespace std;
const int N = 45000, M = 301, K = 2.3e7;
int T, n, ha[M], ok[N];
char obf[K], *O = obf;
int C2(int x){return x*(x-1)>>1;}
void solve(){
	scanf("%d", &n);
	int k = sqrt(n<<1);
	while(C2(k) < n) ++ k;
	int rm = C2(k) - n;
	if(!rm){
		for(int i = 0;i < k;++ i) *O++ = '0'|(i&1);
		*O++ = '\n'; return;
	}
	for(int a = 2;ha[a] <= rm;++ a){
		if(ha[a] == rm){
			for(int i = 0;i < a;++ i) *O++ = '0';
			for(int i = a;i < k;++ i) *O++ = '1'^(i-a&1);
			*O++ = '\n'; return;
		}
		for(int b = 2, c;b < M && ha[a] + ha[b] <= rm;++ b){
			if(ha[a] + ha[b] == rm && a+b <= k){
				for(int i = 0;i < a;++ i) *O++ = '0';
				for(int i = 0;i < b;++ i) *O++ = '1';
				for(int i = a+b;i < k;++ i) *O++ = '0'^(i-a-b&1);
				*O++ = '\n'; return;
			}
			if((c = ok[rm-ha[a]-ha[b]]) && a+b+c <= k){
				for(int i = 0;i < a;++ i) *O++ = '0';
				for(int i = 0;i < b;++ i) *O++ = '1';
				for(int i = 0;i < c;++ i) *O++ = '0';
				for(int i = a+b+c;i < k;++ i) *O++ = '1'^(i-a-b-c&1);
				*O++ = '\n'; return;
			}
		}
	}
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 2;i < M;++ i)
		ok[ha[i] = C2(i)] = i;
	while(T --) solve();
	fwrite(obf, 1, O-obf, stdout);
}
