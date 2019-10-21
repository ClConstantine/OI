#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::cerr;using std::endl;

int n,m;
bool can[110];

int main(){

    cin>>n>>m;
    int max=n;
    int f1=1,now=0;
    while(n){
        if(f1==max+1) f1=1;

        if(can[f1]==0){
            now++;
        }
        if(now==m){
            now=0;
            can[f1]=1;
            cout<<f1<<' ';
            n--;
        }
        f1++;
    }

    return 0;
}
