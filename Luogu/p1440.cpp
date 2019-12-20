#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

using std::cin;using std::cerr;using std::cout;using std::endl;
using std::min;

const int mmax = 2e6;
int n,m,head=1,tail=2;
int can[mmax+10][2];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    scanf("%d%d%d",&n,&m,&can[1][0]);
    can[1][1]=1;
    printf("0\n");

    int t;

    for(int i=2;i<=n;i++){
        if(i-can[head][1]>m)head++;

        printf("%d\n",can[head][0]);

        scanf("%d",&t);

        while(tail>head && t<can[tail-1][0]){
            tail--;
        }
        can[tail][0]=t,can[tail][1]=i;

        tail++;
    }


    return 0;
}
