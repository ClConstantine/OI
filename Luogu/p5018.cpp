#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin; using std::cout;using std::endl;

const int maxx=1e6+10;
int w[maxx],l[maxx],r[maxx],n,book[maxx],size[maxx];

int get(int x){
    if(book[x]) return size[x];
    int temp=0;

    if(l[x]!=-1) temp+=get(l[x]);    
    if(r[x]!=-1) temp+=get(r[x]);
    size[x]=temp+1;
    book[x]=1;
    return temp+1;
}

bool cmp(int u,int v){
    if(u==-1&&v==-1) return true;
    if(u!=-1&&v!=-1&&w[u]==w[v]&&cmp(l[u],r[v])&&cmp(r[u],l[v]))return true;
    return false;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }

    for(int i=1;i<=n;i++){
        size[i]=get(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cmp(l[i],r[i])) ans=std::max(ans,size[i]);
    }

    cout<<ans;

    return 0;
}
