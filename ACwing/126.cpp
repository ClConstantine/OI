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

int a[mmax + 5][mmax + 5];
int n,dp,ans = -0x7f7f7f7f;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		rep(j,1,n){
			cin>>a[i][j];
			a[i][j] += a[i - 1][j];
		}
	}

	rep(i,1,n){
		rep(j,i,n){
			dp = -0x7f7f7f7f;
			rep(k,1,n){
				dp = std::max(a[j][k] - a[i - 1][k],dp + a[j][k] - a[i - 1][k]);
				ans = std::max(ans,dp);
			}
		}
	}

	cout<<ans;

	return 0;
}