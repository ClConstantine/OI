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
double t;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>t>>n;

	printf("%.3f\n%d",t / n,2 * n);
	return 0;
}