#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin; using std::cout; using std::endl; using std::cerr;

const int mmax=200000;

int can[mmax+10];

int main(){

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int ans=can[0]=-1e9;
    for(int i=1;i<=N;i++){
        cin>>can[i];
        can[i]=std::max(can[i-1]+can[i],can[i]);
        ans=std::max(ans,can[i]);
    }
    cout<<ans;
    return 0;
}
