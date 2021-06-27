#include<bits/stdc++.h>
using namespace std;
const int N = 1000001, M = N/10;
bool notp[N], f[N];
int pri[M], tot, sum;
char obf[N*3], *O = obf;
int main(){
	freopen("function.out", "w", stdout);
	notp[0] = notp[1] = true; sum = f[1] = 1;
	*O++ = '1';
	for(int i = 2;i < N;++ i){
		if(!notp[i]){pri[tot++] = i; f[i] = sum > -395;}
		*O++ = ' ';
		if(f[i]) *O++ = '-', --sum; else ++sum;
		*O++ = '1';
		for(int j = 0;j < tot && i * pri[j] < N;++ j){
			notp[i*pri[j]] = true;
			f[i*pri[j]] = f[pri[j]]^f[i];
			if(!(i % pri[j])) break;
		}
	} fwrite(obf, 1, O-obf, stdout);
}
