#include<iostream>
using namespace std;
int main()
{
    int i,a,b,t=0,w=8;
    for(i=1;i<=7;i++){
        cin>>a>>b;
        if(a+b>w){
            w=a+b;
            t=i;
        }
    }
    cout<<t;
    return 0;
}
