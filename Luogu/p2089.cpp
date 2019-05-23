#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

int n;
int can[20];
int ans;

void sao1(int x,int y){
    if(y==11){
        if(x!=n) return ;
        ans++;
        return ;
    }
    for(int i=1;i<=3;i++){
        can[y]=i;
        sao1(x+i,y+1);
    }
}

void sao(int x,int y){
    if(y==11){
        if(x!=n) return ;

        for(int i=1;i<=10;i++){
            cout<<can[i]<<' ';
        }
        cout<<endl;
        ans++;
        return ;
    }
    for(int i=1;i<=3;i++){
        can[y]=i;
        sao(x+i,y+1);
    }
}

int main(){
    cin>>n;
    if(n>30||n<10) cout<<0;
    else {
        sao1(0,1);
        cout<<ans<<endl;
        sao(0,1);
    }
    return 0;
}
