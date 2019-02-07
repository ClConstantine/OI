#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::cerr;using std::endl;

int a[15];
bool book[15];
int N,ans;
void sao(int x){
    if(x==N+1){
        ans++;
        if(ans<=3){
            for(int i=1;i<=N;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    else{
        for(int i=1;i<=N;i++){
            if(!book[i]){
                int j;
                for(j=1;j<=x-1;j++){
                    if(abs(j-x)==abs(a[j]-i)) break;
                }
                if(j==x){
                    book[i]=1;
                    a[x]=i;
                    sao(x+1);
                    book[i]=0;
                }
            }
        }
    }
    return ;
}
int main(){
    cin>>N;
    sao(1);
    cout<<ans;
    return 0;
}
