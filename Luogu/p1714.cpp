#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

multiset<long long> can;
const int mm=5e5;
long long sum[mm+10],m,n;

int main()
{
    cin>>n>>m;

    long long ans = 0;

    for(int i=1;i<=n;i++){
        cin>>sum[i];
        ans=max(ans,sum[i]);
        sum[i]+=sum[i-1];
    }
    set<long long>::iterator it;

    for(int i=1;i<=n;i++){
        can.insert(sum[i]);
        it =can.begin();
        ans = max(ans,sum[i]-(*it));
        if(i<m) continue;
        can.erase(can.find(sum[i-m+1]));

    }

    cout<<ans;



    return 0;
}
