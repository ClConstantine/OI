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
int n,ans,temp,mid;
int y[mmax + 10],x[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>x[i]>>y[i];
	}
	std::sort(x + 1,x + 1 + n); 
	std::sort(y + 1,y + 1 + n);

	mid = y[n / 2 + 1];

	rep(i,1,n){
		ans += std::abs(y[i] - mid);
	}
	rep(i,1,n){
		x[i] -= i;
	}

	std::sort(x + 1,x + 1 + n); 
	mid = x[n / 2 + 1];

	rep(i,1,n){
		ans += std::abs(x[i] - mid);
	}
	cout<<ans;
	
	return 0;
}