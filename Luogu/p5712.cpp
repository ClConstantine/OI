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

	if(n <= 1){
		printf("Today, I ate %d apple.",n);
		return 0;
	}
	printf("Today, I ate %d apples.",n);

	return 0;
}