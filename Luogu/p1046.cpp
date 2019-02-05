#include <cstdio>
#include <iostream>
using namespace std;
int a[20];
int main(){
    int ans=0,x;
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    for(int i=0;i<10;i++){
        if(x+30>=a[i]) ans++;
    }
    printf("%d",ans);
    return 0;
}
