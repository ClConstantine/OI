#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::cerr;

const int mmax=1000000;
int st[mmax+10][20];

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N,M,l,r;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        scanf("%d",&st[i][0]);
    }
    int k=log2(N);
    for(int i=1;i<=k;++i){
        for(int j=1;j+(1<<i)-1<=N;++j){
            st[j][i]=std::max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }

    for(int i=0;i<M;++i){
        scanf("%d%d",&l,&r);
        int temp=log2(r-l+1);
        printf("%d\n",std::max(st[l][temp],st[r-(1<<temp)+1][temp]));
    }
    return 0;
}
