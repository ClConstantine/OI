#include<iostream>
#include<cstdio>
using namespace std;
int su[5000000];
int prime[10000000];
int main()
{
    int N,M,i,j,now;
    prime[1]=1;
    scanf("%d%d",&M,&N);
    for(i=2;i<=M;i++){
        if(!prime[i]){
            su[++su[0]]=i;
        }
        for(j=1;j<=su[0]&&i*su[j]<=M;j++){
            prime[i*su[j]]=1;
            if(i%su[j]==0) break;
        }
    }
    for(i=0;i<N;i++){
        scanf("%d",&now);
        if(!prime[now])
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
