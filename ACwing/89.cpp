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

long long a,b,p;

long long qpow(long long a,long long b){
	long long ans = 1;
	a %= p;

	while(b){
		if(b & 1){
			(ans *= a) %= p;
		}
		b >>= 1;
		(a *= a) %= p;
	}

	return ans % p;

}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0); 

	cin>>a>>b>>p;

	cout<<qpow(a,b);

	return 0;
}