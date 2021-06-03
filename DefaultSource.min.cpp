/*
	Author: Ruakker
	Date: 2021-05-17 07:59:20
	LastEditTime: 2021-05-17 10:18:03
*/
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
namespace FastIO{static const int BUFSIZE=(1<<20)+1;static char Ibuf[BUFSIZE],*I1=Ibuf,*I2=Ibuf,Obuf[BUFSIZE],*O1=Obuf,*O2=O1+BUFSIZE-1;static int Top=0,ST[55];inline void flush(){fwrite(Obuf,1,O1-Obuf,stdout),O1=Obuf;}struct flusher{~flusher(){flush();}}IO;inline char getch(){return I1==I2&&(I2=(I1=Ibuf)+fread(Ibuf,1,BUFSIZE,stdin),I1==I2)?EOF:*I1++;}inline void putch(char x){*O1++=x,(O1==O2)?flush():void();}template<typename Var>inline Var read(){Var res=0,w=1;char ch=getch();for(;!isdigit(ch);ch=getch())if(ch=='-')w=-1;for(;isdigit(ch);ch=getch())res=(res<<3)+(res<<1)+(ch^48);return res*w;}template<typename Var>inline void write(Var num){if(!num)putch('0');if(num<0)putch('-'),num=-num;for(;num;ST[++Top]=num%10+'0',num/=10);for(;Top;putch(ST[Top--]));}template<typename Var>inline void writeln(Var num){write<Var>(num),putch('\n');}inline void getstr(char*s){char ch=getch();int cnt=0;for(;!isgraph(ch);ch=getch());for(;isgraph(ch);ch=getch())s[cnt++]=ch;s[cnt]=0;}inline void putstr(const char*s){int len=strlen(s);for(int i=0;i<len;++i)putch(s[i]);}}using namespace FastIO;

signed main(){

	return 0;
}
