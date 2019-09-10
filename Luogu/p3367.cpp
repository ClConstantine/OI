#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin; using std::cout; using std::endl;

int n,m,x,y,z;

int father[10000+10];

int get(int x){
    if(x==father[x]){
        return x;
    }
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
        cin>>z>>x>>y;
        if(z==1){
            father[get(x)]=get(y);
        }
        if(z==2){
            if(get(x)==get(y)) cout<<'Y'<<endl;
            else cout<<'N'<<endl;
        }
    }
    return 0;
}
