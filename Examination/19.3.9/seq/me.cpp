//score 60
#include <iostream>
#include <cstdio>

using namespace std;

int a[20000000+10];
int b[20000000+10];
int q[110],T;
int MMAX=0;
const int MOD=1000000007;

int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);

    a[1]=a[2]=a[3]=1;
    b[1]=1;b[2]=2;b[3]=3;

    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&q[i]);
        MMAX=MMAX>q[i]?MMAX:q[i];
    }
    for(int i=4;i<=MMAX;i++){
        a[i]=b[i-3]+1;
        b[i]=(b[i-1]+a[i])%MOD;
    }

    for(int i=1;i<=T;i++){
        printf("%d\n",a[q[i]]);
    }

    return 0;
}
