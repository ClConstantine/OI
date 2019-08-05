#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin; using std::cout; using std::endl; using std::cerr;

using std::max;

int can[1001][1001];
int ans=-1e9;

int main(){

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int R;
    cin>>R;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=i;j++){
            cin>>can[i][j];
            can[i][j]+=max(can[i-1][j],can[i-1][j-1]);
            if(i==R) ans=max(ans,can[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
