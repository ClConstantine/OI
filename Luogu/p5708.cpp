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

double p,a,b,c;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b>>c;
	p = (a + b + c) / 2;

	printf("%.1f",sqrt(p * (p - a) * (p - b) * (p - c)));

	return 0;
}