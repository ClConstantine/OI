// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>

using std::cin;using std::cout;using std::endl;using std::cerr;
typedef long long ll;

const int mod = 998244353;

ll pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    ll m,n;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        cout<<pow(2,(n-1)*(m-1))<<endl;
    }
    return 0;
}
