#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::endl;

typedef long long ll;

const ll MOD= 1e8;

ll gcd(ll a, ll b){ return a == 0 ? b : gcd(b % a, a); } 

struct mat{
    long long c[5][5];
    void set1(){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                c[i][j]=0;
    }
    void set2(){
        for(int i=1;i<=3;i++)
            c[i][i]=1;
    }
}yuan;

mat mul(mat x,mat y){
    mat temp;
    temp.set1();
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
    mat ans;

    ans.set1();
    ans.set2();

    while (n){
        if(n&1)
            ans=mul(ans,x);
        x=mul(x,x);
        n>>=1;
    }
    return ans;
}

int main(){
    long long m,n;
    cin>>m>>n;
    long long g=gcd(m,n);
    //cout<<g<<endl;
    yuan.set1();
    yuan.c[1][1]=yuan.c[1][2]=yuan.c[2][1]=yuan.c[3][2]=1;

    if(g<=2){
        cout<< 1 ;
        return 0;
    }
    yuan=qp(yuan,g-2);
    cout<<(yuan.c[1][1]+yuan.c[1][2])%MOD;
    return 0;
}
