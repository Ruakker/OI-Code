#include <stdint.h>
#include "testlib.h"
using namespace std;
typedef pair<int,int> pii;
set<pii> st;
int n,m,u[1000001],v[1000001],k,a[1000000],d[1000001],f[1000001];
bool vis[1000001];
int main(int argc,char *argv[]){
    if(argc>=3){
        char *argv_[]={argv[0],argv[1],argv[2],argv[2]};
        registerTestlibCmd(4,argv_);
    }else{
        quitf(_fail,"Program must be run with the following arguments: <input-file> <output-file>");
    }
    n=inf.readInt(1,1000000,"n");
    m=inf.readInt(0,1000000,"m");
    for(int i=1;i<=m;++i){
        ++d[u[i]=inf.readInt(1,n)],++d[v[i]=inf.readInt(1,n)];
        ensure(u[i]!=v[i]);
        if(u[i]>v[i])
            swap(u[i],v[i]);
        ensure(!st.count(pii(u[i],v[i])));
        st.insert(pii(u[i],v[i]));
    }
    k=ouf.readInt(0,(n+m+1)>>1);
    for(int i=0;i<k;++i){
        a[i]=ouf.readInt(1,m);
        quitif(vis[a[i]],_wa,"A %d",a[i]);
        vis[a[i]]=true;
        ++f[u[a[i]]],++f[v[a[i]]];
    }
    for(int i=1;i<=n;++i)
        quitif(((d[i]+1)>>1)>f[i],_wa,"B %d",i);
    quitf(_ok," ");
}
