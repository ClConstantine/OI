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

int a,b,c,k;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b>>c>>k;

	while(k--){
		if(a >= b){
			b *= 2;
			continue;
		}
		else if(b >= c){
			c *= 2;
			continue;
		}
		else{
			break;
		}
	}

	if(c > b && b > a){
		cout<<"Yes";
		return 0;
	}

	cout<<"No";

	return 0;
}