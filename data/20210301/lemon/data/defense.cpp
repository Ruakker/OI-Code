#include <bits/stdc++.h>
using namespace std;
namespace io {
	const int SIZE = (1 << 19) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I &x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io::gi;
using io::putc;
using io::print;
#define SZ 1000999
short dv[SZ];
int n,m,q,l[SZ],r[SZ],*qr=r,nq[SZ],*fq=l;
int dy1[SZ],dn,dy2[SZ],nd[SZ*2],fd[SZ];
int bs[SZ],ans[SZ],*v=ans;
void edt(int x,int y) {
	for(;x<=n;x+=x&-x) bs[x]+=y;
}
int qs(int x) {
	int s=0;
	for(;x>=1;x-=x&-x) s+=bs[x];
	return s;
}
int main()
{
	gi(n); gi(m); gi(q);
	for(int i=1,v_;i<=n;++i)
		l[i]=0,r[i]=n+1,gi(v_),v[i]=v_;
	for(int i=1,a,b;i<=m;++i)
	{
		gi(a); gi(b);
		assert(a!=b);
		if(b<a) l[a]=max(l[a],b);
		else r[a]=min(r[a],b);
	}
	for(int i=1,x;i<=n;++i) {
		++dn; x=i;
			nd[dn]=fd[x]; fd[x]=dn;
		++dn; x=l[i]; dy1[dn/2]=i;
			dy2[dn/2]=r[i]; dv[dn/2]=-v[i];
			nd[dn]=fd[x]; fd[x]=dn;
	}
	for(int i=1;i<=n;++i) fq[i]=0;
	for(int i=1,ql;i<=q;++i)
		gi(ql), gi(qr[i]),
		nq[i]=fq[ql], fq[ql]=i, ans[i]=0;
	for(int i=n+1;i>=0;--i) {
		for(int d=fd[i];d;d=nd[d])
		{
			short v=dv[(d+1)/2];
			if(d&1) v=-v;
			edt(dy1[(d+1)/2],v),
			edt(dy2[(d+1)/2],-v);
		}
		for(int q=fq[i];q;q=nq[q]) ans[q]=qs(qr[q]);
	}
	for(int i=1;i<=q;++i)
		print(ans[i]),putc('\n');
}

