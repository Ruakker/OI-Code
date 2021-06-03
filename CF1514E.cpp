/*
	Author: Ruakker
	Date: 2021-05-12 20:40:29
	LastEditTime: 2021-05-13 12:20:24
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
ll read(){
	ll x=0,w=1;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar())
		if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar())
		x=x*10+(ch-'0');
	return x*w;
}
inline void write(ll x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){write(x),putchar('\n');}
const int N=105;
int n,t,ret;
bool ans[N][N];
std::vector<int> path;
inline bool ManyEdges(const int &x, int len){
	if (len<0) return 0;
	putchar('2'),putchar(' '),write(x),putchar(' '),write(len+1),putchar(' ');
	for (int i=0;i<=len;i++)
		write(path[i]),putchar(' ');
	puts("");
	ret=read();
	return ret;
}
bool OneEdge(int &a,int &b){
	putchar('1'),putchar(' '),write(a),putchar(' '),writeln(b);
	ret=read();
	return ret;
}
void init(){
	memset(ans,true,sizeof ans);
	path.clear();
}
int main(){
	for (int T=read();T--;){
		init();
		n=read();
		for (int i=0;i<n;i++)
			path.push_back(i);
		stable_sort(path.begin(),path.end(),OneEdge);
		int far=n-2;
		for (int i=n-1;~i;i--){
			if (far==i){
				for (int j=0;j<=i;j++)
					for (int k=i+1;k<n;k++)
						ans[path[k]][path[j]]=0;
				far--;
			}
			for (;ManyEdges(path[i],far);--far);
		}
		puts("3");
		for (int i=0;i<n;i++,puts(""))
			for (int j=0;j<n;j++)
				write(ans[i][j]);
		n=read();
	}
}
