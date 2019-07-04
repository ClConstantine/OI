#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;

int book[5][5]{{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int ans1=0,ans2=0,n,na,nb,t;
int sa[201],sb[201];

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>na>>nb;

    for(int i=0;i<na;i++){
        cin>>t;
        sa[i]=t;
    }

    for(int i=0;i<nb;i++){
        cin>>t;
        sb[i]=t;
    }

    for(int i=0;i<n;i++){
        if(book[sa[i%na]][sb[i%nb]]==1) ans1++;
        if(book[sa[i%na]][sb[i%nb]]==-1) ans2++;
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
