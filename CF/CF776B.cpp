#include<iostream>
#include<cstdio>
using namespace std;
int flag[100020];
int b[10000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<n+1;i++){
        for(int j=2;i*j<=n+1;j++){
            flag[i*j]=1;
        }
    }
    if(n==1||n==2)
        printf("1\n");
    else printf("2\n");
    for(int i=2;i<=n+1;i++){
        printf("%d ",flag[i]+1);
    }
    return 0;
}
