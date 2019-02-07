#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
map<ll,ll> st;
ll add(ll x){
    if(x<2) return 0;
    return x*(x-1)/2;
}
int main()
{
    ll n,m,high;
    ll ans=0;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&high);
        st[i+high]++;
        st[i-high]++;
    }
    for(map<ll,ll>:: iterator it=st.begin();it!=st.end();it++ ){
        ans+=add(it->second);
    }
    printf("%lld",ans);
    return 0;
}
