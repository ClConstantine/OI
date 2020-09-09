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

int a[mmax + 10],n,len1 = 1,len2 = 0; 
int dp[mmax + 10],tail[mmax + 10];

bool cmp(int a,int b){
	return a > b;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	n = 0;
	while(cin>>a[++n] && n){

	}


	dp[1] = a[1]; 
	len1 = 1;
	n = n - 1;

	rep(i,2,n){
		int t = std::upper_bound(dp + 1,dp + 1 + len1,a[i],cmp) - dp;

		if(t > len1){
			dp[++len1] = a[i];
		}
		else{
			dp[t] = a[i];
		}
		// cout<<"i"<<' '<<i<<endl;
		// cout<<'t'<<' '<<t<<endl;
		// rep(j,1,len1){
		// 	cout<<dp[j]<<' ';
		// }
		// cout<<endl;
		// cout<<len1<<endl;
	}

	len2 = 1;
	tail[len2] = a[1];

	rep(i,2,n){
		int t = std::lower_bound(tail + 1,tail + 1 + len2,a[i]) - tail;

		if(t>len2){
			tail[++len2] = a[i];
		}
		else{
			tail[t] = a[i];
		}
	}
	
	cout<<len1<<endl<<len2;

	return 0;
}