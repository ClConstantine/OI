#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;
typedef long long ll;

const int mmax=500000;
int M,N;

int a[mmax+10],C[mmax+10];ll T[mmax+10];

int Lowbit(int x) {
    return x&(-x);
}
void Diference() {
    int i=1;
    C[i]=a[i];
    for(int i=2;i<=M;i++){
        C[i]=a[i]-a[i-1];
    }
    return ;
}
void Build(){
    for(int i=1;i<=M;i++){
        for(int j=i;j<=M;j+=Lowbit(j)){
            T[j]+=C[i];
        }
    }
    return ;
}
void Add(int x,int y){
    for(int i=y;i<=M;i+=Lowbit(i)){
        T[i]+=x;
    }
}
ll Getsum(int x){
    ll temp;
    for(int i=x;i>0;i-=Lowbit(i)){
        temp+=T[i];
    }
    return temp;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        cin>>a[i];
    }
    Diference();
    Build();
    for(int i=1;i<=N;i++){
        int t;
        cin>>t;
        if(t==1){
            int sta,end,x;
            cin>>sta>>end>>x;
            Add(x,sta);Add(-x,end+1);
        }
        else{
            int sta;
            cin>>sta;
            cout<<Getsum(sta)<<endl;
        }
    }

    
    
    
    return 0;
}
