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

const int mmax = 50;

char s[mmax + 10];
int len;
int temp[10];

void qaq(char s,int add){
	if(s == 'R') temp[0] += add;
	else if(s == 'B') temp[1] += add;
	else temp[2] += add;
}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>s;
	len = strlen(s);

	qaq(s[0],1);
	qaq(s[1],1);

	for(int i = 2;i < len;i++){
		qaq(s[i],1);
		if(temp[0] && temp[1] && temp[2]){
			cout<<"Colorful";
			return 0;
		}
		qaq(s[i-2],-1);
	}

	cout<<"Sorry";
	
	return 0;
}