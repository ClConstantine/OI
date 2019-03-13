#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::cerr;using std::endl;

const int MOD=1000000000+7;
long long N;

struct mat{
    long long c[5][5];
    void set(){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                c[i][j]=0;
    }
    void seet(){
        for(int i=1;i<=3;i++)
            c[i][i]=1;
    }
}solve;

mat mul(mat x,mat y){
    mat temp;
    temp.set();
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                (temp.c[i][j]+=x.c[i][k]*y.c[k][j]%MOD)%=MOD;
            }
        }
    }
    return temp;
}

mat qp(mat x,long long n){
    n-=3;
    mat ans;
    
    ans.set();
    ans.seet();
    
    while (n){
        if(n&1)
            ans=mul(ans,x);
        x=mul(x,x);
        n>>=1;
    }
    return ans;
}

int main(){
    
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    while(cin>>N&&N){
        if(N<=3){
            cout<<1<<endl;
        }
        
        else {
            solve.set();
            solve.c[1][1]=solve.c[1][3]=solve.c[2][1]=solve.c[3][2]=1;
            solve=qp(solve,N);
            cout<<(solve.c[1][1]+solve.c[1][2]+solve.c[1][3])%MOD<<endl;
        }
    
    }
    return 0;
}
