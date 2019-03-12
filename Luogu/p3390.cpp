#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::cerr;using std::endl;
long long N,k;
const int MOD=1000000000+7;
struct Mat{
    long long c[110][110];
    void set(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                c[i][j]=0;
            }
        }
    }
}yuan,e;

Mat mul(Mat x,Mat y){
    Mat c;
    c.set();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                c.c[i][j]=(c.c[i][j]+x.c[i][k]*y.c[k][j])%MOD;
            }
        }
    }
    return c;
}

Mat qp(Mat x,long long n){
    Mat ans=e;
    while (n){
        if(n&1){
            ans=mul(ans,x);
        }
        n>>=1;
        x = mul(x,x);
    }
    return ans;
}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin>>N>>k;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>yuan.c[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        e.c[i][i]=1;
    }
    
    yuan=qp(yuan,k);
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<yuan.c[i][j]%MOD<<' ';
        }
        cout<<endl;
    }
    return 0;
}
