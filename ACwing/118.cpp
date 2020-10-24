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

const int mmax = 3000;
int n;
bool s[mmax][mmax];

int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b & 1){
			ans *= a;
		}
		b >>= 1;
		a *= a;
	}
	return ans;
}

void dfs(int x,int y,int n){
	if(n == 1) {
		s[x][y] = 1;
		return ;
	}

	int len = qp(3,n - 2);

	dfs(x,y,n - 1);
	dfs(x,y + 2 * len,n - 1);
	dfs(x + len,y + len,n - 1);
	dfs(x + 2 * len,y,n - 1);
	dfs(x + 2 * len,y + 2 * len ,n - 1);
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while((cin>>n) && n != -1){
		memset(s,0,sizeof(s));
		dfs(1,1,n);
		
		int t = qp(3,n - 1);

		rep(i,1,t){
			rep(j,1,t){
				if(s[i][j]) cout<<'X';
				else cout<<' ';
			}
			cout<<endl;
		}
		cout<<'-'<<endl;
	}



	return 0;
}