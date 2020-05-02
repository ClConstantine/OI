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

long long T,h,x,y;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>h>>x>>y;
		if(y == 0){
			cout<<"No"<<endl;
		}
		else if(x == 0){
			cout<<"Yes"<<endl;
		}
		else if(y >= h){
			cout<<"Yes"<<endl;
		}
		else if(x >= h){
			cout<<"No"<<endl;
		}
		else{
			long long a = h / x, c = h - a * x;
			if(c){
				if( (a+1) * y >=c){
					cout<<"Yes"<<endl;
				}
				else{
					cout<<"No"<<endl;
				}
			}
			else{
				if(a * y >= x){
					cout<<"Yes"<<endl;
				}
				else{
					cout<<"No"<<endl;
				}
			}
		}
	}

	return 0;
}