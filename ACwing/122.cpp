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
long long a[mmax + 10],sum[mmax + 10];
long long n,ans,tot,aver;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
		tot += a[i];
	}

	aver = tot / n;

	rep(i,1,n){
		sum[i] = sum[i - 1] + a[i] - aver; 
	}

	std::sort(sum + 1,sum + 1 + n);

	int mid = sum[n / 2 + 1];

	rep(i,1,n){
		ans += std::abs(sum[i] - mid);
	}

	cout<<ans;

	return 0;
}