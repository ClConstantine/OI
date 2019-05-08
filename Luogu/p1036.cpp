#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin; using std::cout; using std::endl;

int n,k;
int can[30];
int book[30];
int ans=0;

void dfs(int sum,int num,int now){
    if(now==k){
        int up=sqrt(sum),i;
        for(i=2;i<=up;i++){
            if(sum%i==0) break;
        }
        if(i*i>sum) ans++;
        return ;
    }

    for(int i=num+1;i<=n;i++){
        if(!book[i]){
            book[i]=1;
            dfs(sum+can[i],i,now+1);
            book[i]=0;
        }
    }
    return ;
} 

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>can[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
