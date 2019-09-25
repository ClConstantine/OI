#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using std::cin; using std::cout;using std::cerr;using std::endl;

int n,m,mmax=0;

int gang[1010];
int en[1010]={0};

int get(int x){
    if(gang[x]==x) return x;
    return gang[x]=get(gang[x]);
}

void unget(int x,int y){
    if(en[x]==0) {
        en[x]=get(y);
        return ;
    }
    gang[get(y)]=get(en[x]);
}

bool judge(int a,int b){
    return get(a)==get(b);
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        gang[i]=i;
    }

    int a,b;
    char s;

    for(int i=0;i<m;i++){
        cin>>s>>a>>b;
        if(s=='F'){
            gang[get(b)]=get(a);
        }
        else if(s=='E'){
            unget(a,b);
            unget(b,a);
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        if(gang[i]==i) ans++;
    }

    cout<<ans;
    return 0;
}
