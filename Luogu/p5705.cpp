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

char c[10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>> c+1;

	int len = strlen(c + 1);

	for(int i = len;i > 0;--i){
		cout << c[i];
	}

	return 0;
}