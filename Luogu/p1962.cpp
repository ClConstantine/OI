#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

const int mod=1000000007;

struct MAT{
    long long c[5][5];
    
    void set1(){
        for(int i=1;i<=3;++i){
            for(int j=1;j<=3;++j){
                c[i][j]=0;
            }
        }
    }

    void set2(){
        for(int i=1;i<=3;++i){
            c[i][i]=1;
        }
    }
}yuan;

MAT mul(MAT x,MAT y){
    MAT re;
    re.set1();
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            for(int k=1;k<=3;k++){
                (re.c[i][j]+=(x.c[i][k]*y.c[k][j])%mod)%=mod;
            }
        }
    }
    return re;
}

MAT qp(long long b,MAT yuan){
    MAT e;
    e.set1();
    e.set2();
    while(b>0){
        if(b&1){
            e=mul(yuan,e);
        }
        yuan=mul(yuan,yuan);
        b>>=1;
    }
    return e;
}
int main(){
    long long x;
    cin>>x;
    yuan.c[1][1]=yuan.c[1][2]=yuan.c[2][1]=yuan.c[3][2]=1;
    yuan=qp(x-2,yuan);
    cout<<(yuan.c[1][1]+yuan.c[1][2])%mod;
    return 0;
}
