#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using std::cin;using std::cout;using std::endl;using std::cerr;

typedef long long ll;

const int mmax = 5000;
int sum[mmax + 10][mmax + 10];
int n,x,y,r,ans,w;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>r;
	
	for(int i = 1;i <= n;++i){
	       cin>>x>>y>>w;
	       sum[x + 1][y + 1] += w;
	}
	
	for(int i = 1;i <= 5001;++i){
	    for(int j = 1;j <= 5001;++j){
	        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
	    }
	}

    for(int i = r;i <= 5001;++i){
	    for(int j = r;j <= 5001;++j){
            ans = std::max(ans , sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
	    }
	}

	
	cout<<ans;
	
	return 0;
}