#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;

char can[100+10];

int main()
{
    cin>>can;
    int len = strlen(can);

    for(int i=0;i<len;i++){
        if(can[i]>='a'&&can[i]<='z'){
            can[i]-=32;
        }
        cout<<can[i];
    }

    return 0;
}