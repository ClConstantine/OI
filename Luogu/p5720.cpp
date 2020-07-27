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

double l;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>l;

	if(l == 1){
		cout<<1;
		return 0;
	}

	cout<<std::ceil(log2(l));

	return 0;
}