#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

int can[20]{6,2,5,5,4,5,6,3,7,6};
int ans;
int book[1000];

int qu(int a){
    int ans=0;
    if (a==0) ans+=6;
    else {
        while(a){
            ans+=can[a%10];
            a/=10;
        }
    }
    //cout<<ans<<endl;
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    n=n-4;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
             if(i==j){
                if(book[i]) continue;
                else book[i]=1;
            }

            if(qu(i)+qu(j)>n) continue;
            else if(qu(i)+qu(j)==n-qu(i+j)) ans++;

        }
        
    }
    cout<<ans;
    return 0;
}
