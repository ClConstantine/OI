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

int n,m,u,v,w,ans = 0x7fffffff;
int can[15][15],num[15],dp[1<<12 + 10];
bool f[15][15];

void set0(){
	for(int i = 1;i <= n;++i){
		num[i] = -1;
	}
	memset(dp,0x3f,sizeof(dp));
}

void dfs(int x){
	for(int i = 1;i <= n;++i){
		if( (1 << (i - 1) ) & x){
			for(int j = 1;j <= n;++j){
				if( ( (1<<(j - 1) & x) ) == 0 & f[i][j]){
					if(dp[x | 1<<(j - 1)] > dp[x] + num[i] * can[i][j]){
						int t = num[j];
						num[j] = num[i] + 1;
						dp[x | 1<<(j - 1)] = dp[x] + num[i] * can[i][j];
						dfs(x | 1<<(j - 1));
						num[j] = t;
					}
				}
			}
		}
	}
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i = 1;i <= m;++i) {
		cin>>u>>v>>w;
		if(!f[u][v] || w < can[u][v]){
			can[u][v] = w;
			can[v][u] = w;
			f[u][v] = 1;
			f[v][u] = 1;
		}
	}

	for(int i = 1;i <= n;++i){
		set0();
		num[i] = 1;
		dp[1 << (i - 1)] = 0;
		dfs( 1 << (i - 1) );
		ans = std::min(ans,dp[(1<<n) - 1]);
	}

	cout<<ans;

	return 0;
}