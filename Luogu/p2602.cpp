#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

typedef long long ll;

ll a,b;
ll cana[15],canb[15];

void work(ll x,ll can[]){
    
    ll len=1;
    while(len<=x){
        ll sur=x/len/10;
        ll pre=x%len;
        ll now=x/len%10;
        
        if(now==0){
            can[0]+=(sur-1)*len+pre+1;
        }
        else can[0]+=sur*len;

        for(int i=1;i<=9;++i){
            if(i<now){
                can[i]+=(sur+1)*len;
            }
            else if(i==now){
                can[i]+=(sur)*len+pre+1;
            }
            else{
                can[i]+=(sur)*len;
            }
        }
        len*=10;
    }
    return ;

}

int main(){

    cin>>a>>b;
    work(a-1,cana);
    work(b,canb);
    for(int i=0;i<=9;++i){
        cout<<canb[i]-cana[i]<<' ';
    }
    cout<<endl;
    return 0;
}
