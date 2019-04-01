#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::endl;

long long T,N,L,R,X,K,ans,tempv,tempn=1,x,y,k=0;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>N>>L>>R>>X>>K;
    tempv=L;
    while(T--){   
        cin>>x;
        if(x==0){
            if(++tempn>N){
                ans=-1;
                break;
            }
            else {
                tempv=L;
            }
        }
        else if(x==1){
            if(--tempn<1){
                ans=-1;
                break;
            }
            else tempv=R;
        }
        cin>>y;
        if(y==0){
            ans+=tempv*tempn;
        }
        else{
            tempv=std::min(tempv+X,R);
            ans+=tempv*tempn;
        }
        if(tempv==R){
            k++;
            if(k==K){
                break;
            }
        }
        else k=0;
    }
    cout<<ans;
    return 0;
}
