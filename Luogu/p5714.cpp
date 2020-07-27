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
#include <iomanip>

using std::cin;using std::cout;using std::cerr;using std::endl;

double h,m,k;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>m>>h;

	cout.precision(6);

	k = m / h / h;

	if(k < 18.5){
		cout<<"Underweight";
	}
	else if(k < 24){
		cout<<"Normal";
	}
	else{
		cout<<k<<endl<<"Overweight";
	}


	return 0;
}