#include<iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;
typedef long long ll;

ll k;

int pow(int a,int b){
    ll result=1,base=a;
    while(b){
        if(b&1){
            result=(result*base)%k;
        }
        b>>=1;
        base=base*base%k;
    }
    return result%k;
}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    ll b,p;
    cin>>b>>p>>k;
    cout<<b<<'^'<<p<<" mod "<<k<<'='<<pow(b,p);
    return 0;
}
