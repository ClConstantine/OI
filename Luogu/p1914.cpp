#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;

char can[100];

int main(){
    int n;
    cin>>n;
    n%=26;
    
    cin>>can;

    int len = strlen(can);
    for(int i=0;i<len;i++){
        int b=0;
        while(b<n){
            can[i]=can[i]=='z'?'a':can[i]+1;
            b++;
        }
    }
    cout<<can;
    return 0;
}
