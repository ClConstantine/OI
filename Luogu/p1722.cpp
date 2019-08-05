#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin; using std::cout; using std::endl; using std::cerr;

int can[110];

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    can[0]=1;

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            (can[i]+=can[j]*can[i-j-1])%=100;

        }
    }
    cout<<can[n];
    return 0;
}
