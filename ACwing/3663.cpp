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

#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = a;i >= b;--i)

int n;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;

	rep(i,0,2 * n){
		if(i <= n){
			rep(j,1,n - i){
				cout<<"  ";
			}
			rep(j,0,i){
				cout<<j<<" ";
			}
			per(j,i - 1,0){
				cout<<j<<" ";
			}
			cout<<endl;
		}
		else{
			rep(j,1,i - n){
				cout<<"  ";
			}
			rep(j,0,2 * n - i){
				cout<<j<<" ";
			}
			per(j,2 * n - i - 1,0){
				cout<<j<<' ';
			}
			cout<<endl;
		}
	}



	return 0;
}