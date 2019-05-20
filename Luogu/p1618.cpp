#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;

bool can[15];
int a,b,c;
bool bo=0;

bool pan(int x){
     int y=x/a*b,z=x/a*c;
     while(x){
         if(x%10==0) return 0;
         if(can[x%10]==0){
             can[x%10]=1;
             x/=10;
         }
         else return 0;
     }
     while(y){
         if(y%10==0) return 0;
         if(can[y%10]==0){
             can[y%10]=1;
             y/=10;
         }
         else return 0;
     }
     while(z){
         if(z%10==0) return 0;
         if(can[z%10]==0){
             can[z%10]=1;
             z/=10;
         }
         else return 0;
     }
     return 1;
}

void shu(int x){
    cout<<x<<' ';
    cout<<x/a*b<<' ';
    cout<<x/a*c<<endl;
    bo=1;
}

int main(){

    cin>>a>>b>>c;
    for(int i=100;i<=999;i++){
        if(i/a*c>=1000) break;
        memset(can,0,sizeof(can));
        if(i%a==0){
            if(pan(i)){
                shu(i);
            }
        }
    }
    if(!bo){
        cout<<"No!!!";
    }
    return 0;
}
