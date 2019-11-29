#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;

const int mmax=1e5;
char can[mmax+10];
int dp[mmax+10];

int main(){
    /*
    »ù´¡dp
    */
    cin>>can+1;
    int len = strlen(can+1),ans=0;
    for(int i=1;i<=len;i++){
        if(can[i]=='0'){
            dp[i]=std::max(dp[i-1]+1,dp[i]);

        }
        else{
            dp[i]=std::max(dp[i-1]-1,dp[i]);
        }
        ans=std::max(dp[i],ans);
    }
    if(ans==0) ans = -1;
    cout<<ans;

    return 0;
}
