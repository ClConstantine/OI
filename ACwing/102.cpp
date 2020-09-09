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

const int mmax = 1e5;
double n,f,a[mmax + 10],sum[mmax + 10],mmin,ans,l,r,del = 1e-6;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>f;

	rep(i,1,n){
		cin>>a[i];
	}

	l = 1;r = 2000;

	while(r - l > del){
		ans = -2010;
		mmin = 2010;

		double mid = (r + l) / 2;
		rep(i,1,n){
			sum[i] = a[i] - mid;
			sum[i] += sum[i - 1];
		}

		rep(i,f,n){
			mmin = std::min(sum[i - f],mmin);
			ans = std::max(sum[i] - mmin,ans);
		}
		if(ans > 0){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	cout<<int(r * 1000);
	

	return 0;
}