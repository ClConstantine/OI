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
int n,a[mmax + 10],allsum,aver;
int ans = 0;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
		allsum += a[i];
	}

	aver = allsum / n;

	rep(i,1,n){
		a[i] = a[i] - aver;
	}

	rep(i,1,n){
		if(a[i]) ans ++;
		a[i + 1] += a[i];
	}

	cout<<ans;

	return 0;
}