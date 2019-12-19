#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mm = 5000;
int sum[mm+10][mm+10],r,n,x,y,v;

int main()
{
    cin>>n>>r;

    for(int i=0;i<n;i++){
        cin>>x>>y>>v;
        sum[x+1][y+1]=v;
    }

    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            sum [i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans=0;

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<sum[i][j]<<' ';
        }
        cout<<endl;
    }*/

    for(int i=r;i<=5001;i++){
        for(int j=r;j<=5001;j++){
           ans = max(ans,sum[i][j]-sum[i-r][j]-sum[i][j-r]+sum[i-r][j-r]);
        }
    }

    cout<<ans;
    return 0;
}
