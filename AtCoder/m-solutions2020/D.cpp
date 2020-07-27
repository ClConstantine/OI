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

const int mmax = 80;
long long n,money,stock,price[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>price[i];
	}

	money = 1000;
	stock = 0;

	rep(i,1,n - 1){
		if(price[i + 1] > price[i]){
			stock += money / price[i];
			money = money % price[i];
		}
		else{
			money += price[i] * stock;
			stock = 0;
		}
	}

	cout<<money + stock * price[n];

	return 0;
}