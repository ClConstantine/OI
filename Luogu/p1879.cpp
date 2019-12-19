#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[20],f[20][4096+5],state[4096+5];
int n,m,t,ans;
const int mod=1e8;
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int t = 0,b;
        for(int j=0;j<n;j++){
            cin>>b;
            t=(t<<1)+b;
        }
        p[i+1]=t;
    }

    int mmax=(1<<n);

    for(int i=0;i<mmax;i++){
        state[i] = ((i&(i<<1))==0)&&((i&(i>>1))==0);
    }
    f[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<mmax;j++){
            if(state[j]&&((j|p[i])==p[i])){
                for(int k=0;k<mmax;k++){
                    if((k&j)==0)
                        (f[i][j]+=f[i-1][k])%=mod;
                }
            }
        }
    }
    for(int i=0;i<mmax;i++){
        (ans += f[m][i])%=mod;
    }
    cout<<ans;
    return 0;
}
