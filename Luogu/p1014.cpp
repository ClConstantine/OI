#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;
int n,i,a,b;
int main(){
    cin>>n;
    for(i=1;;i++){
        if(i*(i+1)/2>=n) break;
    }
    n-=(i-1)*i/2;
    a=i;b=1;
    for(;n>1;n--){
        a--;b++;
    }
    cout<<a<<'/'<<b;
    return 0;
}
