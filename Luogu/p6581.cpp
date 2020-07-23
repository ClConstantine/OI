#include <iostream>
#include <cstdio>
#include <cmath>

using std::cin;using std::cout;using std::endl;using std::cerr;

long long o;
unsigned long long t;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>o;
	t = (unsigned long long)o;
	o>0?cout<<2*t-1:cout<<0;
	
	return 0;
}