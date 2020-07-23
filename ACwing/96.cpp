#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

int f[20],d[20];

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1;i <= 12;i++){
        f[i] = f[i - 1] * 2 + 1;
    }

    std::memset(d,0x3f,sizeof(d));
    
    d[1] = 1;

    for(int i = 2;i <= 12;++i){
        for(int j = 1;j <= i;j++){
            d[i]=std::min(d[i],2 * d[j] + f[i - j]);
        }
    }

    for(int i = 1;i <= 12;++i){
        cout<<d[i]<<endl;
    }

    return 0;
}