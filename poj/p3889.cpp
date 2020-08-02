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

ll T,n,s,d;
std::pair<ll,ll> calc(ll n,ll m){
	if(n == 0) return std::make_pair(0,0);

	ll len = 1ll << (n - 1),num = 1ll << (2 * n - 2);
	std::pair<ll,ll> pos = calc(n - 1,m % num);
	ll x = pos.first,y = pos.second;
	
	long long z = m / num;
	
	if(z == 0) return std::make_pair(y,x);
	if(z == 1) return std::make_pair(x + len,y);
	if(z == 2) return std::make_pair(x + len,y + len);
	if(z == 3) return std::make_pair(len - y - 1 ,2 * len - x - 1);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;
	while(T--){
		cin>>n>>s>>d;
		std::pair<ll,ll> pos1 = calc(n,s-1);
		std::pair<ll,ll> pos2 = calc(n,d-1);
		// cout<<pos1.first<<' '<<pos1.second<<' '<<pos2.first<<' '<<pos2.second<<endl;
		// cout<<100*(pos1.first - pos2.first)*(pos1.first - pos2.first) + (pos1.second - pos2.second)*(pos1.second - pos2.second)*100<<endl;
		long double x = 100*(pos1.first - pos2.first)*(pos1.first - pos2.first) + (pos1.second - pos2.second)*(pos1.second - pos2.second)*100;
		cout<<ll(std::sqrt(x) + 0.5)<<endl;

	}


	return 0;
}