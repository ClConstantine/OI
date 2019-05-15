#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::endl;

bool ish(int x){
    int y=x,ans=0;
    while(y){
        ans*=10;
        ans+=y%10;
        y/=10;
    }
    if(ans==x) return 1;
    return 0;
}

bool isp(int x){
    int y=sqrt(x);
    for(int i=2;i<=y;i++){
        if(!(x%i)) return 0;
    }
    return 1;
}

int main(){
    int s,e;
    cin>>s>>e;
    for(int i=5;i<=11;i+=2){
        if(i==9) continue;
        if(i<s) continue;
        else if(i>e) break;
        if(ish(i)) cout<<i<<endl;
    }
    for(int i=100;i<=100000000;i*=100){
        if(i*100<s) continue;
        else if(i>e) break;
        for(int j=i+1;j<=i*10;j+=2){
            if(j<s) continue;
            else if(j>e) break;
            if(ish(j)&&isp(j)) cout<<j<<endl;
        }
    }
    return 0;
}
