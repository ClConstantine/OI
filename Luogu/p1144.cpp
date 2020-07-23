#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using std::cin;using std::cout;using std::endl;using std::cerr;using std::string;

const int nmax = 1000000,mmax = 2000000,mod = 100003;
int head[nmax + 10],next[mmax * 2 + 10],ver[mmax * 2 + 10];
int tot,n,m,u,v;
std::priority_queue<std::pair<int,int> > q;
int d[nmax + 10],ans[nmax + 10];
bool f[nmax + 10];

void add(int x,int y){
    ver[++tot] = y;
    next[tot] = head[x];
    head[x] = tot;
}

void dij(){
    memset(d,0x3f,sizeof(d));
    memset(f,0,sizeof(f));
    memset(ans,0,sizeof(ans));

    d[1] = 0;ans[1] = 1;
    
    q.push(std::make_pair(0,1));
    
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        
        if(f[x]) continue;
        f[x] = 1;
        
        for(int i = head[x];i;i = next[i]){
            int y = ver[i];
            if(d[y] > d[x] + 1){
                ans[y] = ans[x];
                d[y] = d[x] + 1; 
                q.push(std::make_pair(-d[y],y));
            }
            else if(d[y] == d[x] + 1){
                (ans[y] += ans[x]) %= mod;
            }
        }
    }
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i = 0 ;i < m;++i){
        cin>>u>>v;
        if(u == v) continue;
        add(u,v);
        add(v,u);
    }

    dij();

    for(int i = 1;i <= n;++i){
        cout<<ans[i]<<endl;
    }

    return 0;
}
