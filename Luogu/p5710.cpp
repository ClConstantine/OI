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

int n;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	bool f1 = (n % 2 == 0),f2 = (n <= 12 && n > 4);

	if(f1 && f2) {
		cout<<1<<' ';
	}
	else cout<<0<<' ';

	if(f1 || f2) {
		cout<<1<<' ';
	}
	else cout<<0<<' ';

	if(f1 ^ f2) {
		cout<<1<<' ';
	}
	else cout<<0<<' ';

	if(!f1 && !f2) {
		cout<<1<<' ';
	}
	else cout<<0<<' ';
	return 0;
}