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

double n,k,sum1,sum2,num1,num2;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;

	for(int i = k;i <= n;i += k){
		num1++;
		sum1 += i;
	}

	num2 = n - num1;
	sum2 = (1 + n) / 2 * n - sum1;

	printf("%.1f %.1f",sum1 / num1,sum2 / num2);

	return 0;
}