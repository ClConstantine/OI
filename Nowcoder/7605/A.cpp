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

long long a,b,c,d,n;

long long gcd(long long x,long long y){
	return (y ? gcd(y,x % y) : x);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	while(n--){
		cin>>a>>b>>c>>d;

		long long sgcd = gcd(a,gcd(b,c));

		if(sgcd == 0){
			if(d == 0)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			if(!(d % sgcd))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}


	return 0;
}
