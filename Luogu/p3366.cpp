#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::cerr;

int m,n;
int x,y,z;

int flag[5010];

struct se{
    int u,v,w;
}can[200010];

bool cmp(se a,se b){
    if(a.w<b.w) return true;
    return false;
}
int get(int x){
    if(flag[x]==x) return x;
    return flag[x]=get(flag[x]);
}

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(0);

    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        can[i].u=x;
        can[i].v=y;
        can[i].w=z;
    }

    std::sort(can,can+m,cmp);
    int ans=0;

    for(int i=1;i<=n;i++){
        flag[i]=i;
    }

    for(int i=0;i<=m;i++){
        if(get(can[i].u)!=get(can[i].v)){
            flag[get(can[i].u)]=get(can[i].v);
            ans+=can[i].w;
        }
    }
    cout<<ans;
    return 0;
}
