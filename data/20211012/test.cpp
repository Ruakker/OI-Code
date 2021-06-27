#include<bits/stdc++.h>
using namespace std;

void disc(std::vector<int> &a) {
    std::vector<int> disc = a;
    std::sort(disc.begin(), disc.end());
    auto ed = std::unique(disc.begin(), disc.end());
    for (unsigned i = 0; i < a.size(); ++i)
        a[i] = std::lower_bound(disc.begin(), ed, a[i]) - disc.begin() + 1;
}
signed main(){
    std::vector<int> a = {0,3,2,5312,4213,32,321,321,231,5312};
    for (auto e:a) cout<<e<<' ';
    cout<<endl;
    disc(a);
    for (auto e:a) cout<<e<<' ';
    cout<<endl;
    
}
