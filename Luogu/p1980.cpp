#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int temp,n,x,ans=0;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++){
        temp=i;
        do{
            if(temp%10==x)
                ans++;
        }while((temp/=10)>0);
    }
    printf("%d",ans);
    return 0;
}
