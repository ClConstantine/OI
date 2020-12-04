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

int T,n;
double d,dp[mmax + 10],sum[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n>>d;
		int t = d;

		rep(i,1,t - 1){
			dp[i] = t - 1;
			sum[i] = sum[i - 1] + dp[i];
		}

		dp[t] = dp[t - 1]  + 1 / d;
		sum[t] = sum[t - 1] + dp[t];
		
		rep(i,d + 1,n){
			dp[i] = (sum[i - 1] - sum[i - t] + d - 1) / d + dp[i - t] / t;
			sum[i] = sum[i - 1] + dp[i];
		}

		printf("%.2f\n",dp[n]);	
	}

	return 0;
}