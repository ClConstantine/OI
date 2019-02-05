#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[10010];
int L,M,sta,end,ans=0;
int main(){
    scanf("%d%d",&L,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&sta,&end);
        for(int i=sta;i<=end;i++)
            map[i]=1;
    }
    for(int i=0;i<=L;i++){
        if(map[i]==0) ans++;
    }
    printf("%d",ans);
    return 0;
}
