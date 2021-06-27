/*
	Author: Ruakker
	Date: 2021-05-22 18:41:03
	LastEditTime: 2021-05-22 19:23:32
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define ppi pair<pii,int>
#define mp make_pair
#define fi first
#define se second
namespace FastIO{static const int BUFSIZE__=(1<<20)+1;static char Ibuf__[BUFSIZE__],*I1__=Ibuf__,*I2__=Ibuf__,Obuf__[BUFSIZE__],*O1__=Obuf__,*O2__=O1__+BUFSIZE__-1;static int ST__[55],Top__;inline void flush(){fwrite(Obuf__,1,O1__-Obuf__,stdout),O1__=Obuf__;}struct flusher__{~flusher__(){flush();}}IO__;inline char getch(){return I1__==I2__&&(I2__=(I1__=Ibuf__)+fread(Ibuf__,1,BUFSIZE__,stdin),I1__==I2__)?EOF:*I1__++;}inline void putch(char Ch__){*O1__++=Ch__,(O1__==O2__)?flush():void();}inline void getstr(char*S__){char Ch__=getch();int cnt__=0;for(;!isgraph(Ch__);Ch__=getch());for(;isgraph(Ch__);Ch__=getch())S__[cnt__++]=Ch__;S__[cnt__]=0;}inline void putstr(const char*S__){int Len__=strlen(S__);for(int i__=0;i__<Len__;++i__)putch(S__[i__]);}template<typename Var__>inline Var__ read(){register Var__ Res__=0,W__=1;register char Ch__=getch();for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())Res__=(Res__<<3)+(Res__<<1)+(Ch__^48);return Res__*W__;}inline double readDB(){register double ResB__=0,Cnt__=1;register char Ch__=getch();register int ResA__=0,W__=1;if(Ch__!='.'){for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResA__=(ResA__<<3)+(ResA__<<1)+(Ch__^48);if(Ch__!='.')return ResA__*W__;}Ch__=getch();for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResB__+=(Ch__^48)*(Cnt__*=0.1);return(ResA__+ResB__)*W__;}template<typename Var__>inline void write(register Var__ Num__,const char Ch__='\0'){if(!Num__)putch('0');if(Num__<0)putch('-'),Num__=-Num__;for(;Num__;ST__[++Top__]=Num__%10+'0',Num__/=10);for(;Top__;putch(ST__[Top__--]));if(Ch__!='\0')putch(Ch__);}}
using namespace FastIO;
using std::pair;
using std::mp;
const int N=2e6+5;
int fa[N],b[N],n,m;
ppi a[N];
inline void init(){for (int i=1;i<=n;++i) fa[i]=i;}
inline bool cmp(const ppi x,const ppi y){return x.se>y.se;}
inline int getfa(int x){
	return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
}
inline void Union(int x,int y){
	fa[getfa(x)]=getfa(y);
}
inline bool chk(int x,int y){return getfa(x)==getfa(y);}
inline void print(){}
signed main(){
	n=read<int>(),m=read<int>();
	init();
	for (int i=1;i<=m;++i)
		a[i].fi.fi=read<int>(),a[i].fi.se=read<int>(),a[i].se=read<int>();
	std::sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;++i){
		if (chk(a[i].fi.fi,a[i].fi.se)) return write(a[i].se,'\n'),0;
		if (!b[a[i].fi.fi]) b[a[i].fi.fi]=a[i].fi.se;
			else Union(b[a[i].fi.fi],a[i].fi.se);
		if (!b[a[i].fi.se]) b[a[i].fi.se]=a[i].fi.fi;
			else Union(b[a[i].fi.se],a[i].fi.fi);
	}
	return write(0,'\n'),0;
}
