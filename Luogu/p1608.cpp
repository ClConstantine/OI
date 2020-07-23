#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using std::cin;using std::cout;using std::endl;using std::cerr;using std::string;

const int nmax = 2000,mmax = 2000*1999;
int head[nmax + 10],next[mmax + 10],ver[mmax + 10],cost[mmax + 10],cmp[2001][2001];
int tot,n,m,u,v,w,mm;

void add(int x,int y,int z){
    ver[++tot] = y;
    next[tot] = head[x];
    head[x] = tot;
    cost[tot] = z;
}

void dij(){
    int d[nmax + 10],ans[nmax + 10];
    bool f[nmax + 10];
    memset(d,0x3f,sizeof(d));
    memset(f,0,sizeof(f));
    memset(ans,0,sizeof(ans));
    std::priority_queue<std::pair<int,int> > q;
    
    d[1] = 0;
    ans[1] = 1;
    q.push(std::make_pair(0,1));
    
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        
        if(f[x]) continue;
        
        f[x] = 1;
        
        for(int i = head[x];i;i = next[i]){
            int y = ver[i],z = cost[i];
            
            if(d[y] > d[x] + z){
                d[y] = d[x] + z;
                ans[y] = ans[x];
                q.push(std::make_pair(-d[y],y));
            }
            else if(d[y] == d[x] + z){
                ans[y] +=ans[x];
            }
        }
    }
    if(d[n] != 0x3f3f3f3f)
        cout<<d[n]<<" "<<ans[n];
    else cout<<"No answer";
}



int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i = 0;i < m;++i){
        cin>>u>>v>>w;
        
        if(!cmp[u][v] || cmp[u][v] > w){
            cmp[u][v] = w;
            add(u,v,w);
        }
    }
    
    dij();
    
    return 0;
}
