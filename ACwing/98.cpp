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
typedef long double ld;
typedef std::pair<ll ,ll> PLL;

ll N,A,B,T;

PLL fractal(ll n,ll id){
	if(n == 0){
		return std::make_pair(0,0);
	}

	ll cnt = 1ll << (2 * n - 2),len = 1ll << (n - 1);
	PLL pos = fractal(n - 1,id % cnt);
	ll x = pos.first,y = pos.second,z = id / cnt;

	if(z == 0) return std::make_pair(y,x);
	if(z == 1) return std::make_pair(x , y + len);
	if(z == 2) return std::make_pair(x + len, y + len);
	return std::make_pair(2 * len - y - 1, len - x - 1);
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>N>>A>>B;
		PLL m = fractal(N,A - 1),n = fractal(N,B - 1);
		ll x = m.first - n.first,y = m.second - n.second;

		double ans = std::sqrt(double(x * x + y * y)) * 10;
		
		printf("%.0lf\n",ans);
	}


	return 0;
}