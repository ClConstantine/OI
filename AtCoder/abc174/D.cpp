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

const int mmax = 2e5;
int n,l,ans = 0;
char t[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	cin>>t;

	rep(i,0,n - 1){
		if(t[i] == 'R') {l++;}
	}

	rep(i,l,n - 1){
		if(t[i] == 'R') ans++;
	}
	cout<<ans;
	

	return 0;
}