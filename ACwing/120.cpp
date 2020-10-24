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

const int mmax = 2e5;
ll T,n,p,c,L,R;

struct node 
{
	ll s,e,d;
}a[mmax + 10];

int check(ll x){
	ll ans = 0;
	rep(i,1,n){
		if(a[i].s <= x){
			ans += (std::min(a[i].e,x) - a[i].s) / a[i].d + 1;
		}
	}
	return ans;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i].s>>a[i].e>>a[i].d;
		}

		L = 0,R = (1ll<<31) - 1;

		while(L < R){
			ll mid = (L + R) >> 1;

			if(check(mid) & 1){
				R = mid;
			}
			else L = mid + 1;
		}
		ll ans = check(R) - check(R - 1);

		if(ans & 1){
			cout<<R<<' '<<ans<<endl;
		}
		else {
			cout<<"There's no weakness."<<endl;
		}
	}


	return 0;
}