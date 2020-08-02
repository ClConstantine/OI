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

long long n,x,y,ans,d;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>d;

	rep(i,1,n){
		cin>>x>>y;
		if(x * x + y * y <= d * d){
			ans++;
		}
	}
	cout<<ans;

	return 0;
}
