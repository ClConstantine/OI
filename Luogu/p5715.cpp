#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::max;using std::min;using std::sort;
int can[5];
int main()
{
    cin>>can[0]>>can[1]>>can[2];
    sort(can,can+3);
    for(int i=0;i<3;i++){
        cout<<can[i]<<' ';
    }
    return 0;
}