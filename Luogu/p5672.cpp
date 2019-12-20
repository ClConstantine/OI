#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
ll n,p,head,tail,del,ans,t,cnt,xo;
ll c[int(1e6+10)],q[int(1e6+10)];
char s;

ll mul(ll a,ll b){
    ll c = ld(a)*b/p;
    return ((a*b-c*p)%p+p)%p;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin>>n>>p;

    for(int i=1;i<=n;i++){
        cin>>c[i];
        c[i]%=p;
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s=='P') q[i]=1;
        else q[i]=0;
    }
    head=1,tail=n,del=1,xo=0;
    while(head!=tail){
        cnt++;
        (ans += c[head])%=p;
        if(q[head+del]==q[head]){
            c[head+del]=mul(c[head],c[head+del]);
            head += del;
        }
        else if((q[head]^xo)==1&&(q[head+del]^xo)==0&&(cnt&1)){
            xo = !xo;
            head += del;
        }
        else {
            head += del;
            t = head;
            head = tail;
            tail = t;
            del=-del;
        }

    }
    cout<<(ans+c[head])%p;

    return 0;
}
