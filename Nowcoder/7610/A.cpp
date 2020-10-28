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

int a,b;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d:%d",&a,&b);

	b += 30;
	a += 3;
	if(b > 59){
		b %= 60;
		a++;
	}
	if(a>23){
		a %= 24;
	}
	printf("%02d:%02d",a,b);

	return 0;
}