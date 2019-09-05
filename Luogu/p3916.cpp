#include <iostream>
#include <cstdio>
#include <vector>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax=100000;
int m,n;

std::vector<int> can[mmax+10];
bool book[mmax+10];
int father[mmax+10];

void dfs(int x){
        std::vector<int>::iterator it;
        for(it=can[x].begin();it!=can[x].end();it++){
            if(!book[*it]){
                book[*it]=1;
                if(father[x]>father[*it])
                    father[*it]=father[x];
                dfs(*it);
            }
        }
    return ;
}

int main(){
    int u,v;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        can[v].push_back(u);
    }
    for(int i=n;i>0;i--){
        if(!book[i]){
            book[i]=1;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<father[i]<<' ';
    return 0;
}
