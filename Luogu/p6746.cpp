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

int a,b,c,d,ans;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b>>c>>d;

	if(a == 0 && b == 0){
		ans = 0;
	}
	else if(a == 0 || b == 0){
		ans = d;
	}
	else if(a == b){
		ans = std::min(c,2 * d);
	}
	else{
		ans = std::min(c + d,2 * d);
	}

	cout<<ans;


	return 0;
}