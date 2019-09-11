#include <iostream>
#include <cstdio>

using std::cin; using std::cout;using std::endl;

int father[5000+10];
int n,m,p;

int get(int x){
    if(father[x]==x) return x;
    return father[x]=get(father[x]);

}

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(0);

    cin>>n>>m>>p;

    for(int i=1;i<=n;i++){
        father[i]=i;
    }

    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(father[get(u)]==father[get(v)]) continue;
        father[get(u)]=get(v);
    }
    for(int i=0;i<p;i++){
        cin>>u>>v;
        if(father[get(u)]==father[get(v)]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
