#include <iostream>
#include <cstdio>
#include <cstring>

bool can[50000];
bool bo=0;

using std::cin;using std::cout;using std::endl;

int main(){
    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        if(!can[i])
            for(int j=2;i*j<=n;j++){
                can[i*j]=1;
            }
    }
    can[0]=can[1]=1;

    for(int i=2;i<=n;i++){
        if(!can[i])
            for(int j=i;j<=n;j++){
                if((!can[j])&&!(can[n-i-j])&&n-i-j>1) {
                    cout<<i<<' '<<j<<' '<<n-i-j;
                    bo=1;
                    break;
                }
            }
        if(bo==1) break;
    }
    return 0;
}
