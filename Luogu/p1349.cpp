#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;
typedef long long ll;

ll a1,a2,p,q,n,m;

struct MAT{
    ll c[5][5];
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
    MAT c;
    c.set1();
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            for(int k=1;k<=3;k++){
                (c.c[i][j]+=x.c[i][k]*y.c[k][j]%m)%=m;
            }
        }
    }
    return c;
}

MAT qp(int b,MAT x){
    MAT e;
    e.set1();
    e.set2();
    while(b>0){
        if(b&1){
            e=mul(x,e);
        }
        x=mul(x,x);
        b>>=1;
    }
    return e;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>p>>q>>a1>>a2>>n>>m;
    yuan.c[1][1]=p;
    yuan.c[1][2]=q;
    yuan.c[2][1]=yuan.c[3][2]=1;
    if(n==1) cout<<a1%m<<endl;
    else if(n==2) cout<<a2%m<<endl;
    else {
        yuan=qp(n-2,yuan);
        cout<<(a2*yuan.c[1][1]+a1*yuan.c[1][2])%m<<endl;
    }
    return 0;
}
