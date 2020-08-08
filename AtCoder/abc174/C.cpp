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

int x,ans = 1,val = 7;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>x;

	if(!(x % 2)||!(x%5)) cout<< -1;
	else{
		while(val%x){
			if(ans > x){
				cout<< -1;
				return 0;
			}
			((val *= 10) += 7) %= x;
			ans++;
		}
		// cout<<val;
		cout<<ans;
	}

	return 0;
}