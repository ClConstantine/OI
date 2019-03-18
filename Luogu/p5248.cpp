// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::endl;

long long can[20000000];

int main(){
    long long m,f,ans=0;
    cin>>m>>f;
    for(int i=0;f!=0;++i){
        can[i]=f%m;
        f/=m;
        ans++;
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<can[i]<<' ';
    }
    return 0;
}
