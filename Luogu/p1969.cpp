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

const int mmax = 1e5;

int h[mmax + 10];
int n,ans = 0,be;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i = 0; i < n;++i){
		cin>>h[i + 1];
	}

	ans += h[1];
	be = h[1];

	for(int i = 2;i <= n;++i){
		if(h[i] > be){
			ans += h[i] - be;
		}
		be = h[i];
	}

	cout<<ans;

	return 0;
}