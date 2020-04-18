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

const int mmax = 1e5;
char ans[mmax + 10],t;
int a,b,num = 0;
int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b;

	if(b == 1 && a == 10){
		cout<<-1;
		return 0;
	}

	for(int i = 1;i <= b;++i){
		
		cin>>t;
		num *= 10;
		if(a == 10 && t == '1' && i == 1){
			cout<<-1;
			return 0;
		}

		else if(a == 1){
			if(t == '0'){
				cout<<-1;
				return 0;
			}
			else {
				if(i == 1){
					ans[i] = '1';
				}
				else{
					ans[i] = '0';
				}
			}
		}

		else if(t == '0'){
			if(i == 1){
				ans[i] = '1';
				num += 1;
			}
			else{
				for(int j = 0;j <= 9;++j){
					if((num + j) % a){
						ans[i] = '0' + j;
						(num += j) %= a;
						break;
					}
				}
			}
		}
		else{
			if(i == 1){
				ans[i] = '0' + a;
			}
			else{
				for(int j = 0;j <= 9;++j){
					if(((num + j) % a) == 0){
						ans[i] = '0' + j;
						(num += j) %= a;
						break;
					}
				}
			}
		}
	}
	for(int i = 1;i<= b;++i){
		cout<<ans[i];
	}

	return 0;
}