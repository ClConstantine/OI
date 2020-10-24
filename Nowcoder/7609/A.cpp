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

const int mmax = 1e7;
ll T,a,b,c,k,s;

ll qpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b & 1){
			(ans *= a) %= s;
		}
		(a *= a) %= s;
		b >>= 1;
	}
	return ans;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>a>>b>>c>>k;
		s = a + b + c;
		cout<<(c * qpow(2,k)) % s<<endl;
	}


	return 0;
}