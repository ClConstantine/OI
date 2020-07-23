#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

int n;
bool f[20];
int ans[20];

void dfs(int x){
    if(x == n + 1) return ;

    for(int i = ans[x - 1] + 1;i <= n;++i){
        if(!f[i]){
            f[i] = 1;
            ans[x] = i;
            for(int j = 1;j <= x;++j){
                cout<<ans[j]<<' ';
            }
            cout<<endl;
            dfs(x + 1);
            f[i] = 0;
        }
    }
}

int main(){
    
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    cout<<endl;
    dfs(1);

    return 0;
}