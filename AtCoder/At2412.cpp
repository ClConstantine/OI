#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl; using std::cerr;

const int mmax=110000;
int can[mmax+10],book[mmax+10];
int res;

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N,k;
    cin>>N>>k;
    for(int i=1;i<=N;++i){
        cin>>can[i];
    }

    for(int i=1;i<=k;++i){
        book[k]+=can[i];
    }

    res=book[k];

    for(int i=k+1;i<=N;++i){
        book[i]=book[i-1]+can[i]-can[i-k];
        if(book[i]>res) res=book[i];
    }
    cout<<res<<endl;
    return 0;
}
