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

const int mmax = 100;
int a[mmax + 10],dp[2][mmax + 10],ans1[mmax + 10],ans2[mmax + 10];
int n,len1,len2,ans;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
	}

	dp[0][1] = a[1];
	ans1[1] = 1;
	len1 = 1;

	rep(i,2,n){
		int t = std::lower_bound(dp[0] + 1,dp[0] + len1 + 1,a[i]) - dp[0];
		if(t > len1){
			dp[0][++len1] = a[i];
			ans1[i] = len1;
		}
		else{
			dp[0][t] = a[i];
			ans1[i] = len1;
		}
	}

	dp[1][1] = a[n];
	ans2[n] = 1;
	len2 = 1;

	per(i,n-1,1){
		int t = std::lower_bound(dp[1] + 1,dp[1] + len2 + 1,a[i]) - dp[1];
		if(t > len2){
			dp[1][++len2] = a[i];
			ans2[i] = len2;
		}
		else{
			dp[1][t] = a[i];
			ans2[i] = len2;
		}
	}



	ans = 0;
	rep(i,1,n){
		// cout<<"i "<<i<<" ans "<<ans1[i] + ans2[i + 1]<<endl; 
		ans = std::max(ans,ans1[i] + ans2[i + 1]);
	}

	cout<<n-ans;

	return 0;
}