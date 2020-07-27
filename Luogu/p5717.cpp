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

int a[5];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0;i < 3;++i){
		cin>>a[i + 1];
	}

	std::sort(a + 1, a + 4);

	if(a[1] + a[2] <= a[3]){
		cout<<"Not triangle"<<endl;
		return 0;
	}
	else if(a[1] * a[1] + a[2] * a[2] == a[3] * a[3]){
		cout<<"Right triangle"<<endl;
	}
	else if(a[1] * a[1] + a[2] * a[2] > a[3] * a[3]){
		cout<<"Acute triangle"<<endl;
	}
	else if(a[1] * a[1] + a[2] * a[2] < a[3] * a[3]){
		cout<<"Obtuse triangle"<<endl;
	}

	if(a[1] == a[2] || a[2] == a[3]){
		cout<<"Isosceles triangle"<<endl;
	}
	if(a[1] == a[2] && a[2] == a[3]){
		cout<<"Equilateral triangle"<<endl;
	}

	return 0;
}