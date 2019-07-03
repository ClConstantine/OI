#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

int n,temp;
bool b=0;
int main(){
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>temp;

        if(temp==0) continue;
        else if(!b){
            if(temp==-1)cout<<'-';
            else if(temp!=1) cout<<temp;
            b=1;
        }
        else if(temp>1){
            cout<<'+'<<temp;
        }
        else if(temp==1) cout<<'+';
        else if(temp==-1) cout<<'-';
        else if(temp<-1) cout<<temp;

        if(i==0&&(temp==1||temp==-1)) cout<<1; 
        
        if(i==1) cout<<'x';
        else if(i!=0) cout<<"x^"<<i;
    }

    return 0;
}
