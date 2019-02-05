#include<cstdio>
#include<iostream>
using namespace std;
int can[110],a[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&can[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(can[j]<can[i]) a[i]++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
