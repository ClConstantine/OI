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

const int mmax = 2e5;
int n,k;
int a[mmax + 10],l = 1e9,r = 0,ans;

bool check(int x){
	int num = 0,t;
	rep(i,1,n){
		t = a[i] / x;
		if(t * x == a[i]) num += t - 1;
		else num += t;
	}
	return (num <= k?1:0);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;

	rep(i,1,n){
		cin>>a[i];
		r = std::max(r,a[i]);
	}
	l = 1;
	ans = r;

	while(r - l >=1){
		int m = (l + r) / 2;
		if(check(m)){
			ans = m;
			r = m;
		}
		else{
			l = m + 1;
		}
	}

	cout<<ans;

	return 0;
}