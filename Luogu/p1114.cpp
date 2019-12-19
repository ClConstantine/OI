#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mm = 100000;
int sumb=0,sumg=0,n,t;
int pre[2*mm+10],rep[2*mm+10];

int main()
{
    cin>>n;

    for(int i=1;i<=n;++i){
        cin>>t;
        t==0?sumg++:sumb++;
        int c = sumb-sumg+n;

        if(c==n) rep[c]=i;
        else if(pre[c]==0)pre[c]=i;
        else rep[c] = i;
    }

    int ans = rep[n];

    for(int i=1;i<=2*n;i++){
        if(i==n) continue;
        ans=max(rep[i]-pre[i],ans);
    }
    cout<<ans;

    return 0;
}
