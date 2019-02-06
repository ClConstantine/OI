#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool flag[25010];
int a[25010];
int main()
{
    int N,n,maxx,ans;
    scanf("%d",&N);
    while(N--){
        cin>>n;
        maxx=ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>maxx) maxx=a[i];
        }
        memset(flag,0,sizeof(flag));
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(flag[a[i]]) continue;
            ans++;
            flag[a[i]]=1;
            for(int j=a[i];j<=maxx;j++){
                if(flag[j-a[i]]) flag[j]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
