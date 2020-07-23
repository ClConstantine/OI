#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

int n,m;
int ans[30];
bool f[30];

void dfs(int x){
    if(x == m + 1){
        for(int i = 1;i <= m;++i){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        return ;
    }
    
    for(int i = ans[x - 1] + 1;i <= n;++i){
        if(!f[i]){
            ans[x] = i;
            f[i] = 1;
            dfs(x + 1);
            f[i] = 0;
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    dfs(1);

    return 0;
}