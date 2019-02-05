#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,n;
    double ans=0;
    scanf("%d",&n);
    for(i=1;;i++){
        ans+=1.0/i;
        if(ans>n) break;
    }
    printf("%d",i);
    return 0;
}
