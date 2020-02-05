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

typedef long long ll;

ll a,b,p;

ll bigmul(ll a,ll b){
	return (a * b - (ll)( (long double) a * b / p) * p + p) % p;
}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b>>p;

	cout<<bigmul(a,b); 
		
	return 0;
}