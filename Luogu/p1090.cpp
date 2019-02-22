#include <iostream>
#include <cstdio>
#include <set>

using std::cin; using std::cout; using std::endl; using std::cerr;

std::multiset<int> can;

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n,temp;
    long long ans=0;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        can.insert(temp);
    }

    while(can.size()!=1){
        std::multiset<int>::iterator it=can.begin();
        temp=*it;
        it++;
        temp+=*it;
        can.erase(can.begin()); can.erase(can.begin());
        ans+=temp;
        can.insert(temp);
    }
    printf("%lld",ans);
    return 0;
}
