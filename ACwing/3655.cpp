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

int n,x,T;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;
	while(T--){
		cin>>n>>x;
		if(n <= 2){
			cout<<1<<endl;
		}		
		else cout<<(n - 3) / x + 2<<endl;
	}



	return 0;
}