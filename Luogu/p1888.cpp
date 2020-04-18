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

int ovo[10];

int gcd(int a,int b){
	return a % b == 0 ? b : gcd(b,a % b); 
}

int main(){

	for(int i = 1;i < 4;i++){
		cin>>ovo[i];
	}

	std::sort(ovo+1,ovo+4);

	int g = gcd(ovo[1],ovo[3]);
	
	cout<<ovo[1]/g<<'/'<<ovo[3]/g;

	return 0;
}