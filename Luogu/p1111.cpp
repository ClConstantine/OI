#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::cerr;

int father[1000+10];
int n,m,u,v,w;

struct point{
    int u,v,w;
}can[100000+10];

bool cmp(point a,point b){
    if(a.w<b.w) return 1;
    return 0;
}

int get(int x){
    if(father[x]==x) return x;
    return father[x]=get(father[x]);
}

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        father[i]=i;
    }

    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        can[i].u=u;
        can[i].v=v;
        can[i].w=w;
    }

    std::sort(can,can+m,cmp);

    int ans=0;
    int num=0;

    for(int i=0;i<m;i++){
        if(father[get(can[i].u)]==father[get(can[i].v)]) continue;
        num++;
        ans=std::max(can[i].w,ans);
        father[get(can[i].u)]=get(can[i].v);
    }

    if(num<n-1) cout<<-1;
    else cout<<ans;

    return 0;
}
