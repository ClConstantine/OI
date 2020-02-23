#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::cout;using std::cerr;

long long n,ans=1;
const long long mod =1e9+7;

void qp(long long x){
    long long b=3;

    if(x&1){
        ans*=3;
    }
    x>>=1;
    
    while(x){
        (b*=b)%=mod;
        if(x&1){
            (ans*=b)%=mod;
        }
        x>>=1;
    }
    return;
}



int main(){

    cin>>n;

    if(n<=3){
        cout<<n;
    }
    
    else {
        if(n%3==0){
            qp(n/3);
        }
        else if(n%3==1){
            ans*=4;
            qp((n-4)/3);
        }
        else {
            ans*=2;
            qp((n-2)/3);
        }
        cout<<ans;
    
    }


    return 0;
}
