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

int ovo[5];
char c;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 1;i < 4;++i){
		cin>>ovo[i];
	}

	std::sort(ovo + 1,ovo + 4);

	for(int i = 1;i <= 3;i++){
		cin>>c;
		cout<<ovo[c - 'A' + 1]<<' ';
	}

	return 0;
}