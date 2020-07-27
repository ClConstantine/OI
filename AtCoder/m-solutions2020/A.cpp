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

int x;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>x;

	if(x <= 599){
		cout<<8;
	}
	else if(x <= 799){
		cout<<7;
	}
	else if(x <= 999){
		cout<<6;
	}
	else if(x <= 1199){
		cout<<5;
	}
	else if(x <= 1399){
		cout<<4;
	}
	else if(x <= 1599){
		cout<<3;
	}
	else if(x <= 1799){
		cout<<2;
	}
	else if(x <= 1999){
		cout<<1;
	}

	return 0;
}