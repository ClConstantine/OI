#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using std::cin;using std::cout;using std::endl;using std::cerr;

typedef long long ll;

const int mmax = 1e5;
ll n,a[mmax + 10],inc[mmax + 10],pos,neg;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i = 1;i <= n;++i){
		cin>>a[i];
	}
	for(int i = 1;i <= n;++i){
		inc[i] = a[i] - a[i - 1];
	}

	for(int i = 2;i <= n;i++){
		if(inc[i] > 0){
			pos += inc[i];
		}
		else neg += -inc[i];
	}

	cout<<std::max(pos,neg)<<endl<<std::abs(pos - neg) + 1;

	return 0;
}