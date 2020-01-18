#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax = 2e5,nmax = 1e5;
int f[nmax+10],in[nmax+10],out[nmax+10];
int head[nmax+10],next[mmax+10],ver[mmax+10];
int ans=0,tot = 0,n,m,x,y;



void add(int a,int b){
    next[++tot] = head[a];
    head[a] = tot;
    ver[tot] =b;
}

int dfs(int x){
    if(f[x]) return f[x];

    if(out[x] == 0) return 1;

    for(int i = head[x];i;i=next[i]){
        f[x] += dfs(ver[i]);
    }
    return f[x];
}

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i = 0;i < m;i++){
        cin>>x>>y;
        add(x,y);
        out[x]++;
        in[y]++;
    }

    for(int i = 1;i <= n;i++){
        if(in[i]==0 && out[i]!=0){
            ans += dfs(i);
        }
    }
    cout<<ans;
    return 0;
}