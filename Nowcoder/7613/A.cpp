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

const int mmax = 1e6;

int n;
int a[mmax + 10];
int ans;
int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	a[1] = 0;

	rep(i,1,n / 2){
		int t = 2;
		while(i * t <= n){
			a[i * t]++;
			t++;
		}
	}

	rep(i,1,n){
		ans += a[i] * (n / i - 1);
	}

	cout<<ans;

	return 0;
}