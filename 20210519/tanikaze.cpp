/*
	Author: Ruakker
	Date: 2021-05-19 13:53:10
	LastEditTime: 2021-05-19 15:30:55
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
bool STARTMEM;
namespace FastIO{static const int BUFSIZE__=(1<<20)+1;static char Ibuf__[BUFSIZE__],*I1__=Ibuf__,*I2__=Ibuf__,Obuf__[BUFSIZE__],*O1__=Obuf__,*O2__=O1__+BUFSIZE__-1;static int ST__[55],Top__;inline void flush(){fwrite(Obuf__,1,O1__-Obuf__,stdout),O1__=Obuf__;}struct flusher__{~flusher__(){flush();}}IO__;inline char getch(){return I1__==I2__&&(I2__=(I1__=Ibuf__)+fread(Ibuf__,1,BUFSIZE__,stdin),I1__==I2__)?EOF:*I1__++;}inline void putch(char Ch__){*O1__++=Ch__,(O1__==O2__)?flush():void();}inline void getstr(char*S__){char Ch__=getch();int cnt__=0;for(;!isgraph(Ch__);Ch__=getch());for(;isgraph(Ch__);Ch__=getch())S__[cnt__++]=Ch__;S__[cnt__]=0;}inline void putstr(const char*S__){int Len__=strlen(S__);for(int i__=0;i__<Len__;++i__)putch(S__[i__]);}template<typename Var__>inline Var__ read(){register Var__ Res__=0,W__=1;register char Ch__=getch();for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())Res__=(Res__<<3)+(Res__<<1)+(Ch__^48);return Res__*W__;}inline double readDB(){register double ResB__=0,Cnt__=1;register char Ch__=getch();register int ResA__=0,W__=1;if(Ch__!='.'){for(;Ch__<'0'||Ch__>'9';Ch__=getch())if(Ch__=='-')W__=-1;for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResA__=(ResA__<<3)+(ResA__<<1)+(Ch__^48);if(Ch__!='.')return ResA__*W__;}Ch__=getch();for(;Ch__<='9'&&Ch__>='0';Ch__=getch())ResB__+=(Ch__^48)*(Cnt__*=0.1);return(ResA__+ResB__)*W__;}template<typename Var__>inline void write(register Var__ Num__,const char Ch__='\0'){if(!Num__)putch('0');if(Num__<0)putch('-'),Num__=-Num__;for(;Num__;ST__[++Top__]=Num__%10+'0',Num__/=10);for(;Top__;putch(ST__[Top__--]));if(Ch__!='\0')putch(Ch__);}}
using namespace FastIO;
const int N=5005,P=1e9+7;
struct Edge{
	int nxt,to;
}e[N<<1];
int head[N],tote=1,dgr[N],n,st;
using std::cerr;
using std::endl;
inline void adde(int x,int y){e[++tote].to=y;e[tote].nxt=head[x];head[x]=tote;}
namespace Task3{
	int path[N],pos[N],ans[N];
	void dfs(int u,int pre,int k){
		// cerr<<k<<endl;
		for (int i=head[u];i;i=e[i].nxt){
			if (e[i].to==pre) continue;
			path[k]=e[i].to;
			dfs(e[i].to,u,k+1);
		}
	}
	void Main(){
		path[1]=st;
		dfs(st,-1,2);
		for (int i=1;i<=n;++i)
			pos[path[i]]=i;
		if (n&1){
			for (int i=1;i<=n;++i) //at node i,position: pos[i]
				ans[i]=path[n+1-pos[i]];
			// for (int i=1;i<=n;++i)
			// 	cerr<<ans[i]<<' ';
			// cerr<<endl;
			for (int i=(n>>1)+1;i<=n;++i)
				ans[path[i]]=path[i-(n>>1)];
		}else{
			for (int i=1;i<=n;++i)
				ans[i]=path[n+1-pos[i]];
		}
		for (int i=1;i<=n;++i)
			write<int>(ans[i],' ');
		putch('\n');
		// for (int i=1;i<=n;++i)
		// 	cerr<<path[i]<<' ';
		// cerr<<endl;
	}
}
bool ENDMEM;
signed main(){
	freopen("tanikaze.in","r",stdin),freopen("tanikaze.out","w",stdout);
	// cerr<<abs(&STARTMEM-&ENDMEM)/1024.0/1024.0<<endl;
	n=read<int>();
	for (int i=1;i<n;++i){
		int u=read<int>(),v=read<int>();
		adde(u,v),adde(v,u),++dgr[u],++dgr[v];
	}
	int tot=0;
	bool flag=1;
	for (int i=1;i<=n;++i){
		if (dgr[i]==1)
			++tot,st=i;
		if (dgr[i]>2) flag=0;
	}
	if (tot==2&&flag) Task3::Main();
	return 0;
}
