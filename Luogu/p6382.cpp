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

char s[10];
bool site = 1;
int num;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>(s + 1);

	if(s[1] != 'M'){site = 0;}
	if(s[2] != 'D'){site = 0;}
	if(s[3] != 'A'){site = 0;}

	if(!site){
		for(int i = 1;i <= 5;++i){
			cout<<1<<' ';
		}
		return 0;
	}

	int f = 8;

	while(f){
		if(s[f] >= '0' && s[f] <= '9'){
			num = s[f] - '0';
			break;
		}
		f--;
	}

	if(num==0 || num == 5){
		for(int i = 1;i <= 4;++i){
			cout<<'0'<<' ';
		}
		cout<<1;
		return 0;
	}

	for(int i = 1;i <= 5;++i){
		if(i == num||num == (10 -i)){
			cout<<1<<' ';
		}
		else{
			cout<<0<<' ';
		}
	}

	return 0;
}