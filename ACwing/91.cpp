#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax = 20;
int ovo[mmax + 10][mmax + 10],f[1<<20][20];
int n;

int main(){
    
    cin>>n;
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            cin>>ovo[i][j];
        }
    }
        
    memset(f,0x3f,sizeof(f));
    f[1][0] = 0;
        
    for(int i = 1;i <= 1<<n;++i){
        for(int j = 0;j < n;++j){
            if((i>>j) & 1){
                for(int k = 0;k < n;++k){
                    if((i ^ (1<<j)) >> k & 1){
                        f[i][j] = std::min(f[i][j],f[i ^ (1 << j)][k] + ovo[k][j]);
                    }
                }
            }   
        }
    }
        
    cout<<f[(1<<n)-1][n-1];
    return 0;
}