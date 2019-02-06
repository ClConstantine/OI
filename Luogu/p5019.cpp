#include<bits/stdc++.h>
using namespace std;
int n,a,b;
long long ans;
int main()
{
    scanf("%d%d",&n,&b);
    ans=b;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a>b) ans+=a-b;
        b=a;
    }
    printf("%lld",ans);
    return 0;
}
