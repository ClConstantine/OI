#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int ans=0,tans=0,last=-10,temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp>last){
            tans++;
            if(tans>ans) ans=tans;
        }
        else tans=1;
        last=temp;
    }
    cout<<ans;
    return 0;
}
