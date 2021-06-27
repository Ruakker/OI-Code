#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;

int T,n;

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

inline int getlen(){
	int l=1,r=max(n,(int)10),res=-1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (mid*(mid-1)/2>=n){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}

namespace Subtask1{

	const int N1=1005;
	int len;
	int a[N1],ans[N1];
	bool tot[2],flag;

	inline int calc(){
		int res=0;
		for (int i=1;i<=len-1;++i){
			tot[0]=tot[1]=false;
			tot[a[i]]=true;
			for (int j=i+1;j<=len;++j){
				tot[a[j]]=true;
				if (tot[0] && tot[1]) ++res;
			}
		}
		return res;
	}
	
	inline void dfs(int now){
		if (flag) return;
		if (now==len+1){
			if (calc()==n){
				flag=true;
				for (int i=1;i<=len;++i) ans[i]=a[i];
				// printf("len=%d\n",len); for (int i=1;i<=len;++i) printf("%d",a[i]); printf("\n");
			}
			return;
		}
		a[now]=0; dfs(now+1);
		a[now]=1; dfs(now+1);
	}

	inline void Main(){
		flag=false;
		for (len=1;len<=max(n,(int)10);++len){
			dfs(1); if (flag) break;
		}
		for (int i=1;i<=len;++i)
			printf("%d",ans[i]);
		printf("\n");
	}

}

namespace Subtask2{

	int len;
	vector <int> pos;

	inline void Main(){
		len=getlen();
		pos.clear();
		// printf("len=%lld\n",len);
		int lst=0,row=0;
		for (int i=1;i<=len;++i){
			int val=(i-lst)*(len-i+1)-1;
			if ((lst>0) && (lst==i-1)) val-=(row*(row+1)/2);
			if (val<0) continue;
			// printf("i=%lld : val=%lld row=%lld\n",i,val,row);
			if ((n>0) && (val<=n)){
				n-=val; lst=i; ++row;
				pos.push_back(i);
			}
			else row=0;
		}
		int siz=(int)(pos.size()),now=0;
		for (int i=1;i<=len;++i){
			if (now>=siz){ putchar('0'); continue; }
			if (pos[now]==i){ putchar('1'); ++now; }
			else putchar('0');
		}
		putchar('\n');
	}

}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while (T--){
		n=read();
		if (n<=170) Subtask1::Main();
		else Subtask2::Main();
	}
	return 0;
}