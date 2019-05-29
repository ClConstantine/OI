#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;
double k=1,x,s,ans;

int main(){
    cin>>s>>x;
    while(ans<s-x){
        ans+=7*k;
        k*=0.98;
    }
    ans+=7*k;
    if(ans>=s-x&&ans<=s+x){
        cout<<'y';
    }
    else cout<<'n';
    return 0;
}
