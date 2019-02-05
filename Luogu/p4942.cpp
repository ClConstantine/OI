#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long q,l,r,sum;
    scanf("%lld",&q);
    for(int i=0;i<q;i++){
        scanf("%lld%lld",&r,&l);
        sum=0;
        for(int j=r%9;j<=l%9+9;j++){
            sum+=j;
        }
        printf("%d\n",sum%9);
    }
    return 0;
}
