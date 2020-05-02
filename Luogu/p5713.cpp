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

	if(5 * n < 3 * n + 11){
		cout<<"Local";
		return 0;
	}

	cout<<"Luogu";

	return 0;
}