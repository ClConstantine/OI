#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;



int main(){
    int m,s,t;

    cin>>m>>t>>s;
    
    if(t==0) cout<<m;
    else if(t*m<s) cout<<0;
    else if(s%t == 0) cout<<m-s/t;
    else cout<<m-s/t-1;

    return 0;
}