#include <iostream>
#include <cstdio>
using namespace std;

long long m,pre,bac;

int main()
{
    cin>>m;
    pre = m >> 16;
    bac = m & ((1<<16)-1);

    cout<<(bac<<16)+pre;
    return 0;
}
