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

const int mmax = 5e4;

int n,sum[mmax + 10],ans;

struct cow
{
	int w,s;
}a[mmax + 10];

bool cmp(cow a,cow b){
	if(a.w + a.s > b.w + b.s) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	rep(i,1,n){
		cin>>a[i].w>>a[i].s;
	}

	std::sort(a + 1,a + n + 1,cmp);

	sum[n] = a[n].w;

	per(i,n - 1,1){
		sum[i] = a[i].w + sum[i + 1];
	}

	ans = -0x7f7f7f7f;

	rep(i,1,n){
		ans = std::max(ans,sum[i + 1]-a[i].s);
	}

	cout<<ans;

	return 0;
}