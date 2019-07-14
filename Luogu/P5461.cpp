#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::cerr;

int n;
int can[1100][1100];
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin>>n;
    n=1<<n;
    can[1][n]=1;
    for(int i=2;i<=n;i++){
        for(int j=n;j>n-i;j--){
            can[i][j]=(can[i-1][j]+can[i-1][j+1])%2;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<can[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
