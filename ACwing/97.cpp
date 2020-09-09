#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using std::cin;using std::cout;using std::cerr;using std::endl;

#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = a;i >= b;--i)

typedef long long ll;

const int mod = 9901; 
int a,b,tot = 0;
ll ans = 1;

struct factor
{
	int p;ll c;
}prime[500000];

ll qpow(ll m,ll x){
	ll ans = 1;
	while(x){
		if(x&1) (ans *= m) %= mod;
		(m *= m) %= mod;
		x >>= 1;
	}
	return ans;
}

ll sum(ll p,ll c){
	if(c == 0) return 1;
	if(c % 2){
		return (1+qpow(p,c/2 + 1))*sum(p,c/2)%mod;
	}
	return ((1+qpow(p,c/2 + 1))*sum(p,c/2-1)+qpow(p,c/2))%mod;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b;

    if(a == 0){
        cout<<0;
        return 0;
    }
    else if(b == 0){
        cout<<1;
        return 0;
    }

	for(int i = 2;i * i <= a;){
		if(a % i == 0){
			prime[++tot].p = i;
			//cout<<i<<endl;
			while(!(a % i)){
				a /= i;
				prime[tot].c++;
			}
			prime[tot].c *= b; 
		}
		if(i == 2) i++;
		else i += 2;
	}

	if (a != 1)
	{
		prime[++tot].p = a;
		prime[tot].c = b;
	}

	rep(i,1,tot){
		// cout<<sum(prime[i].p,prime[i].c)<<endl;
		// cout<<prime[i].p<<' '<<prime[i].c<<endl;

		(ans *= sum(prime[i].p,prime[i].c)) %= mod;
	}

	cout<<ans<<endl;

	return 0;
}