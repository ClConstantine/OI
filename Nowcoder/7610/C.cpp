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

ll a,m,b,n;

ll gcd(ll x,ll y){
	return (!y ? x:gcd(y,x % y));
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>m>>b>>n;

	ll t1 = gcd(a , b * n),t2 = gcd(a,b);
	ll s1 = b * n * a / t1,s2 = a * b / t2;

	cout<< s1 / a + s1 / b - s1 / s2;

	return 0;
}