#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,b;
    cin>>a>>b;
    cout<<a*b-a-b;
    return 0;
}