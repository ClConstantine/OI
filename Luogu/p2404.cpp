#include <iostream>
#include <cstdio>
using namespace std;
int N,cnt=0;
int map0[10];
int can[10];
void sao(int x){
    if(x==0){
        if(can[1]==N)
            return ;
        else {
            cout<<can[1];
            for(int i=2;i<=cnt;i++){
                cout<<'+'<<can[i];
            }
            cout<<endl;
            return ;
        }
    }
    else{
        for(int i=can[cnt];i<=N&&x-i>=0;i++){
            if(i>=map0[cnt]){
                    cnt++;
                    can[cnt]=i;
                    sao(x-i);
                    cnt--;
            }
        }
    }
    return ;
}
int main()
{
    cin>>N;
    can[0]=1;
    sao(N);
    return 0;
}
