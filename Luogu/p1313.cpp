#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl;

int yang[1010][1010];
const int MOD=10007;

int kuai(int x,int n){
    int ans=1;
    while(n){
        if(n&1){
            (ans*=x)%=MOD;
        }
        (x*=x)%=MOD;
        n>>=1;
    }
    return ans;
}

int main(){

    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    a%=MOD;
    b%=MOD;
    for(int i=1;i<=k+1;i++){
        yang[i][1]=1;
    }
    for(int i=2;i<=k+1;i++){
        for(int j=2;j<=i;j++){
            yang[i][j]=(yang[i-1][j-1]+yang[i-1][j])%MOD;
            //cout<<yang[i][j]<<' ';
        }
        //cout<<endl;
    }
    /*cout<<yang[k+1][k+1-n]<<endl;
    cout<<kuai(a,n)<<endl;
    cout<<kuai(b,m)<<endl;
*/
    cout<<(((yang[k+1][k+1-n]*kuai(a,n))%MOD*kuai(b,m))%MOD)%MOD;
    return 0;
}
