#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin; using std::cout;using std::endl;

int n,k;
int can[100000+10];

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    can[1]=1;

    for(int i=2;i<=k;i++){
        for(int j=1;j<i;j++){
            (can[i]+=can[j])%=100003;
        }
        can[i]++;
    }

    for(int i=k+1;i<=n;i++){
        for(int j=i-k;j<i;j++){
            (can[i]+=can[j])%=100003;
        }
    }
    cout<<can[n];
    return 0;
}
