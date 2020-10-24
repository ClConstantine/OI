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

const int mmax = 1e3;
int a[mmax + 10],n,ans;
int g[mmax + 10][mmax + 10];
int gcd(int x,int y){
	if(g[x][y]) return g[x][y];
	g[x][y] = (!y ? x: gcd(y,x % y));
	return g[x][y];
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		rep(j,1,n){
			a[gcd(i,j)]++;
		}
	}

	rep(i,1,n){
		rep(j,1,n){
			ans += a[i] * gcd(i,j);
		}
	}

	cout<<ans;


	return 0;
}