#include <iostream>
using namespace std;
int main()
{
    int hand=0,out,summum=0,i,m=13;
    for(i=1;i<=12;i++){
        cin>>out;
        hand+=300-out;
        summum+=hand/100*100;
        hand=hand%100;
        if(hand<0){
            m=i;
            i=12;
        }
    }
    if(m==13) cout<<hand+1.2*summum;
    else cout<<-m;
    return 0;
}
