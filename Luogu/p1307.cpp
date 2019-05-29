#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;
int N;
int main(){
    cin>>N;
    if(N<0) {
    cout<<'-';
    N=-N;
    }
    while(N%10==0) N/=10;
    while(N){
        cout<<N%10;
        N/=10;
    }
    return 0;
}
