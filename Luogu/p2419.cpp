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

const int mmax = 100;

int ovo[mmax + 10][mmax + 10];
int n,m,t1,t2,ans = 0;
bool f;

void floyd(){
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				ovo[i][j] |= (ovo[i][k] & ovo[k][j]); 
			}
		}
	}
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i = 0;i < m;++i){
		cin>>t1>>t2;
		ovo[t1][t2] = 1;
	}

	floyd();

	for(int i = 1;i <= n;++i){
		f = 1;
		for(int j = 1;j <= n;++j){
			if(i == j) continue;
			if(!f) break;

			f &= (ovo[i][j] | ovo[j][i]);
		}
		if(f) ans++;
	}

	cout<<ans;

	return 0;
}