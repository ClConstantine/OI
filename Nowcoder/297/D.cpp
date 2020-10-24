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

long long mon[mmax + 10],n,m,sum = 0;

bool cmp(long long a,long long b){
	if(a < b) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>mon[i];
	}

	std::sort(mon + 1,mon + 1 + n,cmp);

	rep(i,1,n){
		if(sum >= m){
			cout<<"YES";
			return 0;
		}
		if(mon[i] > sum + 1){
			cout<<"NO";
			return 0;
		}
		else sum += mon[i];
	}

	if(sum >= m){
		cout<<"YES";
	}

	else cout<<"NO";

	return 0;
}