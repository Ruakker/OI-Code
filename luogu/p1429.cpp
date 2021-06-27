/*
	Author: Ruakker
	Date: 2021-05-22 15:54:53
	LastEditTime: 2021-05-22 16:28:17
*/
#include<bits/stdc++.h>
#define ll long long
// #define int long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
namespace FastIO{static const int BUFSIZE__=(1<<20)+1;static char Ibuf__[BUFSIZE__],*I1__=Ibuf__,*I2__=Ibuf__,Obuf__[BUFSIZE__],*O1__=Obuf__,*O2__=O1__+BUFSIZE__-1;static int ST__[55],Top__;inline void flush(){fwrite(Obuf__,1,O1__-Obuf__,stdout),O1__=Obuf__;}struct flusher__{~flusher__(){flush();}}IO__;inline char getch(){return I1__==I2__&&(I2__=(I1__=Ibuf__)+fread(Ibuf__,1,BUFSIZE__,stdin),I1__==I2__)?EOF:*I1__++;}inline void putch(char Ch__){*O1__++=Ch__,(O1__==O2__)?flush():void();}inline void getstr(char*S__){char Ch__=getch();int cnt__=0;for(;!isgraph(Ch__);Ch__=getch());for(;isgraph(Ch__);Ch__=getch())S__[cnt__++]=Ch__;S__[cnt__]=0;}inline void putstr(const char*S__){int Len__=strlen(S__);for(int i__=0;i__<Len__;++i__)putch(S__[i__]);}template<typename Var__>inline Var__ read(){register Var__ Res__=0,W__=1;register char Ch__=getch();for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())Res__=(Res__<<3)+(Res__<<1)+(Ch__^48);return Res__*W__;}inline double readDB(){register double ResB__=0,Cnt__=1;register char Ch__=getch();register int ResA__=0,W__=1;if(Ch__!='.'){for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResA__=(ResA__<<3)+(ResA__<<1)+(Ch__^48);if(Ch__!='.')return ResA__*W__;}Ch__=getch();for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResB__+=(Ch__^48)*(Cnt__*=0.1);return(ResA__+ResB__)*W__;}template<typename Var__>inline void write(register Var__ Num__,const char Ch__='\0'){if(!Num__)putch('0');if(Num__<0)putch('-'),Num__=-Num__;for(;Num__;ST__[++Top__]=Num__%10+'0',Num__/=10);for(;Top__;putch(ST__[Top__--]));if(Ch__!='\0')putch(Ch__);}}
using namespace FastIO;
const int N=2e5+5;
using std::pair;
using std::make_pair;
using std::vector;
pii p[N];
int n;
inline double calc(pii a,pii b){
	double x=a.fi-b.fi,y=a.se-b.se;
	return sqrt(x*x+y*y);
}
inline bool cmp(const int a,const int b){
	return p[a].se<p[b].se;
}
double mrg(int l,int r){
	if (l>=r) return inf;
	if (l+1==r) return calc(p[l],p[r]);
	int mid=l+r>>1;
	double res=std::min(
		mrg(l,mid),
		mrg(mid+1,r)
	);
	vector<int> tmp;
	for (int i=l;i<=r;++i)
		if (std::abs(p[i].fi-p[mid].fi)<res)
			tmp.push_back(i);
	sort(tmp.begin(),tmp.end(),cmp);
	for (int i=0;i<tmp.size();++i)
		for (int j=i+1;j<tmp.size();++j){
			int u=tmp[i],v=tmp[j];
			if (abs(p[u].se-p[u].se)>res) break;
			res=std::min(res,calc(p[u],p[v]));
		}
	return res;
}
signed main(){
	n=read<int>();
	for (int i=1;i<=n;++i){
		p[i].fi=read<int>();
		p[i].se=read<int>();
	}
	sort(p+1,p+1+n);
	printf("%0.4lf\n",mrg(1,n));
	return 0;
}
