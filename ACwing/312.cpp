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

const int nmax = 350,mmax = 120; 
int n,a[nmax + 10],b[5],t,m;
int dp[45][45][45][45];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,m){
		cin>>t;
		b[t]++;
	}
	dp[0][0][0][0] = a[1];
	rep(i,0,b[1]){
		rep(j,0,b[2]){
			rep(k,0,b[3]){
				rep(m,0,b[4]){
					if(i)dp[i][j][k][m] = std::max(dp[i - 1][j][k][m] + a[1 + i + 2 * j + 3 * k + 4 * m],dp[i][j][k][m]);
					if(j)dp[i][j][k][m] = std::max(dp[i][j - 1][k][m] + a[1 + i + 2 * j + 3 * k + 4 * m],dp[i][j][k][m]);
					if(k)dp[i][j][k][m] = std::max(dp[i][j][k - 1][m] + a[1 + i + 2 * j + 3 * k + 4 * m],dp[i][j][k][m]);
					if(m)dp[i][j][k][m] = std::max(dp[i][j][k][m - 1] + a[1 + i + 2 * j + 3 * k + 4 * m],dp[i][j][k][m]);
				}
			}
		}
	}
	cout<<dp[b[1]][b[2]][b[3]][b[4]];

	return 0;
}