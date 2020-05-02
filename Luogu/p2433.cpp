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

int n;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	switch(n){
		case 1:
			cout<<"I love Luogu!";
			break;

		case 2:
			cout<<6<<' '<<4;
			break;

		case 3:
			cout<<3<<endl<<12<<endl<<2;
			break;

		case 4:
			printf("%.3f",500.0 / 3);
			break;

		case 5:
			cout<<480/32;
			break;
		
		case 6:
			cout<<sqrt(9.0*9+6.0*6);
			break;

		case 7:
			cout<<110<<endl<<90<<endl<<0;
			break;

		case 8:
			cout<<10 * 3.141593<<endl<<3.141593 * 25<<endl<<3.141593*4/3*125;
			break;

		case 9:
			cout<<22;
			break;

		case 10:
			cout<<9;
			break;

		case 11:
			cout<<100.0 / 3;
			break;

		case 12:
			cout<<13<<endl<<'R';
			break;

		case 13:
			cout<<(int)pow(3.141593 * 4 / 3 * (64 + 1000),1.0 / 3);
			break;

		case 14:
			cout<<50;
			break;
	}

	return 0;
}