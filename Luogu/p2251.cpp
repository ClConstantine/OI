#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using std::cin;using std::cout;using std::endl;

const int mmax=1e6;
int st[mmax+10][20];

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    st±í
    */
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>st[i][0];
    }

    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            st[j][i]=std::min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            //cout<<j<<" "<<i<<' '<<st[j][i]<<endl;
        }
    }

    int t=log2(m);

    for(int i=1;i<=n-m+1;i++){
        cout<<std::min(st[i][t],st[i+m-(1<<t)][t])<<endl;
    }
    //cout<<t;

    return 0;
}
