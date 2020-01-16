#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;

long long n,sum=1;

int main()
{
    cin>>n;

    while(n){
        sum *= n;
        n--;
    }
    cout<<sum;

    return 0;
}