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
int ovo[mmax + 10],dp[mmax + 10];
int n;
long long ans = 0;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i = 1;i <= n;++i){
		cin>>ovo[i];
	}

	for (int i = 1;i <= n;++i){
		dp[i] = 1;
	}

	for(int i = 1;i <= n - 1;++i){
		if(ovo[i + 1] > ovo[i]){
			dp[i + 1] = dp[i] + 1; 
		}
		else if(ovo[i + 1] == ovo[i]){
			dp[i + 1] = dp[i];
		}
	}

	for (int i = n; i > 1; --i)
	{
		if(ovo[i - 1] > ovo[i]){
			dp[i - 1] = std::max(dp[i] + 1,dp[i - 1]);
		}
		if(ovo[i - 1] == ovo[i]){
			dp[i - 1] = std::max(dp[i],dp[i-1]);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		ans +=dp[i];
	}

	cout<<ans;

	return 0;
}