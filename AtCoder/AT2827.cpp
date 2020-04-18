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

const int mmax = 1e6;

int dp[mmax + 10];
int n,opt,t,len;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n;

	for(int i = 0;i < n;i++){
		dp[i] = 0x3f3f3f3f;
	}

	len = 0;
	cin>>dp[0];
	for(int i = 1;i < n;i++){
		cin>>t;

		if(t > dp[len]){
			dp[++len] = t;
		}
		else {
			opt = std::lower_bound(dp,dp + len + 1,t) - dp;
			dp[opt] = t;
		}
	}

	/*for(int i = 0;i < len;i++){
		cout<<dp[i]<<' ';
	}*/

	cout<<len + 1;


	return 0;
}