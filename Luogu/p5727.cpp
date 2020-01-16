#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

int can[1000000+10];

int main()
{
    int n;
    cin>>n;
    can[0] = 1;
    can[1] = n;
    while(n!=1){
        if(!(n&1)){
            can[++can[0]] = n/2;
            n = n/2;
        }
        else {
            can[++can[0]] = n*3+1;
            n=n*3+1;
        }
    }

    for(int i = can[0];i>0;i--){
        cout<<can[i]<<' ';
    }
    //if(can[0] == 1) cout<<1;
    return 0;
}