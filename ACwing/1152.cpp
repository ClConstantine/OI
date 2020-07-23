#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long n,k;

int main()
{
    cin>>n>>k;
    k = (k ^ (k>>1)) ;
    for(unsigned long long i=n;i>0;i--){
        cout<<((k>>(i-1))&1);
    }

    return 0;
}
