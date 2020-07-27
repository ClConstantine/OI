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

int y,r;

int ovo[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>y>>r;

	if(r == 2){
		if(y % 400 == 0){
			cout<<29;
		}
		else if(y % 100 == 0){
			cout<<28;
		}
		else if(y % 4 == 0){
			cout<<29;
		}
		else cout<<28;
	}
	else cout<<ovo[r];



	return 0;
}