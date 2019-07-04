#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;

int M,N,K,L,D;
int x,y,p,q;
struct line{
    int id,ans=0;
}h[2500],l[2500];

bool book1[2500],book2[2500];

bool com(line a,line b){
    if(a.ans>b.ans)
        return true;
    return false;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>M>>N>>K>>L>>D;

    for(int i=1;i<=M;i++){
        h[i].id=i;
    }
    for(int i=1;i<=N;i++){
        l[i].id=i;
    }

    for(int i=0;i<D;i++){
        cin>>x>>y>>p>>q;
        if(x==p){
            int t=std::min(y,q);
            l[t].ans++;
        }
        else{
            int t=std::min(x,p);
            h[t].ans++;
        }
    }
    std::sort(h+1,h+M+1,com);
    std::sort(l+1,l+N+1,com);
    
    for(int i=1;i<=K;i++){
        book1[h[i].id]=1;
    }
    
    for(int i=1;i<=L;i++){
        book2[l[i].id]=1;
    }

    for(int i=1;i<=M;i++){
        if(book1[i]) cout<<i<<' ';
    }
    cout<<endl;
    for(int i=1;i<=N;i++){
        if(book2[i]) cout<<i<<' ';
    }
    return 0;
}
