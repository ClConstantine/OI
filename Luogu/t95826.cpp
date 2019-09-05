#include <iostream>
#include <cstdio>
#include <cmath>

using std ::cin;using std::cout;using std::endl;using std::cerr;

long long n,s,m,k;
long long stack[100];
struct mat{

    long long can[100][100];

    void set0(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                can[i][j]=0;
            }
        }
    }

    void set1(){
        can[1][n]=1;

        for(int i=2;i<=n;i++){
            can[i][i-1]=1;
        }
        if(s>1){
            can[s][s-1]=0;
            can[m][m-1]=0;
            can[s][m-1]=1;
            can[m][s-1]=1;
        }
        else {
            can[s][n]=0;
            can[m][m-1]=0;
            can[s][m-1]=1;
            can[m][n]=1;
        }

    }

    void seet(){
        for(int i=1;i<=n;i++){
            can[i][i]=1;
        }
    }
}y,ans;

mat mul(mat a,mat b){

    mat temp;
    temp.set0();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                temp.can[i][j]+=a.can[i][k]*b.can[k][j];
            }
        }
    }

    return temp;
}

void print (mat x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<x.can[i][j];
        }
        cout<<endl;
    }
}

mat qp(){
    mat b,temp;
    b=ans;

    temp.set0();
    temp.seet();

    while(k){
        /*cout<<"b:"<<endl;
        print(b);
        */
        if(k&1){
            temp=mul(temp,b);
        }
        k>>=1;
        b=mul(b,b);
    }
    return temp;
}

int main(){

    cin.tie(0);
    std::ios::sync_with_stdio(0);
    cin>>n>>s>>m>>k;

    y.set0();

    for(int i=1;i<=n;i++){
        cin>>y.can[i][1];
    }

    ans.set0();
    ans.set1();
    //print(ans);
    mat now=qp();
    //print(now);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(now.can[i][j]){
                stack[j]=y.can[i][1];
                continue ;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<stack[i]<<' ';
    }
    return 0;
}
