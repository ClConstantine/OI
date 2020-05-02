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
typedef unsigned long long ull;

ull n;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	if(n <= 3){
		cout<<0;
		return 0;
	}
	cout<<n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
 
	return 0;
}