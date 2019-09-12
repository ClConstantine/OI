#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::cerr;

int n;
int father[100+10];

struct point{
    int u,v,w;
}can[10000+10];

int get(int x){
    if(father[x]==x) return x;
    return father[x]=get(father[x]);
}

bool cmp(point a,point b){
    if(a.w<b.w) return 1;
    return 0;
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(0);

    cin>>n;

    for(int i=1;i<=n;i++){
        father[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            can[i*n+j].u=i;
            can[i*n+j].v=j;
            cin>>can[i*n+j].w;
        }
    }

    std::sort(can+1,can+n*n+1,cmp);
    int ans=0;

    for(int i=1;i<=n*n;i++){
        if(get(can[i].u)==get(can[i].v)) continue;
        ans+=can[i].w;
        father[get(can[i].u)]=get(can[i].v);
    }

    cout<<ans;

    return 0;
}
