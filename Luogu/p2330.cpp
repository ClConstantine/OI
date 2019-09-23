#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin; using std::cout;using std::cerr; using std::endl;

int n,m,mmax=0;

struct edge{
    int u,c,v;
}can[100000+10];

int father[310];

int get(int x){
    if(father[x]==x) return x;
    return father[x]=get(father[x]);
}

bool cmp(edge a,edge b){
    if(a.c<b.c) return 1;
    return 0;
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        father[i]=i;
    }

    for(int i=0;i<m;i++){
        cin>>can[i].u>>can[i].v>>can[i].c;
    }

    std::sort(can,can+m,cmp);

    for(int i=0;i<m;i++){
        if(get(can[i].u)==get(can[i].v)) continue;
        mmax=std::max(mmax,can[i].c);
        father[get(can[i].u)]=get(can[i].v);
    }
    cout<<n-1<<' '<<mmax;
    return 0;
}
