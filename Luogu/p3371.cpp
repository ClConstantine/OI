#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::min;using std::max;

const int nmax = 100000,mmax = 500000;
int edge[mmax+10],ver[mmax+10],head[nmax+10],next[mmax+10];
int n,m,s,a,b,c,tot=0,dist[nmax+10];
bool f[nmax+10];

void add(int x,int y,int z){
    next[++tot] = head[x];
    head[x] = tot;
    ver[tot] = y;
    edge[tot] = z;
}

void dij(){
    memset(dist,0x3f,sizeof(dist));
    memset(f,0,sizeof(f));
    dist[s] = 0;
    for(int i=1;i<n;i++){
        int x = 0;
        for(int j = 1;j <= n;j ++){
            if(!f[j]&&(x==0||dist[j]<dist[x])) x = j;
        }
        f[x] = 1;
        for(int j = head[x];j;j=next[j]){
            dist[ver[j]] = min(dist[ver[j]],dist[x]+edge[j]);
        }
    }
}

int main()
{
    cin>>n>>m>>s;

    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }

    dij();

    for(int i = 1;i<=n;i++){
        if(dist[i] != 0x3f3f3f3f)
            cout<<dist[i]<<' ';
        else cout<<((1<<31)-1)<<' ';
    }

    return 0;
}
