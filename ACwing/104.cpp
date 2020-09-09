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

const int mmax = 1e5; 
long long n,k,ans = 0;
long long a[mmax + 10];

bool cmp(long long a,long long b){
	if(a < b) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
	}

	std::sort(a + 1,a + 1 + n,cmp);

	k = a[n / 2 + 1];

	rep(i,1,n){
		ans += std::abs(a[i] - k);
	}

	cout<<ans;

	return 0;
}