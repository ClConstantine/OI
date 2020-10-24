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

const int mmax = 20;

int st1[mmax + 10],st2[mmax + 10],h1 = 0,h2 = 0,n,cnt = 0;

void dfs(int x){
	if(cnt >= 20) return;
	if(x == n + 1){
		cnt++;
		rep(i,1,h2){
			cout<<st2[i];
		}
		per(i,h1,1){
			cout<<st1[i];
		}
		cout<<endl;
		return;
	}

	if(h1){
		st2[++h2] = st1[h1--];
		dfs(x);
		st1[++h1] = st2[h2--];	
	}

	st1[++h1] = x;
	dfs(x + 1);
	h1--;
	return ;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	dfs(1);


	return 0;
}